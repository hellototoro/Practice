#include <iostream>
#include <cmath>

using namespace std;

int _1007()
{
    int n;
    cin >> n;

    int counter = 0;
    if (n > 3) {
        for (int i = 3; i < n; i += 2) {//3 5 7 11 13 17
            int k = 3;
            int max = static_cast<int>(sqrt(i + 2));
            while (k <= max && (i + 2) <= n) {
                if (i % k == 0 || (i + 2) % k == 0) {//
                    break;
                }
                k += 2;
            }
            if (k > max)
                counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
