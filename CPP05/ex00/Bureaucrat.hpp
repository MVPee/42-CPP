#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"

class Bureaucrat
{
    private:
        const std::string& name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat& operator=(Bureaucrat const& rhs);

        const std::string& getName() const;
};

#endif