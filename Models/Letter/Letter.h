//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_LETTER_H
#define TEST_LETTER_H


#include <string>

#include "ISerializable.h"

namespace DDP {
    class Letter : ISerializable {
    public:
        Letter(int = 0, int = 0, const std::string & = "");

        std::ostream & serialize(std::ostream &) const override;
        std::istream & deserialize(std::istream &) override;

        int getID() const;
        int getFrom() const;
        int getTo() const;
        const std::string & getMessage() const;
        long long getDateTime() const;

        void setID(int);
        void setFrom(int);
        void setTo(int);
        void setMessage(const std::string &);
        void setDateTime(long long);

    private:
        static void checkMessage(const std::string &);
        static bool isValidMessage(const std::string &);

        int id_ = 0;
        int from_;
        int to_;
        std::string message_;
        long long dateTime_;
    };
}


#endif //TEST_LETTER_H
