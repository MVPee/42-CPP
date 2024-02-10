#ifndef HARL_CPP
# define HARL_CPP

#include <iostream>
#include <string>

class Harl {
    private:
        void debug();
        void info();
        void warning();
        void error();
        int getLevel(std::string level);
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif