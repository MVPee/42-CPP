#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
	public:

		Form();
		Form(const std::string name, int signGrade, int executeGrade);
		Form( Form const & src );
		~Form();

		Form& operator=( Form const & rhs );

		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat &bureaucrat);

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

std::ostream& operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */