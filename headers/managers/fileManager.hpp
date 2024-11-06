#pragma once

#include <string>
#include <deque>
using std::string;
using std::deque;

class FileManager {
    FileManager() = delete;
    FileManager(const FileManager&) = delete;
    FileManager(FileManager&&) noexcept = delete;
    ~FileManager() noexcept = delete;

    FileManager& operator=(const FileManager&) = delete;
    FileManager& operator=(FileManager&&) noexcept = delete;

    public:
        static deque<string> getFileList(const string&);

        static string getFileDirectory(const string&);
        static string getFileName(const string&);
        static string getFileExtension(const string&);
        static unsigned long long getFileSize(const string&);

        static string readFile(const string&);
};