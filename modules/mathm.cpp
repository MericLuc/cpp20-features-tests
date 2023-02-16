/*
 * Global module fragment
 */
module;

// include libraries not modularized yet
/// #include <myLib.h>

/*
 * Module declaration
 */
export module mathm;

/*
 * Non exported declarations
 * i.e. module linkage
 *
 * Note : The c++20 standard ensures every
 * stl headers are modularized.
 */

import <vector>;
import <numeric>;
import <concepts>;

/*
 * Exported names
 * i.e. external-linkage
 */
export namespace mathm {

/*
 * It is possible to declare generic functions
 * in a module.
 *
 */
template < std::integral T, std::integral U >
auto add(T t, U u) {
    return t + u;
}

auto elemsProduct( const std::vector<int>& v ) noexcept {
    return std::accumulate(std::cbegin(v),
                           std::cend(v),
                           1,
                           std::multiplies<int>());
}

}
