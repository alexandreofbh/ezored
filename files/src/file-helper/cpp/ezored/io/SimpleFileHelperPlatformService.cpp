#include "SimpleFileHelperPlatformService.hpp"

#include "boost/filesystem.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace ezored
{
namespace io
{

namespace fs = boost::filesystem;

bool SimpleFileHelperPlatformService::createFile(const std::string &path)
{
    try
    {
        fs::path filePath{path};
        fs::create_directories(filePath.parent_path());

        std::ofstream ofs(fs::absolute(filePath).generic_string(), std::ios::out);
        ofs.close();

        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::createFileWithStringContent(const std::string &path, const std::string &content)
{
    try
    {
        fs::path filePath{path};
        fs::create_directories(filePath.parent_path());

        std::ofstream stream(fs::absolute(filePath).generic_string(), std::ios::out | std::ios::binary | std::ios::trunc);
        stream << content;
        stream.close();

        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::createFileWithBinaryContent(const std::string &path, const std::vector<uint8_t> &content)
{
    try
    {
        fs::path filePath{path};
        fs::create_directories(filePath.parent_path());

        std::ofstream stream(fs::absolute(filePath).generic_string(), std::ios::in | std::ios::binary);

        for (auto &data : content)
        {
            stream << data;
        }

        stream.close();

        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::createDir(const std::string &path)
{
    try
    {
        fs::path dirPath{path};
        return fs::create_directories(dirPath);
    }
    catch (const std::exception &)
    {
        return false;
    }
}

std::vector<std::string> SimpleFileHelperPlatformService::listFiles(const std::string &path)
{
    try
    {
        fs::path dirPath{path};
        std::vector<std::string> files;
        fs::directory_iterator endItr;

        for (fs::directory_iterator itr(dirPath); itr != endItr; ++itr)
        {
            if (is_regular_file(itr->path()))
            {
                files.push_back(itr->path().string());
            }
        }

        return files;
    }
    catch (const std::exception &)
    {
        return {};
    }
}

std::string SimpleFileHelperPlatformService::getExtension(const std::string &path)
{
    try
    {
        return fs::extension(path);
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getFilename(const std::string &path)
{
    try
    {
        return fs::path(path).filename().c_str();
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getBasename(const std::string &path)
{
    try
    {
        return fs::path(path).filename().c_str();
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getFilenameFromUrl(const std::string &url)
{
    try
    {
        return fs::path(url).filename().c_str();
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getBasenameFromUrl(const std::string &url)
{
    try
    {
        return fs::path(url).filename().c_str();
    }
    catch (const std::exception &)
    {
        return "";
    }
}

bool SimpleFileHelperPlatformService::removeFile(const std::string &path)
{
    try
    {
        fs::remove(path);
        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::removeDir(const std::string &path)
{
    try
    {
        fs::remove_all(path);
        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::isDir(const std::string &path)
{
    try
    {
        fs::path dirPath{path};
        return fs::is_directory(dirPath);
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::isFile(const std::string &path)
{
    try
    {
        fs::path filePath{path};
        return fs::is_regular_file(filePath);
    }
    catch (const std::exception &)
    {
        return false;
    }
}

int64_t SimpleFileHelperPlatformService::getFileSize(const std::string &path)
{
    try
    {
        fs::path filePath{path};
        return static_cast<int64_t>(fs::file_size(filePath));
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::copyFile(const std::string &from, const std::string &to)
{
    try
    {
        fs::copy_file(from, to, fs::copy_option::overwrite_if_exists);
        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::moveFile(const std::string &from, const std::string &to)
{
    try
    {
        fs::rename(from, to);
        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

std::string SimpleFileHelperPlatformService::join(const std::string &first, const std::string &second)
{
    try
    {
        fs::path firstPath(first);
        fs::path secondPath(second);

        return (firstPath / secondPath).c_str();
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getFileContentAsString(const std::string &path)
{
    try
    {
        std::string data;
        fs::ifstream stream(path);
        stream >> data;
        stream.close();

        return data;
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::vector<uint8_t> SimpleFileHelperPlatformService::getFileContentAsBinary(const std::string &path)
{
    try
    {
        std::ifstream stream(path, std::ios::in | std::ios::binary);
        std::vector<uint8_t> data((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
        return data;
    }
    catch (const std::exception &)
    {
        return {};
    }
}

std::string SimpleFileHelperPlatformService::getHomeDir()
{
    auto homeDirectory = "";

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    homeDirectory = getenv("HOMEDRIVE") + getenv("HOMEPATH");
#elif defined(unix) || defined(__linux__) || defined(__APPLE__) || defined(_POSIX_VERSION)
    homeDirectory = getenv("HOME");
#else
    throw std::exception("[SimpleFileHelperPlatformService : getHomeDir] Unknown platform");
#endif

    return homeDirectory;
}

} // namespace io
} // namespace ezored
