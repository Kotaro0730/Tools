#include <iostream>
#include <string>

#include "fileOperator.hpp"

#include "directory.hpp"

int main(void)
{
  FILE_OPERATOR fOperator("C:\\workspace");

  fOperator.distribute_based_on_label(".txt");

  return 0;
}
