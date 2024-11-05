#include "managers/fileManager.hpp"

#include <fstream>
#include <iostream>
using std::ifstream;
using std::cout;
using std::endl;

static unsigned long long getFileSize(ifstream& reader) {
    unsigned long long fileSize{ };

    reader.seekg(0, std::ios_base::end);
    fileSize = static_cast<unsigned int>(reader.tellg());
    reader.seekg(0, std::ios_base::beg);

    return fileSize;
}

FileManager::FileManager() { }
FileManager::~FileManager() noexcept { }

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

        reader.close();
    }
    else
        cout << "[ERROR]: FAILED TO OPEN FILE \"" << file << '\"' << endl;

    return buf;
}