//
// Created by Daniil on 10.06.2023.
//

#include "Letter.h"

#include <fstream>
#include <chrono>

#include "LetterException.h"

namespace sc = std::chrono;
using namespace std;

namespace DDP {
    Letter::Letter(int from, int to, const string & message) : from_(from), to_(to) {
        setMessage(message);
        auto time = sc::system_clock::now();
        auto sinceEpoch = time.time_since_epoch();
        auto millis = sc::duration_cast<sc::milliseconds>(sinceEpoch);
        dateTime_ = millis.count();
    }


    ostream & Letter::serialize(ostream & out) const {
        out.write((char *) &id_, sizeof(id_));
        out.write((char *) &from_, sizeof(from_));
        out.write((char *) &to_, sizeof(to_));

        size_t messageSize = message_.size();
        out.write((char *) &messageSize, sizeof(messageSize));
        out.write(message_.c_str(), (long long)messageSize + 1);

        out.write((char *) &dateTime_, sizeof(dateTime_));
        return out;
    }
    istream & Letter::deserialize(istream & in) {
        in.read((char *) &id_, sizeof(id_));
        in.read((char *) &from_, sizeof(from_));
        in.read((char *) &to_, sizeof(to_));

        size_t messageSize;
        char buffer[2048];
        in.read((char *) & messageSize, sizeof(messageSize));
        in.read(buffer, (long long)messageSize + 1);
        message_ = buffer;

        in.read((char *) &dateTime_, sizeof(dateTime_));
        return in;
    }


    int Letter::getID() const { return id_; }
    int Letter::getFrom() const { return from_; }
    int Letter::getTo() const { return to_; }
    const string & Letter::getMessage() const { return message_; }
    long long Letter::getDateTime() const { return dateTime_; }

    void Letter::setID(int id) { id_ = id; }
    void Letter::setFrom(int from) { from_ = from; }
    void Letter::setTo(int to) { to_ = to; }
    void Letter::setMessage(const string & message) {
        checkMessage(message);
        message_ = message;
    }
    void Letter::setDateTime(long long dateTime) { dateTime_ = dateTime; }


    void Letter::checkMessage(const string & message) {
        if (!isValidMessage(message))
            throw LetterException();
    }
    bool Letter::isValidMessage(const string & message) {
        return message.size() < 2048;
    }
}