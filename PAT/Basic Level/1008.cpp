#include <iostream>
#include <cmath>

using namespace std;

void move1setp(int a[], int n)
{
    int tmp = a[n - 1];
    for (int i = 0; i < n - 1; ++i) {
        a[n - 1 - i] = a[n - 2 - i];
    }
    a[0] = tmp;
}

int _1008()
{
    int N, M;
    cin >> N >> M;
    int arr[100];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < M; ++i) {
        move1setp(arr, N);
    }
    for (int i = 0; i < N; ++i) {
        cout << arr[i];
        if (i != N - 1)
            cout << ' ';
    }
    cout << endl;
    return 0;
}
