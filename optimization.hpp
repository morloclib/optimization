#ifndef __OPTIMIZATION_HPP__
#define __OPTIMIZATION_HPP__

#include <limits>
#include <boost/math/tools/minima.hpp>
#include <utility>
using boost::math::tools::brent_find_minima;

template<class F>
double optimize1D(F f, double lbnd, double rbnd){
    int precision = std::numeric_limits<double>::digits;
    std::pair<double, double> r = brent_find_minima(f, lbnd, rbnd, precision);
    return r.first;
}

#endif
