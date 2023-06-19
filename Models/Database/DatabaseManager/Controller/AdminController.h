//
// Created by Daniil on 11.06.2023.
//

#ifndef CHATBOT_ADMIN_CONTROLLER_H
#define CHATBOT_ADMIN_CONTROLLER_H

#include "Admin.h"
#include "Vector.h"

namespace DDP {
    struct AdminController {
        virtual void insertAdmin(Admin &) = 0;
        virtual void deleteAdminByID(int) = 0;
        virtual const Vector<Admin> & getAllAdmins() = 0;
        virtual const Admin & getAdminByID(int) = 0;
    };
}

#endif //CHATBOT_ADMIN_CONTROLLER_H
