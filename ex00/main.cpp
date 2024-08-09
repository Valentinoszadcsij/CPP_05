#include <unistd.h> //for sleep
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 50);
        std::cout << "Created bureaucrat " << bob.getName() << " with grade " << bob.getGrade() << std::endl;

        bob.increaseGrade();
        std::cout << bob.getName() << "'s grade after increment: " << bob.getGrade() << std::endl;

        bob.decreaseGrade();
        std::cout << bob.getName() << "'s grade after decrement: " << bob.getGrade() << std::endl;
        std::cout << bob;
        usleep(50000);
        
        //Test invalid grade (too high)
        try
        {
            Bureaucrat alice("Alice", 0);
        }
        catch (const Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Error creating Alice: " << e.what() << std::endl;
        }
        usleep(50000);

        //Test invalid grade (too low)
        try
        {
            Bureaucrat charlie("Charlie", 151);
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Error creating Charlie: " << e.what() << std::endl;
        }
        usleep(50000);

        // Test incrementing too high
        try
        {
            Bureaucrat dave("Dave", 1);
            dave.increaseGrade();
        }
        catch (const Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Error incrementing Dave's grade: " << e.what() << std::endl;
        }
        usleep(50000);
        
        // Test decrementing too low
        try
        {
            Bureaucrat eve("Eve", 150);
            eve.decreaseGrade();
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Error decrementing Eve's grade: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Quite an expected error: " << e.what() << std::endl;
    }
    return 0;
}
