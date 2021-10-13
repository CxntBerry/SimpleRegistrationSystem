#include <iostream>
#include <fstream>
#include <string>

int input1;
std::string input2;
std::string input3;
std::string output1;

std::string encryptdecrypt(std::string text)
{
    char Key = 'D';
    std::string encrypted = text;
    for (int i = 0; i <= text.size(); i++)
    {
        encrypted[i] = text[i] ^ Key;
    }

    return encrypted;
}


int registeruser()
{
    std::cout << "Please enter a username: ";
    std::cin >> input2;
    std::cout << "Please enter a password: ";
    std::cin >> input3;
    input2 = input2 + ".txt";
    std::ifstream userfilecheck(encryptdecrypt(input2));

    if (userfilecheck)
    {
        std::cout << "\nSomeone already has that username!\n" << std::endl;
        return 0;
    }
    else
    {
        std::ofstream userfile(input2);
        userfile << encryptdecrypt(input3);
        userfile.close();
    }
}
int loginuser()
{
    std::cout << "Please enter a username: ";
    std::cin >> input2;
    std::cout << "Please enter a password: ";
    std::cin >> input3;
    input2 = input2 + ".txt";
    std::ifstream userfile(input2);
    while (std::getline(userfile, output1)) {
        if (output1 == encryptdecrypt(input3))
        {
            std::cout << "Successfully logged in as: " << input2 << std::endl;
        }
        else {
            std::cout << "Incorrect username or password." << std::endl;
            return 0;
        }
    }
    userfile.close();
    return 0;
}


int main()
{
    while (true) {
        std::cout << "1 to register, 2 to login." << std::endl;
        std::cin >> input1;
        if (input1 == 1)
        {
            registeruser();
        }
        else if (input1 == 2)
        {
            loginuser();
        }
        else
        {
            std::cout << "Invalid argument.";
            return 0;
        }
    }
}

