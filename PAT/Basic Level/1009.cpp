#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int _1009()
{
    string line;
    vector<int> out;

    // 读取整行输入
    getline(cin, line);
    stringstream ss(line);

    int a, b;
    while (ss >> a >> b) {
        if (b != 0) {
            out.push_back(a * b);
            out.push_back(b - 1);
        }
    }

    // 输出结果
    for (auto i = out.begin(); i != out.end(); ++i) {
        if (i != out.begin()) {
            cout << ' ';
        }
        cout << *i;
    }
    if (out.empty())
        cout << "0 0" << endl;

    return 0;
}
