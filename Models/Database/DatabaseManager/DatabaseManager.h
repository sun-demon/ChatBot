//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_DATABASE_MANAGER_H
#define TEST_DATABASE_MANAGER_H


#include "Database.h"
#include "UserController.h"
#include "AdminController.h"
#include "LetterController.h"

namespace DDP {
    class DatabaseManager : UserController, AdminController, LetterController {
    public:
        static DatabaseManager &getInstance() {
            static DatabaseManager instance;
            return instance;
        }


        void insertUser(User &) override;
        void deleteUserByID(int) override;
        Vector<User> & getAllUsers() override;
        User & getUserByID(int) override;

        void insertAdmin(Admin &) override;
        void deleteAdminByID(int) override;
        Vector<Admin> & getAllAdmins() override;
        Admin & getAdminByID(int) override;

        void insertLetter(Letter &) override;
        void deleteLetterByID(int) override;
        Vector<Letter> & getAllLetters() override;
        Letter & getLetterByID(int) override;


    private:
        DatabaseManager();
        ~DatabaseManager();
        DatabaseManager(DatabaseManager const &) {}
        void operator=(DatabaseManager const &) {}

        void usersSerialize();
        void usersDeserialize();

        void adminsSerialize();
        void adminsDeserialize();

        void lettersSerialize();
        void lettersDeserialize();

        Database database;
        const std::string usersFileName = "users.bin";
        const std::string adminsFileName = "admins.bin";
        const std::string lettersFileName = "letters.bin";
    };
}

#endif //TEST_DATABASE_MANAGER_H
