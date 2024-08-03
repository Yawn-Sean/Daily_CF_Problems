#include <bits/stdc++.h>
using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    std::string s;
    std::cin >> s;
    i64 res = 0;
    int n = s.size();
    std::vector<int> r(n + 1, n);
    for (int i = n - 1; ~i; i -- ) {
        r[i] = r[i + 1];
        for (int j = 1; i + j * 2 < r[i]; j ++ )
            if (s[i] == s[i + j] && s[i] == s[i + 2 * j])
                r[i] = i + 2 * j;
        res += n - r[i];
    }
    std::cout << res;
    return 0;
}