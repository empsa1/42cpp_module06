#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include "Utils.hpp"
#include <stdint.h>
#include <iostream>


class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer(); // Private constructor to prevent instantiation
        Serializer(const Serializer& that); // Private copy constructor
        Serializer& operator=(const Serializer& that); // Private copy assignment operator
        ~Serializer(); // Private destructor
};

#endif