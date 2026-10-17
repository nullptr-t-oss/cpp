#include <iostream>

void doNothing(int*)
{
}

void doNothing2(int&)
{
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    [[maybe_unused]] int _def;    /* default initilization*/
    [[maybe_unused]] int __def;
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

    /* trick compiler into thinking that we are not using uninitialized __def variable
     * hence silencing the errors/warning(s)
     */
    // doNothing(&__def);
    doNothing2(__def);
    std::cout << "__def is: " << __def << "; size of __def if: " << sizeof(__def) << '\n';


    /* if _def is printed it will produce gibberish values since its not initialized */
    std::cout << a << b << c << d << e << f << std::endl; /* try avoiding endl for muliple LF since it flushes the buffer everytime */

    /* '/' maps to 0x2F and 'n' maps to 0x6E in ASCII
     *  combining we get: 0x2F6E which translates to 12142
     */
    std::cout << '/n' << '\n'; /* 12142 */

    int x{}, y{}, z{4};

    std::cout << "Enter two numbers: ";

    /* when input is 5a 6, then output is 5, 0 and 4
     * when input is 5 6a, then output is 5, 6 and 0
     * when input is 5a 6 7, then output is 5, 0 and 4 ; since extraction failed since first encounter of a and its not flushed
     *  if an extraction fails due to a type mismatch, the variable that caused the failure is assigned a value of 0
     *  and queued up variables are skipped (thats why 5 6a produced 0 for z and 5a 6 didnt bcoz in the former, 
     *                                       extraction failed at z but in the latter if failed at y)
     */
    std::cin >> x >> y >> z;
    std::cout << "x is: " << x << " y is: " << y << " z is: " << z << '\n';
    return 0;
}
