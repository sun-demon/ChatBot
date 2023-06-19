//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_DATABASE_H
#define TEST_DATABASE_H


#include "Admin.h"
#include "Letter.h"
#include "User.h"
#include "Vector.h"

namespace DDP {
    struct Database {
        int nextUserID = 0;
        int nextAdminID = 0;
        int nextLetterID = 0;

        Vector<User> users = Vector<User>();
        Vector<Admin> admins = Vector<Admin>();
        Vector<Letter> letters = Vector<Letter>();
    };
}


#endif //TEST_DATABASE_H
