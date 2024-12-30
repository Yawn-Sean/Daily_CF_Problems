#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> pre(n + 1);
    int res = 0;
    for (int i = 1; i <= n; i ++ )
        if (s[i - 1] ^ 48)
            pre[i] = 0;
        else 
            pre[i] = pre[i - 1] + 1;

    for (int i = 0; i < n; i ++ ) {
        int msk = 0;
        for (int j = i; j >= 0 && i - j <= 18; j -- ) {
            if (s[j] ^ 48) {
                msk |= 1 << i - j;
                if (pre[j] + i - j + 1 >= msk)
                    res ++;
            }
        }
    }
    std::cout << res << '\n';
}


int main () {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_ --) 
        solve();
    return 0;
}