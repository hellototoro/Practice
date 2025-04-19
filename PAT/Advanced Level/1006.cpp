#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long time2s(string time);

int _1006()
{
    int n;
    cin >> n;
    long max = 0, min = 24*3600;
    vector<string> out;
    string first, last;
    for (int i = 0; i < n; ++i) {
        string id, start, end;
        cin >> id >> start >> end;
        /*
        CS301111 15:30:28 17:00:10
        SC3021234 08:00:00 11:25:25
        CS301133 21:45:00 21:58:40
        */
        long s = time2s(start);
        if (s < min) {
            first = id;
            min = s;
        }
        s = time2s(end);
        if (s > max) {
            last = id;
            max = s;
        }
    }

    cout << first << ' ' << last << endl;

    return 0;
}

long time2s(string time)
{
    size_t index = 0;
    long h = atoi(time.substr(0, 2).c_str());
    long m = atoi(time.substr(2, 2).c_str());
    long s = atoi(time.substr(4, 2).c_str());
    return s + m * 60 + h * 3600;
}