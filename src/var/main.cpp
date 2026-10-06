#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    [[maybe_unused]] int _def;    /* default initilization*/
    int a = 2;   /* traditional copy initialization */ 
    int b ( 5 ); /* traditional direct initialization */
    int c { 3 }; /* modern direct-list initialization */
    int d { };   /* modern value initialization */
    int e = { 4 }; /* copy list initialization */

    int f ( 0 );
    /* int g { 1.0 }; error! nawrrowing now allowed in list initialization */
    [[maybe_unused]] int g = 1.0;

    b = a = 9; /* works ; same in Java */
    // d { 8 };

    std::cout << a << b << c << d << e << f << std:: endl;
    return 0;
}
