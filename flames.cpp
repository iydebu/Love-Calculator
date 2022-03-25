#include <iostream>
using namespace std;
void remove_char(string &str, char c)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == c)
        {
            for (int j = i; j <= str.size(); j++)
            {
                str[j] = str[j + 1];
            }
            str.resize(str.size() - 1);
            break;
        }
    }
}
void flames(string boy, string girl)
{
    string love = "flames";
    for (int i = 0; i < boy.size(); i++)
    {
        for (int j = 0; j < girl.size(); j++)
        {
            if (boy[i] == girl[j])
            {
                remove_char(boy, boy[i]);
                remove_char(girl, girl[j]);
                break;
            }
        }
    }

    int love_number = boy.size() + girl.size();

    int count = 0;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= love_number; j++)
        {
            count++;
            if (count >= love.size())
                count = 0;
        }
        remove_char(love, love[count]);
    }
    switch (love[0])
    {
    case 'f':
        cout << "Friend" << endl;
        break;
    case 'l':
        cout << "Love" << endl;
        break;
    case 'a':
        cout << "Affair" << endl;
        break;
    case 'm':
        cout << "Marriage" << endl;
        break;
    case 'e':
        cout << "Enemy" << endl;
        break;
    case 's':
        cout << "Sex" << endl;
        break;
    }
}
int main()
{
    string boy, girl;
    cout << "Welcome to love calculator: " << endl
         << endl;
    cout << "Enter the name of Boy: ";
    cin >> boy;
    cout << "Enter the name of Girl: ";
    cin >> girl;
    cout << "Result: ";
    flames(boy, girl);
}