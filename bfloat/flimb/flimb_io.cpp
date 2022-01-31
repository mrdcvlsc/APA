#ifndef FLIMB_IO_HPP
#define FLIMB_IO_HPP

#include <iostream>
#include "flimb.hpp"

namespace backend_bigfloat
{
    std::istream& operator>>(std::istream& in, flimb& value)
    {
        std::string input_stream(std::istreambuf_iterator<char>(in), {});
        value = flimb(input_stream);
        return in;
    }

    std::ostream& operator<<(std::ostream &out, const flimb& value)
    {
        // temporary fix
        out << value.string_form();
        return out;
    }
}

#endif