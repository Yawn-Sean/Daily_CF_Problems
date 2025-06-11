#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    
    if (n == 0) {
        cout << "YES\n";
        cout << 1 << '\n';
        cout << 1 << '\n';
        cout << 3 << '\n';
        cout << 3 << '\n';
    } else if (n == 1) {
        // 给定一个
        cout << "YES\n";
        int x1 = a[0];
        int x2 = x1;
        int x3 = 4 * x1 - x2;
        int x4 = 3 * x1;
        cout << x2 << '\n';
        cout << x3 << '\n';
        cout << x4 << '\n';
    } else if (n == 2) {
        // 新加入一个数字 最大/最小的比值 不会变小
        // 原来的就已经超过了3就不可能了
        // x1 x2, 4x1-x2, 3x1
        int x = a[0], y = a[1];        
        if (3 * x >= y) {
            cout << "YES\n";
            cout << 3 * x << '\n';
            cout << 4 * x - y << '\n';
        } else {
            cout << "NO\n";
        }
    } else if (n == 3) {
        int x = a[0], y = a[1], z = a[2];
        if (z % 3 == 0 && (x + y) == 4 * (z / 3)) {
            // 第1类 剩下的数字是a1
            cout << "YES\n";
            cout << z / 3 << '\n';
        } else if (z == 3 * x) {
            // 第2类 剩下的数字是a2/a3
            cout << "YES\n";
            cout << 4 * x - y << '\n';
        } else if (3 * x >= z && y + z == 4 * x) {
            // 第3类 剩下的数字是a4
            cout << "YES\n";
            cout << 3 * x << '\n';
        } else {
            cout << "NO\n";
        }
    } else {
        if (a[0] * 3 == a[3] && a[1] + a[2] == a[0] * 4) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
