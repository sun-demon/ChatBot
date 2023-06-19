//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_ISERIALIZABLE_H
#define TEST_ISERIALIZABLE_H


#include <ostream>

namespace DDP {
    struct ISerializable {
        virtual std::ostream & serialize(std::ostream &) const = 0;
        virtual std::istream & deserialize(std::istream &) = 0;
    };
}

#endif //TEST_ISERIALIZABLE_H
