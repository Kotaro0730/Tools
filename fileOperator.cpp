#include "fileOperator.hpp"

#include "directory.hpp"
#include "common.hpp"
#include "macros.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>

// static member
std::string const FILE_OPERATOR::m_listname = "list.csv";

// public
FILE_OPERATOR::FILE_OPERATOR()
{
  std::cout << "Input directory name >> ";
  std::cin >> m_dirname;
}

FILE_OPERATOR::FILE_OPERATOR(const std::string& dirname)
  : m_dirname(dirname)
{
  ;
}

FILE_OPERATOR::~FILE_OPERATOR()
{
  ;
}

void FILE_OPERATOR::distribute_based_on_label(const std::string& ext)
{
  chdir(m_dirname);

  acquire_filename_list(ext);

  std::ifstream ifs(m_listname.c_str());

  const std::string dst_dir_name = "distributed";
  mkdir(dst_dir_name);

  std::string src_file_path;
  while (std::getline(ifs, src_file_path)) {
    std::string filename = src_file_path.substr(src_file_path.find_last_of("\\") + 1);
    std::vector<std::string> strs = split(filename, '_');
    int label = name_to_label(strs[0]);
    chdir(dst_dir_name);
    std::string label_str = i_to_str(label);
    mkdir(label_str);
    std::string dst_file_path = label_str + "\\" + filename;
    copy_file(src_file_path, dst_file_path);
    chdir(TO_UP_DIR);
  }

  ifs.close();

  delete_filename_list();
}

// private
void FILE_OPERATOR::acquire_filename_list(const std::string& ext)
{
  const std::string batname = "do.bat";
  std::ofstream ofs(batname.c_str());
  ofs << "dir /s /b *" << ext << " > " << m_listname;
  ofs.close();

  system(batname.c_str());
  remove(batname.c_str());
}

void FILE_OPERATOR::delete_filename_list()
{
  remove(m_listname.c_str());
}
