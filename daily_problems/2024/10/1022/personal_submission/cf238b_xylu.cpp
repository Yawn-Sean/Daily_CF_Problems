#include <bits/stdc++.h>
using namespace std;

void solveB() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    if (n == 2) {
        cout << "0\n1 2\n";
        return;
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    int diff1 = a[idx[n-1]] + a[idx[n-2]] - a[idx[0]] - a[idx[1]];
    int diff2 = max(a[idx[n-1]] + a[idx[n-2]], a[idx[n-1]] + a[idx[0]] + h) - min(a[idx[1]] + a[idx[2]], a[idx[0]] + a[idx[1]] + h);
    if (diff1 < diff2) {
        cout << diff1 << '\n';
        for (int i = 0; i < n; i++) {
            cout << "1 ";
        }
        cout << '\n';
    } else {
        cout << diff2 << '\n';
        for (int i = 0; i < n; i++) {
            if (i == idx[0]) cout << "1 ";
            else cout << "2 ";
        }
        cout << '\n';
    }
}

int main() {
    solveB();
    return 0;
}
