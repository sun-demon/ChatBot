//
// Created by Daniil on 10.06.2023.
//

#include "Client.h"

#include <regex>

#include "ClientException.h"
#include "DatabaseManager.h"
#include "Letter.h"

using namespace std;

namespace DDP {
    ostream & Client::serialize(ostream & out) const {
        size_t loginSize = login_.size(), passwordSize = password_.size(),
                surnameSize = surname_.size(), nameSize = name_.size();

        out.write((char *) &id_, sizeof(id_));

        out.write((char *) &loginSize, sizeof(loginSize));
        out.write(login_.c_str(), (long long)loginSize + 1);

        out.write((char *) &passwordSize, sizeof(passwordSize));
        out.write(password_.c_str(), (long long)passwordSize + 1);

        out.write((char *) &surnameSize, sizeof(surnameSize));
        out.write(surname_.c_str(), (long long)surnameSize + 1);

        out.write((char *) &nameSize, sizeof(nameSize));
        out.write(name_.c_str(), (long long)nameSize + 1);

        out.write((char *) &age_, sizeof(age_));

        return out;
    }
    istream & Client::deserialize(istream & in) {
        size_t loginSize, passwordSize, surnameSize, nameSize;
        char buffer[2048];

        in.read((char *) &id_, sizeof(id_));

        in.read((char *) &loginSize, sizeof(loginSize));
        in.read(buffer, (long long)loginSize + 1);
        login_ = buffer;

        in.read((char *) &passwordSize, sizeof(passwordSize));
        in.read(buffer, (long long)passwordSize + 1);
        password_ = buffer;

        in.read((char *) &surnameSize, sizeof(surnameSize));
        in.read(buffer, (long long)surnameSize + 1);
        surname_ = buffer;

        in.read((char *) &nameSize, sizeof(nameSize));
        in.read(buffer, (long long)nameSize + 1);
        name_ = buffer;

        in.read((char *) &age_, sizeof(age_));

        return in;
    }


    void Client::sendMessage(int toID, const string & message) const {
        Letter letter = Letter(id_, toID, message);
        DatabaseManager::getInstance().insertLetter(letter);
    }


    int Client::getID() const { return id_; }
    const string & Client::getLogin() const { return login_; }
    const string & Client::getPassword() const { return password_; }
    const string & Client::getSurname() const { return surname_; }
    const string & Client::getName() const { return name_; }
    int Client::getAge() const { return age_; }


    void Client::setID(int id) {
        id_ = id;
    }
    void Client::setLogin(const string & login) {
        checkLogin(login);
        login_ = login;
    }
    void Client::setPassword(const string & password) {
        checkPassword(password);
        password_ = password;
    }
    void Client::setSurname(const string & surname) {
        checkSurname(surname);
        surname_ = surname;
    }
    void Client::setName(const string & name) {
        checkName(name);
        name_ = name;
    }
    void Client::setAge(int age) {
        checkAge(age);
        age_ = age;
    }


    void Client::checkLogin(const string & login) {
        if (!isValidLogin(login))
            throw LoginException();
    }
    void Client::checkPassword(const string & password) {
        if (!isValidPassword(password))
            throw PasswordException();
    }
    void Client::checkSurname(const string & surname) {
        if (!isValidSurname(surname))
            throw SurnameException();
    }
    void Client::checkName(const string & name) {
        if (!isValidName(name))
            throw NameException();
    }
    void Client::checkAge(int age) {
        if (!isValidAge(age))
            throw AgeException();
    }


    bool Client::isValidLogin(const string & login) {
        return regex_match(login, regex("^[a-z]+\\d*$")) && login.size() > 1;
    }
    bool Client::isValidPassword(const string & password) {
        return regex_match(password, regex("^(?=.*\\d)(?=.*[a-zA-Z])(?!.*\\s).{8,40}$"));
    }
    bool Client::isValidSurname(const string & surname) {
        return regex_match(surname, regex("^[a-zA-Z]*$"));
    }
    bool Client::isValidName(const string & name) {
        return regex_match(name, regex("^[a-zA-Z]*$"));
    }
    bool Client::isValidAge(int age) {
        return (6 <= age && age <= 200);
    }
}
