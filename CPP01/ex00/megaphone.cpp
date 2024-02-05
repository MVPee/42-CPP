#include <iostream>
#include <cstring>

int main(int ac, char **av) {
  if (ac == 1)
    return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);

  for (int i = 1; i < ac; i++) {
    for (int j = 0; av[i][j] != '\0'; j++) {
      std::cout << (char)toupper(av[i][j]);
    }
    if (i < ac -1)
      std::cout << " ";
  }

  return (std::cout << "" << std::endl, 0);
}