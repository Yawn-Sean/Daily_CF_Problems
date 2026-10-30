#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        }
    }

    if (!cnt) {
        cout << n;
        return 0;
    }

    cnt = rgs::count(s, 'G');
    int ans = (cnt + (n - cnt) * 2) % 3;

    if (ans) {
        cout << 1;
    } else {
        cout << 2;
    }
    return 0;
}