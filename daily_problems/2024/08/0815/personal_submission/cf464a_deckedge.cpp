#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int read() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    int n = read(), p = read(), idx = n - 1;
    cin >> a;
    auto is_vailed = [&](int i) -> bool {
        if (i >= 1 && a[i] == a[i - 1]) {
            return false;
        }
        if (i >= 2 && a[i] == a[i - 2]) {
            return false;
        }
        return true;
    };
    while (true) {
        if (idx == n) {
            cout << a << '\n';
            break;
        } else if (idx < 0) {
            cout << "NO\n"; 
            break;
        } else if (a[idx] - 'a' + 1 == p) {
            a[idx--] = 'a' - 1;
        } else {
            int cur = a[idx] - 'a' + 1;
            a[idx] = cur + 'a';
            if (is_vailed(idx)) {
                idx++;
            } 
        }
    }

    return 0;
}
