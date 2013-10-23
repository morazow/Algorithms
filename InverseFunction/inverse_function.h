#ifndef _INVERSE_H_
#define _INVERSE_H_

// STL
#include <functional>

typedef std::function<double (double)> func_t;

func_t inverse(func_t fn) {

    func_t f = [&fn](double x) {
        double y = fn(x);
        return x + y;
    };

    return f;
}

#endif
