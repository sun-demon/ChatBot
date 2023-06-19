//
// Created by Daniil on 10.06.2023.
//

#include "DatabaseManager.h"

#include <fstream>
#include <algorithm>

using namespace std;

namespace DDP {
    void DatabaseManager::insertUser(User & user) {
        user.setID(database.nextUserID++);
        database.users.push_back(user);
    }
    bool compareUserByID(const User & first, const int & id) { return first.getID() < id; }
    void DatabaseManager::deleteUserByID(int id) {
        auto it = lower_bound(database.users.begin(), database.users.end(), id, compareUserByID);
        database.users.erase(it);
    }
    Vector<User> & DatabaseManager::getAllUsers() {
        return database.users;
    }
    User & DatabaseManager::getUserByID(int id) {
        return *lower_bound(database.users.begin(), database.users.end(), id, compareUserByID);
    }


    void DatabaseManager::insertAdmin(Admin & admin) {
        admin.setID(database.nextAdminID++);
        database.admins.push_back(admin);
    }
    bool compareAdminByID(const Admin & first, const int & id) { return first.getID() < id; }
    void DatabaseManager::deleteAdminByID(int id) {
        auto it = lower_bound(database.admins.begin(), database.admins.end(), id, compareAdminByID);
        database.admins.erase(it);
    }
    Vector<Admin> & DatabaseManager::getAllAdmins() {
        return database.admins;
    }
    Admin & DatabaseManager::getAdminByID(int id) {
        return *lower_bound(database.admins.begin(), database.admins.end(), id, compareAdminByID);
    }


    void DatabaseManager::insertLetter(Letter & letter) {
        letter.setID(database.nextLetterID++);
        database.letters.push_back(letter);
    }
    bool compareLetterByID(const Letter & first, const int & id) { return first.getID() < id; }
    void DatabaseManager::deleteLetterByID(int id) {
        auto it = lower_bound(database.letters.begin(), database.letters.end(), id, compareLetterByID);
        database.letters.erase(it);
    }
    Vector<Letter> & DatabaseManager::getAllLetters() {
        return database.letters;
    }
    Letter & DatabaseManager::getLetterByID(int id) {
        return *lower_bound(database.letters.begin(), database.letters.end(), id, compareLetterByID);
    }


    DatabaseManager::DatabaseManager() {
        usersDeserialize();
        adminsDeserialize();
        lettersDeserialize();
    }
    DatabaseManager::~DatabaseManager() {
        usersSerialize();
        adminsSerialize();
        lettersSerialize();
    }


    void DatabaseManager::usersSerialize() {
        ofstream fileOut(usersFileName, ios_base::binary);

        int nextUserID = database.nextUserID;
        fileOut.write((char *) &nextUserID, sizeof(nextUserID));

        size_t usersSize = database.users.size();
        fileOut.write((char *) &usersSize, sizeof(usersSize));
        for (auto & user : database.users)
            user.serialize(fileOut);

        fileOut.close();
    }
    void DatabaseManager::usersDeserialize() {
        ifstream fileIn(usersFileName, ios_base::binary);
        if (!fileIn)
            return;

        ;
        fileIn.read((char *) &(database.nextUserID), sizeof(database.nextUserID));

        size_t usersSize;
        fileIn.read((char *) &usersSize, sizeof(usersSize));
        User user;
        for (int i = 0; i < usersSize; ++i) {
            user.deserialize(fileIn);
            database.users.push_back(user);
        }
        fileIn.close();
    }

    void DatabaseManager::adminsSerialize() {
        ofstream fileOut(adminsFileName, ios_base::binary);

        int nextAdminID = database.nextAdminID;
        fileOut.write((char *) &nextAdminID, sizeof(nextAdminID));

        size_t adminsSize = database.admins.size();
        fileOut.write((char *) &adminsSize, sizeof(adminsSize));
        for (auto & admin : database.admins)
            admin.serialize(fileOut);

        fileOut.close();
    }
    void DatabaseManager::adminsDeserialize() {
        ifstream fileIn(adminsFileName, ios_base::binary);
        if (!fileIn)
            return;

        fileIn.read((char *) &(database.nextAdminID), sizeof(database.nextAdminID));

        size_t adminsSize;
        fileIn.read((char *) &adminsSize, sizeof(adminsSize));
        Admin admin;
        for (int i = 0; i < adminsSize; ++i) {
            admin.deserialize(fileIn);
            database.admins.push_back(admin);
        }
        fileIn.close();
    }

    void DatabaseManager::lettersSerialize() {
        ofstream fileOut(lettersFileName, ios_base::binary);

        int nextLetterID = database.nextLetterID;
        fileOut.write((char *) &nextLetterID, sizeof(nextLetterID));

        size_t lettersSize = database.letters.size();
        fileOut.write((char *) &lettersSize, sizeof(lettersSize));
        for (auto & letter : database.letters)
            letter.serialize(fileOut);

        fileOut.close();
    }
    void DatabaseManager::lettersDeserialize() {
        ifstream fileIn(lettersFileName, ios_base::binary);
        if (!fileIn)
            return;

        fileIn.read((char *) &(database.nextLetterID), sizeof(database.nextLetterID));

        size_t lettersSize;
        fileIn.read((char *) &lettersSize, sizeof(lettersSize));
        Letter letter;
        for (int i = 0; i < lettersSize; ++i) {
            letter.deserialize(fileIn);
            database.letters.push_back(letter);
        }
        fileIn.close();
    }
}