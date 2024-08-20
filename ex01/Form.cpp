#include "Form.hpp"

//default constructor
Form::Form()  : _name("Unknown"), _requiredToSign(150), _requiredToExecute(150), _is_signed(false)
{
	std::cout << "Default Form constuctor called: name initialized to " << this->_name << " with grade required to sign set to " << this->_requiredToSign << " and to execute " << this->_requiredToExecute << std::endl;   
}
//param constructor
Form::Form(const std::string &name, const int required_to_sign, const int required_to_execute) : _name(name), _requiredToSign(required_to_sign), _requiredToExecute(required_to_execute), _is_signed(false)
{
	if (_requiredToSign > 150 || _requiredToExecute > 150)
		throw Form::GradeTooLowException();
	else if (_requiredToSign < 1 || _requiredToExecute < 1)
		throw Form::GradeTooHighException();
	std::cout << "Parameter Form constuctor called: name initialized to " << this->_name << " with grade required to sign set to " << this->_requiredToSign << " and to execute " << this->_requiredToExecute << std::endl;   
}

//copy constructor
Form::Form(const Form &copy) : _name(copy._name), _requiredToSign(copy._requiredToSign), _requiredToExecute(copy._requiredToExecute), _is_signed(false)
{
	*this = copy;
	std::cout << "Copy Form constructor called" << std::endl;
}

// = operator overload
Form& Form::operator=(const Form &copy)
{
	if (this != &copy)
		this->_is_signed = copy._is_signed;
	return (*this);
}

// Destructor
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

//getters
std::string Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_is_signed);
}

int	Form::getGradeToSign() const
{
	return (_requiredToSign);
}

int	Form::getGradeToExecute() const
{
	return (_requiredToExecute);
}

//member function
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredToSign)
		throw Form::GradeTooLowException();
	else
		_is_signed = true;
}

//exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

//assignement overoad
std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	std::cout << obj.getName() << ": status: " << obj.isSigned() << "." << std::endl;
	std::cout << "Required grade to sign: " <<  obj.getGradeToSign() << std::endl;
	std::cout << "Required grade to execute: " <<  obj.getGradeToExecute() << std::endl;
	return (out);
}
