#include <iostream>
#include <cstdint>

using u32 = uint32_t;

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    /* goal: given a number n; check divisibility using bit masking */

    u32 n{};
    std::cout << "Enter a number: ";
    std::cin >> n;
    /**
     * 2^4 is 16; and 16 = 1 (mod 5)
     * also, 
     *  for any positive integer k, we can write 16^k as
     *  (15 + 1)^k
     *  
     *  applying binominal theorem,
     *  (kC0)15^k + kC1(15^k-1) + .... + 1^k
     *  hence
     *  16^k = 1 (mod 5) 
     * bcz all terms contains 15 except the last term
     * in the binomial expansion
     * 
     * so if we express binary numbers in base 16 notation like:
     *   High * 16^k + Low ; and apply modulo 5, we get:
     * 
     *   (( High (mod 5) * 16^k (mod 5) ) (mod 5) + Low (mod 5) ) (mod 5)
     *   (High (mod 5) + Low (mod 5)) (mod 5)
     *   ( High + Low ) (mod 5)
     * 
     *   hence High + Low will still give same remainder as the original number
     * 
     *   matter of fact 16^k is 2^4k, hence splliting at 4k intervals like 4, 8, 16...
     *   should give High + Low that doesent affect the remainder
     * 
     */
    n = (n >> 16) + (n & 0xFFFF); /* 16 bit split; high * 2^16 + low */
    /**
     * max value of n after this: 0xFFFF + 0xFFFF = 0x1FFFE
     */
    n = (n >> 8) + (n & 0xFF); /* 8 bit split; high * 2^8 + low */
    /**
     * max value of n after this if we split previous value : 0x1FF + 0xFE = 0x2FD
     * 
     * but, for true max, max out low and reduce high while remaining strictly within
     * previous max (0x1FFFE)
     * 
     * note that: 0x1FEFF < 0x1FFFE
     * so max becomes : 0x1FE + 0xFF = 0x2FD (same here)
     */
    n = (n >> 4) + (n & 0xF); /* 4 bit split; high * 2^4 + low */
    /**
     * max value of n after this: 0x2F + 0xD = 0x3C
     * 
     * note that: 0x2EF < 0x2FD
     * true max: 0x2E + 0xF = 0x3D
     */
    n = (n >> 4) + (n & 0xF); /* 4 bit split; high * 2^4 + low */
    /**
     * max value of n after this: 0x3 + 0xD = 0x10
     * 
     * note that: 0x2F < 0x3D
     * true max = 0x2 + 0xF = 0x11
     */
    n = (n >> 4) + (n & 0xF); /* 4 bit split; high * 2^4 + low */
    /**
     * max value of n after this: 0x1 + 0x1 = 0x2
     * 
     * note that: 0xF < 0x11
     * true max = 0x0 + 0xF = 0xF
     */
    
    /**
     * multiples of 15 lying in this range are:
     * 5  0b0101
     * 10 0b1010
     * 15 0b1111
     * 
     * somehow check if this number n now 0, 5, 10, 15
     * 
     * just create a 16bit lookup table, like this:
     *  0b1000010000100001
     *  basically set every i th number we need to check at
     *  i th index, now extact i th bit, and check if its one or not
     * 
     * 0b1000 0100 0010 0001 translates to: 0x8421
     */
    bool is_div_by5 = (0x8421 >> n) & 1;

    if(is_div_by5)
        std::cout << "n is divisible by 5\n";
    else
        std::cout << "n is not divisible by 5\n";


    return 0;
}
