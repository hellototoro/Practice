#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int _1005()
{
    string n;
    cin >> n;
    long long i = 0;
    vector<string> digit{ "zero", "one", "two","three", "four", "five", "six", "seven", "eight", "nine" };
    for (auto& it : n) {
        char tmp = it;
        i += atoi(&tmp);
    }
    //cout << "i = " << i << endl;
    string res = to_string(i);
    for (const auto& it : res) {
        char tmp = it;
        cout << digit[atoi(&tmp)];
        if (*((&it) + 1) != '\0') {
            cout << '*';
        }
    }
    cout << endl;

    return 0;
}
