#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "_____________________subject test begin______________________" << std::endl << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    std::cout << "_____________________wrong animal & wrong cat______________________" << std::endl << std::endl;
    const WrongAnimal* wrongAni = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongAni->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongAni->makeSound();
    wrongCat->makeSound(); //this should not call WrongCat makesound function


    std::cout << "_____________________subject test end______________________" << std::endl << std::endl;

    std::cout << "_____________________copy test begin(no polymorphism)______________________" << std::endl << std::endl;  
    Animal* meta_copy = new Animal(*meta);
    Animal* cool_animal = new Animal("coolAnimal");
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    Dog* dog_copy = new Dog(*dog);
    Cat* cat_copy = new Cat(*cat);

    std::cout << std::endl;

    meta_copy->makeSound();
    cool_animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    dog_copy->makeSound();
    cat_copy->makeSound();

    std::cout << "_____________________copy test end(no polymorphism)______________________" << std::endl << std::endl;


    std::cout << "_____________________subject destructor______________________" << std::endl << std::endl;

    delete i;
    delete j;
    delete meta;
    delete wrongAni;
    delete wrongCat;

    std::cout << "_____________________copy test destructor______________________" << std::endl << std::endl;

    delete meta_copy;
    delete cool_animal;
    delete dog;
    delete cat;
    delete dog_copy;
    delete cat_copy;

    return (0);
}