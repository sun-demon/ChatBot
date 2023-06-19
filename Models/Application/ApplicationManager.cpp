//
// Created by Daniil on 13.06.2023.
//

#include "ApplicationManager.h"

namespace DDP {
    ApplicationManager::ApplicationManager() {}

    ApplicationManager::~ApplicationManager() {
//        delete signInItem;
//        delete signUpItem;
//        delete loginItem;
//        delete passwordItem;
//        delete surnameItem;
//        delete nameItem;
//        delete ageItem;
//        delete authorizeItem;
//        delete registerItem;
//        delete sentLettersItem;
//        delete receivedLettersItem;
//        delete newLetterItem;

        for (int i = 0; i < signInItems.size(); ++i)
            delete signInItems[i];
        for (int i = 0; i < signUpItems.size(); ++i)
            delete signUpItems[i];


        for (int i = 0; i < loginItems.size(); ++i)
            delete loginItems[i];
        for (int i = 0; i < passwordItems.size(); ++i)
            delete passwordItems[i];
        for (int i = 0; i < surnameItems.size(); ++i)
            delete surnameItems[i];
        for (int i = 0; i < nameItems.size(); ++i)
            delete nameItems[i];
        for (int i = 0; i < ageItems.size(); ++i)
            delete ageItems[i];


        for (int i = 0; i < authorizeItems.size(); ++i)
            delete authorizeItems[i];
        for (int i = 0; i < registerItems.size(); ++i)
            delete registerItems[i];


        for (int i = 0; i < sentLettersItems.size(); ++i)
            delete sentLettersItems[i];

        for (int i = 0; i < receivedLettersItems.size(); ++i)
            delete receivedLettersItems[i];

        for (int i = 0; i < newLetterItems.size(); ++i)
            delete newLetterItems[i];


        for (int i = 0; i < sentLettersItems.size(); ++i)
            delete sentLettersItems[i];

        for (int i = 0; i < receivedLetterFromItems.size(); ++i)
            delete receivedLetterFromItems[i];

        for (int i = 0; i < newLetterToItems.size(); ++i)
            delete newLetterToItems[i];
    }

//    SignInItem *ApplicationManager::newSignInItem() { delete signInItem; return signInItem = new SignInItem(); }
//    SignUpItem *ApplicationManager::newSignUpItem() { delete signUpItem; return signUpItem = new SignUpItem(); }
//    LoginItem *ApplicationManager::newLoginItem() { delete loginItem; return loginItem = new LoginItem(); }
//    PasswordItem *ApplicationManager::newPasswordItem() { delete passwordItem; return passwordItem = new PasswordItem(); }
//    SurnameItem *ApplicationManager::newSurnameItem() { delete surnameItem; return surnameItem = new SurnameItem(); }
//    NameItem *ApplicationManager::newNameItem() { delete nameItem; return nameItem = new NameItem(); }
//    AgeItem *ApplicationManager::newAgeItem() { delete ageItem; return ageItem = new AgeItem(); }
//    AuthorizeItem *ApplicationManager::newAuthorizeItem() { delete authorizeItem; return authorizeItem = new AuthorizeItem(); }
//    RegisterItem *ApplicationManager::newRegisterItem() { delete registerItem; return registerItem = new RegisterItem(); }
//    SentLettersItem *ApplicationManager::newSentLettersItem() { delete sentLettersItem; return sentLettersItem = new SentLettersItem(); }
//    ReceivedLettersItem *ApplicationManager::newReceivedLettersItem() { delete receivedLettersItem; return receivedLettersItem = new ReceivedLettersItem(); }
//    NewLetterItem *ApplicationManager::newNewLetterItem() { delete newLetterItem; return newLetterItem = new NewLetterItem(); }



    SignInItem *ApplicationManager::newSignInItem() {
        signInItems.push_back(new SignInItem());
        return *(signInItems.end() - 1);
    }
    SignUpItem *ApplicationManager::newSignUpItem() {
        signUpItems.push_back(new SignUpItem());
        return *(signUpItems.end() - 1);
    }

    LoginItem *ApplicationManager::newLoginItem() {
        loginItems.push_back(new LoginItem());
        return *(loginItems.end() - 1);
    }
    PasswordItem *ApplicationManager::newPasswordItem() {
        passwordItems.push_back(new PasswordItem());
        return *(passwordItems.end() - 1);
    }
    SurnameItem *ApplicationManager::newSurnameItem() {
        surnameItems.push_back(new SurnameItem());
        return *(surnameItems.end() - 1);
    }
    NameItem *ApplicationManager::newNameItem() {
        nameItems.push_back(new NameItem());
        return *(nameItems.end() - 1);
    }
    AgeItem *ApplicationManager::newAgeItem() {
        ageItems.push_back(new AgeItem());
        return *(ageItems.end() - 1);
    }

    AuthorizeItem *ApplicationManager::newAuthorizeItem() {
        authorizeItems.push_back(new AuthorizeItem());
        return *(authorizeItems.end() - 1);
    }
    RegisterItem *ApplicationManager::newRegisterItem() {
        registerItems.push_back(new RegisterItem());
        return *(registerItems.end() - 1);
    }
    SentLettersItem *ApplicationManager::newSentLettersItem() {
        sentLettersItems.push_back(new SentLettersItem());
        return *(sentLettersItems.end() - 1);
    }
    ReceivedLettersItem *ApplicationManager::newReceivedLettersItem() {
        receivedLettersItems.push_back(new ReceivedLettersItem());
        return *(receivedLettersItems.end() - 1);
    }
    NewLetterItem *ApplicationManager::newNewLetterItem() {
        newLetterItems.push_back(new NewLetterItem());
        return *(newLetterItems.end() - 1);
    }



    SentLetterToItem *ApplicationManager::newSentLetterToItem() {
        sentLetterToItems.push_back(new SentLetterToItem());
        return *(sentLetterToItems.end() - 1);
    }

    ReceivedLetterFromItem *ApplicationManager::newReceivedLetterFromItem() {
        receivedLetterFromItems.push_back(new ReceivedLetterFromItem());
        return *(receivedLetterFromItems.end() - 1);
    }

    NewLetterToItem *ApplicationManager::newNewLetterToItem() {
        newLetterToItems.push_back(new NewLetterToItem());
        return *(newLetterToItems.end() - 1);
    }
}