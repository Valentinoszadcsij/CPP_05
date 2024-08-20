#include <unistd.h> //for sleep
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    try
    {
        Bureaucrat bob("Bob", 50);
        usleep(50000);

        //Test form with proper grades
        try
        {
            Form form404("Form 404", 40, 40);
            std::cout << form404;
            
            //Test signing form
            try
            {
                bob.signForm(form404);
            }
            catch(const Bureaucrat::GradeTooLowException &e)
            {
                std::cerr << e.what() << '\n';
            }
            try
            {
                bob.increaseGrade(10);
                bob.signForm(form404);
            }
            catch(const Form::GradeTooLowException &e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
        catch (const Form::GradeTooHighException &e)
        {
            std::cerr << "Error creating form: " << e.what() << std::endl;
        }
        catch (const Form::GradeTooLowException &e)
        {
            std::cerr << "Error creating form: " << e.what() << std::endl;
        }
        usleep(50000);

        //Test invalid grade (too low)
        try
        {
            Form Form303("Form 303", 151, 100);
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Error creating form: " << e.what() << std::endl;
        }
        usleep(50000);

        //Test invalid grade (too high)
        try
        {
            Form Form202("Form 202", 0, 100);
        }
        catch (const Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Error creating form: " << e.what() << std::endl;
        }
        usleep(50000);

        
        
    }
    catch (const std::exception &e)
    {
        std::cerr << "Quite an expected error: " << e.what() << std::endl;
    }
    return 0;
}
