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

    return files;
}

string FileManager::getFileDirectory(const string& file) {
    // dir: linux '/',  windows '\'
    auto idx = file.rfind('\\');

    if (idx == std::string::npos)
        idx = file.rfind('/');

    return file.substr(0, idx);
}
string FileManager::getFileName(const string& file) {
    auto dirIdx = file.rfind('\\');
    auto extIdx = file.rfind('.');

    if (dirIdx == std::string::npos)
        dirIdx = file.rfind('/');

    return file.substr(dirIdx + 1, extIdx - dirIdx - 1);
}
string FileManager::getFileExtension(const string& file) { return file.substr(file.rfind('.') + 1); }
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