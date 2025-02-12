#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int _1002(void)
{
    int k;
    constexpr int line = 2;
    map<int, double> out;
    int exp;
    double coe;

    for (int i = 0; i < line; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> exp >> coe;
            auto p = out.find(exp);
            if (p == out.end()) {
                out.insert({ exp,coe });
            }
            else {//相同指数
                p->second += coe;
                if (p->second == 0) {//底数为零的情况
                    out.erase(exp);
                }
            }
        }
    }

    cout << out.size();
    for (auto i = out.rbegin(); i != out.rend(); i++) {
        cout << ' ' << i->first << ' ' << fixed << setprecision(1) << i->second;
    }
    cout << endl;
    return 0;
}
