#pragma once

#include <string>
using std::string;

class FileManager {
    FileManager(const FileManager&) = delete;
    FileManager(FileManager&&) noexcept = delete;

    FileManager& operator=(const FileManager&) = delete;
    FileManager& operator=(FileManager&&) noexcept = delete;

    public:
        FileManager();
        ~FileManager() noexcept;

        static string getFileDirectory(const string&);
        static string getFileName(const string&);
        static string getFileExtension(const string&);
        static unsigned long long getFileSize(const string&);

        static string readFile(const string&);
};