#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    std::cout << "___________________Subject test start___________________" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << "___________________Subject test end___________________" << std::endl << std::endl;

    std::cout << "___________________Subject test2 start___________________" << std::endl << std::endl;

    Animal* pets[10];

    for (int i = 0; i < 5; i++)
    {
        pets[i] = new Dog();
        std::cout << std::endl;
    }
    for (int i = 5; i < 10; i++)
    {
        pets[i] = new Cat();
        std::cout << std::endl;
    }

    std::cout << "___________________Subject test2 delete___________________" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        delete pets[i];
        std::cout << std::endl;
    }
    
    std::cout << "___________________Subject test2 end___________________" << std::endl << std::endl;

    std::cout << "___________________Subject test3 deepcopy start___________________" << std::endl << std::endl;

    Cat* cat1 = new Cat();
    cat1->setBrainIdeas("smartCatIdea");
    std::cout << std::endl;

    cat1->showBrainIdeas(); //should show 100 smartCatIdea

    Cat* cat2 = new Cat(*cat1);
    cat2->showBrainIdeas(); //should show 100 smartCatIdea
    cat2->setBrainIdeas("cleverCatIdea");
    std::cout << std::endl;

    cat2->showBrainIdeas(); //should show 100 cleverCatIdea

    delete cat1;

    cat2->showBrainIdeas(); //should show 100 cleverCatIdea
    delete cat2;

    std::cout << "___________________Subject test3 deepcopy end___________________" << std::endl << std::endl;

    std::cout << "___________________Subject test4 deepcopy start___________________" << std::endl << std::endl;

    Dog* dog1 = new Dog();
    dog1->setBrainIdeas("superDogIdea");
    std::cout << std::endl;

    dog1->showBrainIdeas(); //should show 100 superDogIdea

    Dog* dog2 = new Dog(*dog1);
    dog2->showBrainIdeas(); //should show 100 superDogIdea
    dog2->setBrainIdeas("prettyDogIdea");
    std::cout << std::endl;

    dog2->showBrainIdeas(); //should show 100 prettyDogIdea

    delete dog1;

    dog2->showBrainIdeas(); //should show 100 prettyDogIdea
    delete dog2;

    std::cout << "___________________Subject test4 deepcopy end___________________" << std::endl << std::endl;

    return (0);
}