cmake_minimum_required(VERSION 3.23)
project(ChatBot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_SOURCE_DIR Models)

include_directories(
        Models/Application

        Models/Client
        Models/Client/Admin
        Models/Client/User

        Models/Database
        Models/Database/DatabaseManager
        Models/Database/DatabaseManager/Controller

        Models/Exception/Client
        Models/Exception/Letter

        Models/Function

        Models/Item
        Models/Item/AgeItem
        Models/Item/AuthorizeItem
        Models/Item/HelloWorldItem
        Models/Item/LoginItem
        Models/Item/NameItem
        Models/Item/NewLetterItem
        Models/Item/NewLetterToItem
        Models/Item/PasswordItem
        Models/Item/ReceivedLetterFromItem
        Models/Item/ReceivedLettersItem
        Models/Item/RegisterItem
        Models/Item/SentLettersItem
        Models/Item/SentLetterToItem
        Models/Item/SignInItem
        Models/Item/SignUpItem
        Models/Item/SurnameItem

        Models/Iterator

        Models/Letter

        Models/Menu
        Models/Menu/AuthorizationMenu
        Models/Menu/AuthorizationMenu/SignInMenu
        Models/Menu/AuthorizationMenu/SignUpMenu
        Models/Menu/HelloWorldMenu
        Models/Menu/MainMenu
        Models/Menu/MainMenu/NewLetterMenu
        Models/Menu/MainMenu/ReceivedLettersMenu
        Models/Menu/MainMenu/SentLettersMenu

        Models/Tools/Color
        Models/Tools/Key

        Models/Vector
)

add_executable(
        Test main.cpp

        Models/Application/ApplicationManager.cpp

        Models/Client/Client.cpp
        Models/Client/Admin/Admin.cpp
        Models/Client/User/User.cpp

        Models/Database/DatabaseManager/DatabaseManager.cpp

        Models/Exception/Client/ClientException.cpp
        Models/Exception/Letter/LetterException.cpp

        Models/Item/Item.cpp
        Models/Item/AgeItem/AgeItem.cpp
        Models/Item/AuthorizeItem/AuthorizeItem.cpp
        Models/Item/HelloWorldItem/HelloWorldItem.cpp
        Models/Item/LoginItem/LoginItem.cpp
        Models/Item/NameItem/NameItem.cpp
        Models/Item/NewLetterItem/NewLetterItem.cpp
        Models/Item/NewLetterToItem/NewLetterToItem.cpp
        Models/Item/PasswordItem/PasswordItem.cpp
        Models/Item/ReceivedLetterFromItem/ReceivedLetterFromItem.cpp
        Models/Item/ReceivedLettersItem/ReceivedLettersItem.cpp
        Models/Item/RegisterItem/RegisterItem.cpp
        Models/Item/SentLettersItem/SentLettersItem.cpp
        Models/Item/SentLetterToItem/SentLetterToItem.cpp
        Models/Item/SignInItem/SignInItem.cpp
        Models/Item/SignUpItem/SignUpItem.cpp
        Models/Item/SurnameItem/SurnameItem.cpp

        Models/Letter/Letter.cpp

        Models/Menu/Menu.cpp
        Models/Menu/AuthorizationMenu/AuthorizationMenu.cpp
        Models/Menu/AuthorizationMenu/SignInMenu/SignInMenu.cpp
        Models/Menu/AuthorizationMenu/SignUpMenu/SignUpMenu.cpp
        Models/Menu/HelloWorldMenu/HelloWorldMenu.cpp
        Models/Menu/MainMenu/MainMenu.cpp
        Models/Menu/MainMenu/NewLetterMenu/NewLetterMenu.cpp
        Models/Menu/MainMenu/ReceivedLettersMenu/ReceivedLettersMenu.cpp
        Models/Menu/MainMenu/SentLettersMenu/SentLettersMenu.cpp

        Models/Tools/Color/Color.cpp
)