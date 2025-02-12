#include <iostream>

using namespace std;

int _1006(void)
{
    int n;
    cin >> n;
    char out[27];
    int count = 0;
    int d = 100;
    while (n != 0) {
        for (int i = n / d; i > 0; --i) {
            switch (d)
            {
            case 100:
                out[count++] = 'B';
                break;
            case 10:
                out[count++] = 'S';
                break;

            default:
                out[count++] = '1' + n / d - i;
                break;
            }
        }
        n = n % d;
        d /= 10;
    }

    for (int i = 0; i < count; ++i) {
        cout << out[i];
    }
    cout << endl;
    return 0;
}