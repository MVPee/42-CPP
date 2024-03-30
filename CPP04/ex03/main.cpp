# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

int main(void) {
    AMateria* test = new Cure();
    std::cout << test->getType() << std::endl;
    return (0);
}