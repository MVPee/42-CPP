#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"

class Bureaucrat;

class AForm {
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
	public:

		AForm();
		AForm(const std::string name, int signGrade, int executeGrade);
		AForm( AForm const & src );
		virtual ~AForm();

		AForm& operator=( AForm const & rhs );

		virtual void	execute(Bureaucrat const & executor) const = 0;
		void checkExecution(const Bureaucrat &executor) const;

		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

        class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
		public:
			const char *what() const throw();
		};

};

std::ostream& operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AFORM_H */