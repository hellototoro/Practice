#include <iostream>
#include <vector>
#include <algorithm>

int _1005(void)
{
    using namespace std;
    int k;
    cin >> k;
    int v_[100];
    for (int i = 0; i < k; ++i) {
        cin >> v_[i];
    }
    vector<int> out(v_, v_ + k);
    for (int i = 0; i < k; ++i) {
        int n = v_[i];
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            }
            else {
                n = (3 * n + 1) / 2;
            }
            auto it = find(out.begin(), out.end(), n);
            if (it != out.end()) {
                out.erase(it);
            }
        }
    }

    sort(out.begin(), out.end(), greater<int>());
    for (auto i = out.begin(); i != out.end(); ++i) {
        if (i != out.begin()) {
            cout << ' ';
        }
        cout << *i;
    }
    cout << endl;
    return 0;
}