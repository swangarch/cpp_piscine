#include <iostream>
#include "Fixed.hpp"

int main( void ) {

    std::cout << "------------Subject test begin-------------" << std::endl;

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "------------Subject test end---------------" << std::endl << std::endl;


    std::cout << "--------------my test begin----------------" << std::endl;

    std::cout << "[arithmtic operators]" << std::endl;
    std::cout << "0.35 in fixed point number: " <<  Fixed((float)0.35) << std::endl;
    std::cout << "0.6 in fixed point number: " <<  Fixed((float)0.6) << std::endl;
    std::cout << "0.6 + 0.35: " <<  Fixed( (float)0.6 ) + Fixed( (float)0.35 ) << std::endl;
    std::cout << "0.6 + 0.4: " <<  Fixed( (float)0.6 ) + Fixed( (float)0.4 ) << std::endl;
    std::cout << "0.6 + 1: " <<  Fixed( (float)0.6 ) + Fixed( 1 ) << std::endl;
    std::cout << "6 - 8: " <<  Fixed( 6 ) - Fixed( 8 ) << std::endl;
    std::cout << "6 * 2: " <<  Fixed( 6 ) * Fixed( 2 ) << std::endl;
    std::cout << "6 / 7: " <<  Fixed( 6 ) / Fixed( 7 ) << std::endl;
    std::cout << "6.0 * 7: " <<  Fixed( (float)6.0 ) * Fixed( 7 ) << std::endl;
    std::cout << "6.0 + 7 - 3 * 10: " <<  Fixed( (float)6.0 ) + Fixed( 7 ) - Fixed( 3 ) * Fixed( 10 ) << std::endl;
    std::cout << "1.0 + 2 + 3 + 4: " <<  Fixed( (float)1 ) + Fixed( 2 ) + Fixed( 3 ) + Fixed( 4) << std::endl;
    std::cout << "1.0 + 0 + 0.0: " <<  Fixed( (float)1.0 ) + Fixed( 0 ) + Fixed( (float)0.0 ) << std::endl;
    std::cout << std::endl;

    std::cout << "[max_min]" << std::endl;
    std::cout << "0.6 in fixed point number: " <<  Fixed((float)0.6) << std::endl;
    std::cout << "max 0.6 0.35: " <<  Fixed::max(Fixed((float)0.6), Fixed((float)0.35)) << std::endl;
    std::cout << "max 1 0.35: " <<  Fixed::max(Fixed(1), Fixed((float)0.35)) << std::endl;
    std::cout << "min 0.6 0.35: " <<  Fixed::min(Fixed((float)0.6), Fixed((float)0.35)) << std::endl;
    std::cout << "min 1 0.35: " <<  Fixed::min(Fixed(1), Fixed((float)0.35)) << std::endl;

    std::cout << "max -199 0: " <<  Fixed::max(Fixed(-199), Fixed(0)) << std::endl;
    std::cout << "min -199 0: " <<  Fixed::min(Fixed(-199), Fixed(0)) << std::endl;
    std::cout << std::endl;

    std::cout << "[comparasion operators]" << std::endl;
    std::cout << "-199 > 0: " <<  (Fixed(-199) > Fixed(0)) << std::endl;
    std::cout << "19.8 > 19.85: " <<  (Fixed((float)19.8) > Fixed((float)19.85)) << std::endl;
    std::cout << "-199 < 0: " <<  (Fixed(-199) < Fixed(0)) << std::endl;
    std::cout << "19.8 < 19.85: " <<  (Fixed((float)19.8) < Fixed((float)19.85)) << std::endl;
    std::cout << "-199 == 0: " <<  (Fixed(-199) == Fixed(0)) << std::endl;
    std::cout << "19.8 != 19.85: " <<  (Fixed((float)19.8) != Fixed((float)19.85)) << std::endl;

    std::cout << std::endl;

    std::cout << "[increment]" << std::endl;

    Fixed fp1 = Fixed((float)1.5);
    Fixed fp2 = fp1++;
    Fixed fp3 = Fixed((float)1.5);
    Fixed fp4 = ++fp3;
    std::cout << "fp1_fp2_fp3_fp4 increment: " << std::endl
              << fp1 << std::endl
              << fp2 << std::endl
              << fp3 << std::endl
              << fp4 << std::endl;

    std::cout << std::endl;

    Fixed fp5 = Fixed((float)1.5);
    Fixed fp6 = fp5--;
    Fixed fp7 = Fixed((float)1.5);
    Fixed fp8 = --fp7;
    std::cout << "fp5_fp6_fp7_fp8 decrement: " << std::endl
              << fp5 << std::endl
              << fp6 << std::endl
              << fp7 << std::endl
              << fp8 << std::endl;

    std::cout << "--------------my test end------------------" << std::endl;

    return (0);
}