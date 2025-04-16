#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int _1010()
{
    int t;
    cin >> t;
    stringstream ss;
    vector<string> out;
    out.insert(vector::iterator)
    for (int i = 0; i < t; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        ss << "Case #" << i + 1 << ": " << ((a + b > c) ? "true" : "false") << endl;
    }
    cout << ss.str();
    return 0;
}
