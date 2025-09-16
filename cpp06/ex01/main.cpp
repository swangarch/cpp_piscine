#include <iostream>
#include <string>
#include "Serializer.hpp"
#include "Data.hpp"

int     main(void)
{
    Data    d;

    d.num = 1231231231;

    std::cout << "Original content of the structure Data is: " << d.num << std::endl;

    uintptr_t serializedPtr = Serializer::serialize(&d);

    Data*    dptr;
    
    dptr = Serializer::deserialize(serializedPtr);
    std::cout << "After serialized - deserialized, content of the structure Data is: " << dptr->num << std::endl;

    std::cout << "Original pointer: " << &d << std::endl;
    std::cout << "Deserialized pointer: " << dptr << std::endl;
}