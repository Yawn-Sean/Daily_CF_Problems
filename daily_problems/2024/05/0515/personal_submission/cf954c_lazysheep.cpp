#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 5;
 
int a[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (n == 1) {
        cout << "YES" << '\n';
        cout << 1 << ' ' << a[0];
        return 0;
    }
    int c = -1;
    for (int i = 1; i < n; i++) {
        int x = abs(a[i] - a[i - 1]);
        if (x == 0) {
            cout << "NO";
            return 0;
        }
        if (x == 1) continue;
        if (c == -1)    c = x;
        else if (c != x) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 1; i < n; i++) {
        if (c == -1)    break;
        int x = abs(a[i] - a[i - 1]);
        if (x == 1) {
            int x = a[i], y = a[i - 1];
            if (x < y)  swap(x, y);
            if (y % c == 0) {
                cout << "NO";
                return 0;
            }
        }
    }
    if (c == -1) {
        cout << "YES" << '\n';
        cout << 1 << ' ' << mx;
        return 0;
    }
    int r = (mx + c - 1) / c;
    cout << "YES" << '\n';
    cout << r << ' ' << c;
 
 
    return 0;
}
