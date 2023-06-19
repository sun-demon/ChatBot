//
// Created by Daniil on 10.06.2023.
//

#include "ClientException.h"

using namespace std;

namespace DDP {
    ClientException::ClientException(const std::string& message) : invalid_argument(message) {}

    LoginException::LoginException(const std::string& message) : ClientException(message) {}

    PasswordException::PasswordException(const std::string& message) : ClientException(message) {}

    SurnameException::SurnameException(const std::string& message) : ClientException(message) {}

    NameException::NameException(const std::string& message) : ClientException(message) {}

    AgeException::AgeException(const std::string& message) : ClientException(message) {}
}