#include "common.hpp"
#include "types.hpp"
#include "macros.hpp"

#include <sstream>

std::vector<std::string> split(const std::string& src, char dlm)
{
  std::vector<std::string> strs;

  std::stringstream sstr(src);

  std::string str;
  while (std::getline(sstr, str, dlm)) {
    if (!str.empty()) {
      strs.push_back(str);
    }
  }

  return strs;
}

static NAME_LABEL s_name_label[] = {
  {"label1", 1},
  {"label2", 2},
  {"label3", 3},
  {"label4", 4},
  {"label5", 5}
};

int name_to_label(const std::string& name)
{
  for (int i = 0; i < ARRAY_SIZE(s_name_label); i++) {
    if (s_name_label[i].name == name) {
      return s_name_label[i].label;
    }
  }

  return -1;
}

std::string i_to_str(int val)
{
  std::stringstream sstr;
  sstr << val;
  return sstr.str();
}
