#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int query(const string& s) {
    cout << "? " << s << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void print(const string& s) {
    cout << "! " << s;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string ans(n, '0');
    int l = 0, r = 0;
    string s(n, '0');
    for (int i = 0; i < n; i++) {
        s[i] = '1';
        if (query(s) == 1) {
            ans[i] = '1', r = i;
            break;
        }
    }
    s.assign(n, '0');
    for (int i = r; i >= 0; i--) {
        s[i] = '1';
        if (query(s) == 1) {
            ans[i] = '1', l = i;
            break;
        }
    }
    s.assign(n, '0');
    for (int i = l; i <= r; i++) {
        s[i] = '1';
    }
    for (int i = l + 1; i < r; i++) {
        s[i] = '0';
        if (!query(s)) {
            ans[i] = '1';
        }
        s[i] = '1';
    }

    s.assign(n, '0');
    for (int i = l; i <= r; i++) {
        if (ans[i] == '1') {
            s[i] = '1';
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == '1') {
            continue;
        }
        s[i] = '1';
        if (!query(s)) {
            ans[i] = '1';
        }
        s[i] = '0';
    }

    print(ans);
    return 0;
}