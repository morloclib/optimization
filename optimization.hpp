#ifndef __OPTIMIZATION_H__
#define __OPTIMIZATION_H__

#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_min.h>

/*
GNU Scientific Library - One dimensional minimization
https://www.gnu.org/software/gsl/doc/html/min.html
*/

double fun(double x, void* ptr){
    double (*f)(double);
    f = (double (*)(double)) ptr;
    return f(x);
}

double optimize1D (double (*f)(double), double a, double b, int max_iter){
    int status;
    int iter = 0;
    const gsl_min_fminimizer_type *T;
    gsl_min_fminimizer *s;
    double m = (a + b) / 2;

    // FIXME: this is a very dirty hack.
    // I don't want to pass a paramter list. In a language that supported
    // nested functions, I would specialize the function. For example, in
    // Haskell:
    //   f :: Double -> Double
    //   f' :: Double -> Params -> Double
    //   f' x _ = f x
    // But I am not sure if this is even possible in C. So instead I ninja the
    // function into the unsed parameter void pointer and use `fun` to unwrap
    // it.
    gsl_function F;
    F.function = fun;
    F.params = ((void*) f);

    T = gsl_min_fminimizer_brent;
    s = gsl_min_fminimizer_alloc (T);
    gsl_min_fminimizer_set (s, &F, m, a, b);

    do
        {
            iter++;
            status = gsl_min_fminimizer_iterate (s);
          
            m = gsl_min_fminimizer_x_minimum (s);
            a = gsl_min_fminimizer_x_lower (s);
            b = gsl_min_fminimizer_x_upper (s);
          
            status = gsl_min_test_interval (a, b, 0.001, 0.0);
        }
    while (status == GSL_CONTINUE && iter < max_iter);
    return m;
}

#endif
