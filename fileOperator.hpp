#pragma once

#include <string>

class FILE_OPERATOR
{
public:
  FILE_OPERATOR();
  FILE_OPERATOR(const std::string& dirname);
  ~FILE_OPERATOR();
  void distribute_based_on_label(const std::string& ext);
private:
  void acquire_filename_list(const std::string& ext);
  void delete_filename_list();

  std::string m_dirname;

  static const std::string m_listname;
};
