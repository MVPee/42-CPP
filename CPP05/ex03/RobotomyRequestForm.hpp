#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private:
		const std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);

		void	execute(Bureaucrat const &bureaucrat) const;
};

std::ostream& operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ******************************************* ROBOTOMYREQUESTFORM */