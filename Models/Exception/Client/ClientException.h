//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_CLIENT_EXCEPTION_H
#define TEST_CLIENT_EXCEPTION_H


#include <stdexcept>

namespace DDP {
    struct ClientException : std::invalid_argument {
        explicit ClientException(const std::string& message = "Client exception");
    };

    struct LoginException : ClientException {
        explicit LoginException(const std::string& message = "Login must contain only letters and digits and first character must be a letter");
    };

    struct PasswordException : ClientException {
        explicit PasswordException(const std::string& message = "Password must contain letter, digit with length from 8 to 40 without spaces");
    };

    struct SurnameException : ClientException {
        explicit SurnameException(const std::string& message = "Surname must contain only letters");
    };

    struct NameException : ClientException {
        explicit NameException(const std::string& message = "Name must contain only letters");
    };

    struct AgeException : ClientException {
        explicit AgeException(const std::string& message = "Age must be in range from 6 to 200");
    };
}


#endif //TEST_CLIENT_EXCEPTION_H
