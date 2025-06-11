// 0528
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = ssize(s);  
    i64 ret = 0;

    int r = n;
    for (int l = n - 1; l >= 0; --l) {
        for (int span = 1; span <= 10 && l + 2 * span < n; ++span) {
            if (s[l] == s[l + span] && s[l] == s[l + 2 * span]) {
                r = min(r, l + 2 * span);
                break;
            }
        }
        ret += n - r;
    }
    cout << ret << endl;

    return 0;
}