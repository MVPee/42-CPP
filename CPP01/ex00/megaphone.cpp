#include <iostream>
#include <cstring>

int main(int ac, char **av) {
  int i = 0, j;
  
  if (ac == 1)
    return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);

  while(++i < ac) {
    j = -1;
    while(++j < (int)strlen(av[i])) {
      std::cout << (char)toupper(av[i][j]);
    }
    if (i < ac -1)
      std::cout << " ";
  }

  return (std::cout << "" << std::endl, 0);
}