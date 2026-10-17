#include <iostream>
#include <string>

/* Stein's Algorithm aka Binary GCD Algorithm */
uint gcd(uint a, uint b)
{
    if(!a || !b)
        return a | b;
    
    /* 
     * gcd(2^m * x, 2^n * y) =  2^min(m, n) gcd(x, y)
     * so __builtin_ctz gives the highest power of 2 that
     * divides `both x and y`, factor out now and multiply
     * back at last
     */
    int shift = __builtin_ctz(a | b);

    /*
     * factor out the highest power of 2 from `a` as required
     * from the statement:
     *   gcd(2^m * x, 2^n * y) =  2^min(m, n) gcd(x, y)
     */
    a >>= __builtin_ctz(a);

    do {
        /*
         * in the first iteration:
         *   factor out the highest power of 2 from `b` as required
         *   from the statement:
         *     gcd(2^m * x, 2^n * y) =  2^min(m, n) gcd(x, y)
         * 
         * next runs:
         *   following the statement:
         *     gcd(x, 2^k * y) = gcd(x, y) or gcd(2^k * x, y) = gcd(x, y)
         *    so factor out highest powers of 2 from b.
         *    why not a?
         *      after first statement, `a` is strictly odd, we can get even
         *      number only in `b -= a;` line (since odd - odd is even)
         *      short proof:
         *        as lets say b > a and b = 2k + 1 and a = 2m + 1
         *        then b - a is 2 (k - m) , hence odd - odd is even
         *      so we factor out from b only
         */
        b >>= __builtin_ctz(b);

        /*
         * euclidean gcd states that:
         *   gcd(a, b) = gcd(|a - b|, min(a, b))
         *                   or
         *   gcd(a, b) = gcd(max(a, b) - min(a, b), min(a, b))
         * 
         *   so to get positive difference everytime, always ensure 
         *   b is >= a
         */
        if (a > b)
            std::swap(a, b);
        
        /*
         * euclidean gcd step:
         *   gcd(x, y) = gcd(|a - b|, min(a, b))
         *  
         *   note: we need to subtract only since we
         *         ensured that b is always >= a
         */
        b -= a;
        
    } while (b); /* gcd(x, 0) is x; so stop */

    /*
     * from the statement:
     *   gcd(2^m * x, 2^n * y) =  2^min(m, n) gcd(x, y)
     * multiply back the 2^min(m, n) we factored out earlier
     * 
     * note: the factoring of 2^min(m, n) is done implicitly since
     *       m, n is <= __builtin_ctz(a) or __builtin_ctz(b)
     * 
     */
    return a <<= shift;
}

int main(int argc __attribute_maybe_unused__, char const *argv[])
{
    std::cout << gcd(static_cast<unsigned int>(std::stoul(argv[1])), static_cast<unsigned int>(std::stoul(argv[2])));
    return 0;
}
