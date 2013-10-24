#ifndef _INVERSE_H_
#define _INVERSE_H_

// STL
#include <functional>

// C
#include <stdio.h>
#include <math.h>

const double EPS = 1e-15;
typedef std::function<double (double)> func_t;

func_t inverse(func_t fn) {

    func_t bsearch = [&fn](double x) {
        //assert( x > 0 );
        double low  = 0,
               mid  = 0,
               high = x,
               guess;

        while ( true ) {
            if (high - low < EPS)
                break;

            mid = (low + high) / 2;
            guess = fn(mid);

            if ( (fabs(guess - x) / x) < EPS )
                break;
            else if (guess < x)
                low = mid;
            else
                high = mid;
        }
        return mid;
    };

    return bsearch;
}

#endif
