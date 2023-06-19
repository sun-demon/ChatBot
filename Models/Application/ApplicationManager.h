//
// Created by Daniil on 13.06.2023.
//

#ifndef CHATBOT_APPLICATION_MANAGER_H
#define CHATBOT_APPLICATION_MANAGER_H


#include "SignInItem.h"
#include "SignUpItem.h"
#include "LoginItem.h"
#include "PasswordItem.h"
#include "SurnameItem.h"
#include "NameItem.h"
#include "SurnameItem.h"
#include "NameItem.h"
#include "AgeItem.h"
#include "AuthorizeItem.h"
#include "RegisterItem.h"
#include "SentLettersItem.h"
#include "ReceivedLettersItem.h"
#include "NewLetterItem.h"
#include "SentLetterToItem.h"
#include "ReceivedLetterFromItem.h"
#include "NewLetterToItem.h"

namespace DDP {
    class ApplicationManager {
    public:
        static ApplicationManager &getInstance() {
            static ApplicationManager instance;
            return instance;
        }


        SignInItem * newSignInItem();
        SignUpItem * newSignUpItem();
        LoginItem * newLoginItem();
        PasswordItem * newPasswordItem();
        SurnameItem * newSurnameItem();
        NameItem * newNameItem();
        AgeItem * newAgeItem();
        AuthorizeItem * newAuthorizeItem();
        RegisterItem * newRegisterItem();

        SentLettersItem * newSentLettersItem();
        ReceivedLettersItem * newReceivedLettersItem();
        NewLetterItem * newNewLetterItem();

        SentLetterToItem * newSentLetterToItem();
        ReceivedLetterFromItem * newReceivedLetterFromItem();
        NewLetterToItem * newNewLetterToItem();


    private:
        ApplicationManager();
        ~ApplicationManager();
        ApplicationManager(ApplicationManager const &) {}


        Vector<SignInItem *> signInItems;
        Vector<SignUpItem *> signUpItems;
        Vector<LoginItem *> loginItems;
        Vector<PasswordItem *> passwordItems;
        Vector<SurnameItem *> surnameItems;
        Vector<NameItem *> nameItems;
        Vector<AgeItem *> ageItems;
        Vector<AuthorizeItem *> authorizeItems;
        Vector<RegisterItem *> registerItems;
        Vector<SentLettersItem *> sentLettersItems;
        Vector<ReceivedLettersItem *> receivedLettersItems;
        Vector<NewLetterItem *> newLetterItems;

        Vector<SentLetterToItem *> sentLetterToItems;
        Vector<ReceivedLetterFromItem *> receivedLetterFromItems;
        Vector<NewLetterToItem *> newLetterToItems;
    };
}

#endif //CHATBOT_APPLICATION_MANAGER_H
