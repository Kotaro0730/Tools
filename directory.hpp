#pragma once

#include <string>

void chdir(const std::string& dir);
void mkdir(const std::string& dir);
void copy_file(const std::string& src, const std::string& dst);
