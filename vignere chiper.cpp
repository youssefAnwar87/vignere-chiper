#include <iostream>
#include <string>

using namespace std;

int encrypt(string text, string key)
{
    string fullKey;
    int sum;

    for (int i = 0; i != text.length(); i++) /* two for loops to captalize the word */
    {
        text[i] = toupper(text[i]);
    }
    for (int i = 0; i != key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }

    int i = 0;
    while (fullKey.length() != text.length()) /* while loop to repeat the entered key until it becomes eqaul to the text */
    {
        fullKey += key[i % key.length()];
        i += 1;
    }

    for (int i = 0; i < text.length(); i++) /*  to print anything as it is not alphaptical*/
    {
        if (!isalpha(text[i]) || text[i] == ' ')
        {
            cout << text[i];
            continue;
        }

        sum = text[i] + fullKey[i];
        sum = sum % 26;
        sum = sum + 65;
        cout << (char)sum;
    }
    cin >> text;
}

int decrypt(string text, string key)
{
    string fullKey;
    int sum, sum2;
    for (int i = 0; i != text.length(); i++) /* two for loops to captalize the word */
    {
        text[i] = toupper(text[i]);
    }
    for (int i = 0; i != key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }
    int i = 0;
    while (fullKey.length() != text.length()) /* while loop to repeat the entered key until it becomes eqaul to the text */
    {
        fullKey += key[i % key.length()];
        i += 1;
    }

    for (int i = 0; i < text.length(); i++) /*  to print anything as it is not alphaptical*/
    {
        if (!isalpha(text[i]))
        {
            cout << text[i];
            continue;
        }
        sum2 = text[i] - 65; /*  operations to decrypte */
        for (int j = 65; j <= 90; j++)
        {
            if ((j + fullKey[i]) % 26 == sum2)
            {
                cout << (char)j;
                break;
            }
        }
    }
    cin >> text;
    return 0;
}
int main()
{

    string choice;

    cout << "hello" << endl;
    cout << "1-Encrypt " << endl;
    cout << "2-decrypt " << endl;
    cout << "Enter 1 or 2: ";
    getline(cin, choice);
    while (true)
    {
        if (choice == "1")
        {
            break;
        }
        else if (choice == "2")
        {

            break;
        }
        else
        {
            cout << "please enter 1 or 2 : ";
            getline(cin, choice);
        }
    }

    string text, key;
    cout << "enter your text: ";
    getline(cin, text);
    cout << "enter your keyword: ";
    getline(cin, key);

    if (choice == "1")
    {
        encrypt(text, key);
    }
    else
    {
        decrypt(text, key);
    }
    return 0;
}
