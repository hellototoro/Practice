#include <iostream>
#include <string>
#include <map>

using namespace std;

int _1004(void)
{
    int n;
    map<int, string> out;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        string number;
        int mark;
        cin >> name >> number >> mark;
        out.insert({ mark,name + ' ' + number });
    }
    cout << (--out.end())->second << endl;
    cout << out.begin()->second << endl;
    return 0;
}