#include "directory.hpp"

#include <Windows.h>
#include <direct.h>

void chdir(const std::string& dir)
{
  _chdir(dir.c_str());
}

void mkdir(const std::string& dir)
{
  _mkdir(dir.c_str());
}

void copy_file(const std::string& src, const std::string& dst)
{
  CopyFile(src.c_str(), dst.c_str(), false);
}
