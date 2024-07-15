#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator=(Bureaucrat const& rhs);

        std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();

        void signForm(Form &form);

        class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

        class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);

#endif