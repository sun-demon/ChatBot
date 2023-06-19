//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_USER_CONTROLLER_H
#define CHATBOT_USER_CONTROLLER_H

#include "User.h"
#include "Vector.h"

namespace DDP {
    struct UserController {
        virtual void insertUser(User &) = 0;
        virtual void deleteUserByID(int) = 0;
        virtual const Vector<User> & getAllUsers() = 0;
        virtual const User & getUserByID(int) = 0;
    };
}

#endif //CHATBOT_USER_CONTROLLER_H
