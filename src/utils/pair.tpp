namespace own::ds::utils {
    template<typename F, typename S>
    Pair<F, S>::Pair() {
    }
    
    template<typename F, typename S>
    Pair<F, S>::Pair(F first, S second) : first(first), second(second) {
    }
}
