#pragma once

namespace own::ds::utils {
    template<typename F, typename S>
    class Pair {
    public:
        F first;
        S second;
        Pair();
        Pair(F first, S second);
    };
}

#include "pair.tpp"
