#pragma once

#include <ostream>

namespace own::ds::linear {
    class Vector {
    private:
        int* data;
        size_t cur_size, cur_capacity;
    public:
        Vector();
        void push_back(int value);
        int get_back();

        friend std::ostream& operator<<(std::ostream& os, Vector const& v);
        ~Vector();
    };
}
