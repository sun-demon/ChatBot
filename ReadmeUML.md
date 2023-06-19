---
title: ChatBot
---
classDiagram-v2
    ISerializable <|-- Client

    Client <|-- User
    Client <|-- Admin

    ISerializable <|-- Letter

    IConsumer <|-- Item

    AdminController <|-- DatabaseManager
    LetterController <|-- DatabaseManager
    UserController <|-- DatabaseManager

    DatabaseManager *-- Database

    ClientException <|-- LoginException
    ClientException <|-- PasswordException
    ClientException <|-- SurnameException
    ClientException <|-- NameException
    ClientException <|-- AgeException

    IRunnable <|-- Menu
    
    Item <--* Menu

    Item <|-- AgeItem
    Item <|-- AuthorizeItem
    Item <|-- LoginItem
    Item <|-- NameItem
    Item <|-- NewLetterItem
    Item <|-- NewLetterToItem
    Item <|-- PasswordItem
    Item <|-- ReceivedLetterFromItem
    Item <|-- ReceivedLettersItem
    Item <|-- RegisterItem
    Item <|-- SentLettersItem
    Item <|-- SentLettersToItem
    Item <|-- SignInItem
    Item <|-- SignUpItem
    Item <|-- SurnameItem

    Menu <|-- AuthorizationMenu
    Menu <|-- MainMenu
    MainMenu <|-- NewLetterMenu
    MainMenu <|-- ReceivedLettersMenu
    MainMenu <|-- SentLettersMenu

    class AuthorizationMenu {
        -login: string
        -password: string
        +getLogin(): string
        +setLogin(login: string)
        +getPassword(): string
        +setPassword(password: string)
    }

    class IRunnable {
        <<interface>>
        + run()
    }

    class Database {
        +nextUserID: int
        +nextAdminID: int
        +nextLetterID: int
        +users: Vector<User>
        +admins: Vector<Admin>
        +letters: Vector<Letter>
    }

    class Client {
        <<abstract>>
        -id: int
        -login: string
        -password: string
        -surname: string
        -name: string
        -age: string
        +getID(): Int
        +setID(id: int)
        +getLogin(): string
        +setLogin(login: string)
        +getPassword(): string
        +setPassword(password: string)
        +getSurname(): string
        +setSurname(surname: string)
        +getName(): string
        +setName(name: string)
        +getAge(): int
        +setAge(age: int)

        -checkLogin(login: string) 
        -isValidLogin(login: string)
    }

    class ISerializable {
        <<interface>>
        +serialize(out: ostream): ostream
        +deserialize(in: istream): istream
    }

    class User {
        +serialize(out: ostream): ostream
        +deserialize(in: istream): istream
    }

    class Admin {
        +serialize(out: ostream): ostream
        +deserialize(in: istream): istream
    }

    class AdminController {
        <<interface>>
        +insertAdmin(admin: Admin)
        +deleteAdminByID(id: int)
        +getAllAdmins(): Admin[]
        +getAdminByID(id: int): Admin
    }

    class UserController {
        <<interface>>
        +insertUser(user: User)
        +deleteUserByID(id: int)
        +getAllUsers(): User[]
        +getUserByID(id: int): User
    }

    class LetterController {
        <<interface>>
        +insertLetter(letter: Letter)
        +deleteLetterByID(id: int)
        +getAllLetters(): Letter[]
        +getLetterByID(id: int): Letter
    }

    class DatabaseManager {
        - database: Database
        - usersFileName: string
        - adminsFileName: string
        - lettersFileName: string
        + getInstance(): DatabaseManager
        - DatabaseManager(): DatabaseManager
        - usersSerialize(): void
        - adminsSerialize(): void
        - lettersSerialize(): void
        - usersDeserialize(): void
        - adminsDeserialize(): void
        - lettersDeserialize(): void
    }

    class IConsumer {
        <<interface>>
        +accept(Menu)
    }

    class Item {
        -name: string
        +getName(): string
        +setName(name: string)
    }

    class Menu {
        -name: string
        -items: Item[]
        -currentPosition: int
        -exceptionMessage: string
        +getException(): string
        +setException(message: string)
    }

    class MainMenu {
        -id: int
        +getUserID(): int
        +setUserID(id: int)
    }

    class SentLettersMenu {
        -letters: Vector<Letter>
        +getLetters(): Vector<Letter>
        +setLetters(letters: Vector<Letter>)
    }

    class ReceivedLettersMenu {
        -letters: Vector<Letter>
        +getLetters(): Vector<Letter>
        +setLetters(letters: Vector<Letter>)
    }

    class NewLetterMenu {
        -users: Vector<User>
        +getUsers(): Vector<User>
        +setUsers(letters: Vector<User>)
    }

    class Letter {
        -id: int
        -from: int
        -to: int 
        -message: string 
        -dateTime: long long

        -isValidMessage(message: string): bool
        -checkMessage(message: string)

        +getID(): int
        +setID(id: int)
    }