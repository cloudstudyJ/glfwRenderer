#include "managers/fileManager.hpp"

#include <fstream>
#include <iostream>
#include <filesystem>
using std::ifstream;
using std::cout;
using std::endl;

namespace fs = std::filesystem;

static unsigned long long getFileSize(ifstream& reader) {
    unsigned long long fileSize{ };

    reader.seekg(0, std::ios_base::end);
    fileSize = static_cast<unsigned int>(reader.tellg());
    reader.seekg(0, std::ios_base::beg);

    return fileSize;
}

deque<string> FileManager::getFileList(const string& dir) {
    deque<string> files;

    if (fs::is_directory(dir)) {
        for (const auto& entry: fs::recursive_directory_iterator(dir)) {
            if (fs::is_regular_file(entry.path()))
                files.push_back(entry.path().string());
        }
    }
    else
        cout << "[ERROR]: \"" << dir << "\" IS NOT A DIRECTORY" << endl;

    return files;
}

string FileManager::getFileDirectory(const string& file) {
    if (!fs::exists(file)) {
        cout << "[ERROR]: \"" << file << "\" NOT FOUND" << endl;

        return {};
    }

    return file.substr(0, file.find_last_of("\\/"));
}
string FileManager::getFileName(const string& file) {
    if (!fs::exists(file)) {
        cout << "[ERROR]: \"" << file << "\" NOT FOUND" << endl;

        return {};
    }

    auto dirIdx = file.find_last_of("\\/") + 1;
    auto extIdx = file.rfind('.');

    return file.substr((fs::is_directory(file)) ? dirIdx : dirIdx, extIdx - dirIdx);
}
string FileManager::getFileExtension(const string& file) {
    if (!fs::exists(file)) {
        cout << "[ERROR]: \"" << file << "\" NOT FOUND" << endl;

        return {};
    }
    else if (fs::is_directory(file))
        return "[DIRECTORY]";

    auto dirIdx = file.find_last_of("\\/") + 1;
    auto extIdx = file.find('.', dirIdx);

    return (extIdx == string::npos) ? "[NONE]" : file.substr(extIdx + 1);
}
unsigned long long FileManager::getFileSize(const string& file) {
    ifstream reader(file, std::ios_base::binary);

    return ::getFileSize(reader);
}

string FileManager::readFile(const string& file) {
    ifstream reader(file, std::ios_base::binary);
    string buf;

    if (reader) {
        auto fileSize = ::getFileSize(reader);

        buf.resize(fileSize);
        reader.read(&buf[0], fileSize);
    }
    else
        cout << "[ERROR]: FAILED TO OPEN FILE \"" << file << '\"' << endl;

    return buf;
}