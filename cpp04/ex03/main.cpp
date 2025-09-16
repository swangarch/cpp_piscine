#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int     main(void)
{
    std::cout << "__________________SUBJECT TEST START__________________" << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    std::cout << "__________________SUBJECT TEST END__________________" << std::endl << std::endl;



    // std::cout << "__________________DEEPCOPY TEST START__________________" << std::endl;

    // IMateriaSource* src = new MateriaSource();
    
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");
    // AMateria* tmp;

    // IMateriaSource* src2 = new MateriaSource(*dynamic_cast<MateriaSource*>(src));
    // IMateriaSource* src3 = new MateriaSource();

    // *dynamic_cast<MateriaSource*>(src3) = *dynamic_cast<MateriaSource*>(src2);

    // delete src;
    // delete src2;

    // tmp = src3->createMateria("ice");
    // me->equip(tmp);
    // tmp = src3->createMateria("cure");
    // me->equip(tmp);

    // ICharacter* bob = new Character("bob");
    // ICharacter* copy_me = new Character(*dynamic_cast<Character*>(me));
    
    // delete (me);

    // dynamic_cast<Character*>(copy_me)->setName("copy_me");
    // copy_me->use(0, *bob);
    // copy_me->use(1, *bob);

    // delete bob;
    // delete copy_me;
    // delete src3;

    // std::cout << "__________________DEEPCOPY TEST END__________________" << std::endl << std::endl;



    // std::cout << "__________________FUNCTIONAL TEST START__________________" << std::endl;

    // IMateriaSource* src = new MateriaSource();
    
    // src->learnMateria(new Ice());
    // ICharacter* me = new Character("me");
    // ICharacter* bob = new Character("bob");

    // AMateria* tmp;

    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure"); //should do nothing beacause cure has not been learned
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure"); //should do nothing beacause cure has not been learned
    // me->equip(tmp);

    // me->use(0, *bob); //should call ice
    // me->use(1, *bob); //should call ice
    // me->use(2, *bob); //should do nothing because only 2 slots are filled

    // me->unequip(0);
    // me->unequip(1);
    // me->unequip(2); //should do nothing because slot 2 is empty

    // //___after this step, unequipped should have 2 ice___ inventory shoule be empty

    // src->learnMateria(new Cure());

    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice"); //should do nothing because slots are full

    // me->equip(tmp);
    // delete(tmp);  //need to be deleted here because it hasn't been add to inventory slot

    // me->use(0, *bob); //should call ice
    // me->use(1, *bob); //should call cure
    // me->use(2, *bob); //should call ice
    // me->use(3, *bob); //should call cure
    // me->use(4, *bob); //should print error because only 4 slots

    // me->unequip(0);
    // me->unequip(1);
    // me->unequip(2);

    // //___after this step, unequipped should have ice ice ice cure ice then maybe some NULL___, inventory has NULL NULL NULL cure

    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // me->use(0, *bob); //should call cure
    // me->use(1, *bob); //should do nothing
    // me->use(2, *bob); //should do nothing
    // me->use(3, *bob); //should call cure

    // //___after this step, unequipped should have ice ice ice cure ice then maybe some NULL___, inventory has cure NULL NULL cure
    // //the result will be ice ice | ice cure ice cure | cure cure

    // delete bob;
    // delete me;
    // delete src;

    // std::cout << "__________________FUNCTIONAL TEST END__________________" << std::endl << std::endl;


    return 0;
}