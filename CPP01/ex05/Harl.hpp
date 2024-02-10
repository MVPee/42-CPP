#ifndef HARL_CPP
# define HARL_CPP

#include <iostream>
#include <string>

class Harl;

struct LevelFunction {
    const char* level;
    void (Harl::*func)();
};

class Harl {
    private:
        LevelFunction levelFunctions[4];

        void debug();
        void info();
        void warning();
        void error();

    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif