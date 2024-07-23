#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define ROBOTOMY_REQUEST_FORM "robotomy request"
# define PRESIDENTIAL_PARDON_FORM "presidential pardon"
# define SHRUBBERY_CREATION_FORM "shrubbery creation"

typedef enum {
	ROBOTOMY_FORM = 0,
	PRESIDENTIAL_FORM = 1,
	SHRUBBERY_FORM = 2
}	t_form;

class Intern
{
	private:

	public:

		Intern();
		Intern(Intern const &src);
		~Intern();
		Intern &operator=(Intern const &rhs);

		AForm *makeForm(std::string name, std::string target);

		class FormDoesNotExist : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif /* ********************************************************** INTERN_H */