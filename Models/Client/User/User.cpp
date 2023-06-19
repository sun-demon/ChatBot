//
// Created by Daniil on 10.06.2023.
//

#include "User.h"

#include <fstream>

using namespace std;

namespace DDP {
    User::User() {}
    User::User(const std::string & login, const std::string & password, const std::string & surname, const std::string & name, int age) {
        setLogin(login);
        setPassword(password);
        setSurname(surname);
        setName(name);
        setAge(age);
    }

    ostream & User::serialize(ostream & out) const {
        string prefix = "User";
        size_t prefixSize = prefix.size();

        out.write(prefix.c_str(), (long long)prefixSize + 1);
        Client::serialize(out);
        return out;
    }
    istream & User::deserialize(istream & in) {
        string prefix = "User";
        size_t prefixSize = prefix.size();
        char buffer[prefixSize + 1];

        in.read(buffer, (long long)prefixSize + 1);
        Client::deserialize(in);
        return in;
    }
}