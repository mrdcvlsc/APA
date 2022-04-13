#ifndef UNSIGNED_BIG_INTEGER_HPP
#define UNSIGNED_BIG_INTEGER_HPP

#include <iostream>
#include <cstring>

#if (__MINGW64__ || __MINGW64)
#define PRINT_LIMBHEX "%08llx "
#elif (__clang__ || __GNUC__ || __GNUG__)
#define PRINT_LIMBHEX "%08lx "
#else
#error not supported
#endif

// BASE => MAX VALUE OF EACH LIMBS CAN HOLD

#define UBINT_BASE 4294967295
#define UBINT_BASEBITS 32
#define UBINT_BASEBYTES 4

#define UBINT_INITIAL_LIMB_CAPACITY 4
#define UBINT_INITIAL_LIMB_LENGTH 2
#define LIMB_BYTES 8

#define LESS -1
#define EQUAL 0
#define GREAT 1

namespace apa {
    class ubint {
        public:
            size_t capacity;
            size_t length;
            uint64_t *limbs;

            ubint();
            ubint(size_t num);

            /// copy constructor.
            ubint(const ubint& src);
            
            /// move constructor.
            ubint(ubint&& src) noexcept;

            /// copy assignment.
            ubint& operator=(const ubint& src);

            /// move assignment.
            ubint& operator=(ubint&& src) noexcept;

            ~ubint();

            /// @return returns; -1 : if less than, 0 : if equal, 1 : if greater than.
            int compare(const ubint& with) const;
            bool operator==(const ubint& op) const;

            ubint& operator+=(const ubint& op);
            ubint& operator-=(const ubint& op);
            ubint operator*(const ubint& op) const;
            ubint operator/(const ubint& op) const;

            void printHex() const;
    };
}
#endif

#ifndef _MAKE_LIB
#include "ubint.cpp"
#endif