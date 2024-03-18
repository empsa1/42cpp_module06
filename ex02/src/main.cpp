#include <iostream>
#include <cstdlib>
#include "../includes/Utils.hpp"
#include <ctime>

class Base { public: virtual ~Base() {std::cout << DESTRUCTOR << std::endl;} };
class A : public Base {};
class B : public Base {};
class C : public Base {};
class D : public Base {};

Base *generate()
{
    std::srand(std::time(0));
    int rand = std::rand() % 4;
    //std::cout <<  rand << std::endl;
    if (rand == 0)
        return new A;
    if (rand == 1)
        return new B;
    else if (rand == 2)
        return new C;
    else
        return new D;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << RED << "Unknown" << RESET << std::endl;
}

void identify(Base & p)
{
    try
    {
        A& a = dynamic_cast<A&> (p);
        std::cout << "A\n";
        (void)a;
    }
    catch (const std::exception& e)
    {
        try
        {
            B& b = dynamic_cast<B&> (p);
            std::cout << "B\n";
            (void)b;
        }
        catch (const std::exception& e)
        {
            try
                {
                    C& c = dynamic_cast<C&> (p);
                    std::cout << "C\n";
                    (void)c;
                }
            catch (const std::exception& e)
            {
                std::cout << RED  << e.what() << RESET << std::endl;
            }
        }
    }
}

int main()
{
    Base *a = generate();
    Base &b = *a;
    identify(a);
    identify(b);
    return 0;
}