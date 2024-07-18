# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>

Base* generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception& E) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::exception& E) {
            (void)dynamic_cast<C&>(p);
            std::cout << "C" << std::endl;
        }
    }
}

int main() {
    std::cout << "PART1 random" << std::endl;
    {
        Base* base = generate();
        identify(base);
        identify(*base);
        delete base;
    }
    std::cout << std::endl;

    std::cout << "PART2" << std::endl;
    {
        Base* base = new A();
        identify(base);
        identify(*base);
        delete base;
    }
    std::cout << std::endl;

    std::cout << "PART3" << std::endl;
    {
        Base* base = new B();
        identify(base);
        identify(*base);
        delete base;
    }
    std::cout << std::endl;

    std::cout << "PART4" << std::endl;
    {
        Base* base = new C();
        identify(base);
        identify(*base);
        delete base;
    }
    std::cout << std::endl;

    return (0);
}