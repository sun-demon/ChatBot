//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_ADMIN_H
#define TEST_ADMIN_H


#include <string>

#include "Client.h"

namespace DDP {
    class Admin : public Client {
    public:
        std::ostream & serialize(std::ostream &) const override;
        std::istream & deserialize(std::istream &) override;
    };
}

#endif //TEST_ADMIN_H
