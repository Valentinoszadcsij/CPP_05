#ifndef _BUREAUCRAT_
# define _BUREAUCRAT_

# include <iostream>
# include <exception>

class Bureaucrat
{
private:
    const std::string _name;
    int              _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat& operator=(const Bureaucrat &copy);
    ~Bureaucrat();

    //getters
    std::string getName() const;
    int         getGrade() const;
    //member functions
    void    increaseGrade(int value = 1);
    void    decreaseGrade(int value = 1);
    void	signForm();

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

# endif