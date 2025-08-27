#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    std::string s;  std::cin >> s;
    int n = s.length();
    s = " " + s;
    int ans = 0;
    for (int len = 2;len <= n;len += 2) {
        int d = len / 2;
        int cnt = 0;
        for (int i = 1;i <= d;i++)
        {
            if (s[i] == '?' || s[i + d] == '?') cnt++;
            else if (s[i] == s[i + d]) cnt++;
        }
        if (cnt == d) {
            ans = len;
            continue;
        }
        for (int i = 1;i <= n - len;i++)
        {
            int r = i + len;
            if (s[i] == '?' || s[i + d] == '?') cnt--;
            else if (s[i] == s[i + d]) cnt--;

            if (s[r] == '?' || s[r - d] == '?') cnt++;
            else if (s[r] == s[r - d]) cnt++;
            if (cnt == d) {
                ans = len;
                break;
            }
        }
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}