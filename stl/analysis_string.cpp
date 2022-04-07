#include <iostream>
#include <string>
#include <vector>

using namespace std;

// simple example
// - analysis word from website string and store words to vector
vector<string> AnalysisString(string &str);

int main()
{

    string str("www.baidu.com");

    vector<string> words = AnalysisString(str);

    for(auto it_begin = words.begin(); it_begin != words.end(); it_begin++)
        cout << *it_begin << endl;

    return 0;
}

vector<string> AnalysisString(string &str)
{
    vector<string> words_vector; 
    string temp_str;

    int position;
    int start = 0;

    while(1)
    {
        position = str.find('.', start);

        if(position == -1)
        {
            temp_str = str.substr(start, str.size()-start);
            words_vector.push_back(temp_str);
            break;
        }

        temp_str = str.substr(start, position - start);
        words_vector.push_back(temp_str);
        start = position + 1;
    }

    return words_vector;
}
