//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_CLIENT_H
#define TEST_CLIENT_H


#include <string>

#include "ISerializable.h"

namespace DDP {
    class Client : ISerializable {
    public:
        std::ostream & serialize(std::ostream &) const override;
        std::istream & deserialize(std::istream &) override;

        void sendMessage(int, const std::string &) const;

        int getID() const;
        const std::string & getLogin() const;
        const std::string & getPassword() const;
        const std::string & getSurname() const;
        const std::string & getName() const;
        int getAge() const;

        void setID(int);
        void setLogin(const std::string &);
        void setPassword(const std::string &);
        void setSurname(const std::string &);
        void setName(const std::string &);
        void setAge(int);

        static void checkLogin(const std::string &);
        static void checkPassword(const std::string &);
        static void checkSurname(const std::string &);
        static void checkName(const std::string &);
        static void checkAge(int);

        static bool isValidLogin(const std::string &);
        static bool isValidPassword(const std::string &);
        static bool isValidSurname(const std::string &);
        static bool isValidName(const std::string &);
        static bool isValidAge(int);

    private:
        int id_;
        std::string login_;
        std::string password_;
        std::string surname_;
        std::string name_;
        int age_;
    };
}


#endif //TEST_CLIENT_H
