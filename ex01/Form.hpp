#ifndef _FORM_
# define _FORM_

# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
private:
    const std::string	_name;
    bool             	_is_signed;
	const int			_requiredToSign;
	const int			_requiredToExecute;
public:
    Form();
    Form(const std::string &name, const int required_to_sign, const int required_to_execute);
    Form(const Form &copy);
    Form& operator=(const Form &copy);
    ~Form();

    //getters
    std::string getName() const;
	bool		isSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;
	
	//member functions
	void	beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

# endif