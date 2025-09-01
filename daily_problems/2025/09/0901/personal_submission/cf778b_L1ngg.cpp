#include <bits/stdc++.h>

using a3 = std::array<int, 3>;
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> f(n + 1);
    std::map<std::string, int> mp;
    std::vector val(n + 1, std::vector<int>(m + 1));
    mp["?"] = 0;
    std::vector<a3> op(n + 1);
    for (int i = 1;i <= n;i++) {
        std::string s;  std::cin >> s;
        mp[s] = i;
        std::cin >> s >> s;
        if (s[0] == '0' || s[0] == '1') {
            for (int j = 1;j <= m;j++)
                val[i][j] = s[j - 1];
        }
        else {
            f[i] = 1;
            op[i][0] = mp[s];

            std::cin >> s;
            if (s[0] == 'X') op[i][1] = 0;
            else if (s[0] == 'O') op[i][1] = 1;
            else op[i][1] = 2;

            std::cin >> s;
            op[i][2] = mp[s];
        }
    }
    std::string ans1, ans2;
    for (int i = 1;i <= m;i++) {
        int c0 = 0, c1 = 0;
        std::vector<int> now0(n + 1), now1(n + 1);
        for (int j = 1;j <= n;j++) {
            if (f[j]) {
                auto [x, o, y] = op[j];
                int x0 = (x ? now0[x] : 0);
                int x1 = (x ? now1[x] : 1);

                int y0 = (y ? now0[y] : 0);
                int y1 = (y ? now1[y] : 1);

                if (o == 0) now0[j] = x0 ^ y0, now1[j] = x1 ^ y1;
                else if (o == 1)  now0[j] = x0 | y0, now1[j] = x1 | y1;
                else  now0[j] = x0 & y0, now1[j] = x1 & y1;

            }
            else now0[j] = now1[j] = val[j][i];

            c0 += now0[j], c1 += now1[j];
        }
        if (c0 <= c1) ans1 += "0";
        else ans1 += "1";

        if (c0 >= c1) ans2 += "0";
        else ans2 += "1";
    }
    std::cout << ans1 << '\n' << ans2;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}