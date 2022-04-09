#include <iostream>
#include <string>

using namespace std;

void string_lower_upper(string &str);

int main()
{
    string str("abcDEF");

    string_lower_upper(str);

    cout << str << endl;

    return 0;
}

void string_lower_upper(string &str)
{
    int length = str.size();

    for(int i = 0; i < length; i++)
    {
        str.at(i) = tolower(str.at(i));
    }
}
