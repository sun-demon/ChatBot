//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_USER_H
#define TEST_USER_H


#include "Client.h"

namespace DDP {
    class User : public Client {
    public:
        User();
        User(const std::string &, const std::string &, const std::string &, const std::string &, int);

        std::ostream & serialize(std::ostream &) const override;
        std::istream & deserialize(std::istream &) override;
    };
}


#endif //TEST_USER_H
