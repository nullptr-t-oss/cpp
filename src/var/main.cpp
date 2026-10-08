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

    std::cout << a << b << c << d << e << f << std::endl; /* try avoiding endl for muliple LF since it flushes the buffer everytime */

    std::cout << '/n'; /* 12142 */

    int x{}, y{}, z{};

    std::cout << "Enter two numbers: ";

    /* when input is s 5a 6, then output is 5 and 0
     * when input is 5 6a, then output is 5 and 6
     * when input is 5a 6 7, then output is 5, 0 and 0 ; since extraction failed since first encounter of a and its not flushed
     */
    std::cin >> x >> y >> z;
    std::cout << "x is: " << x << " y is: " << y << " z is: " << z << '\n';
    return 0;
}
