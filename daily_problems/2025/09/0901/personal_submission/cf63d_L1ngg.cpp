#include <bits/stdc++.h>
void solve()
{
    int a, b, c, d; std::cin >> a >> b >> c >> d;
    int A = std::max(b, d), B = a + c;
    int n;  std::cin >> n;
    std::vector<int> num(n);
    for (int i = 0;i < n;i++)    std::cin >> num[i];
    std::vector<std::string> g(A, std::string(B, '.'));

    for (int i = 0;i < b;i++)
        for (int j = 0;j < a;j++)
            g[i][j] = '?';
    for (int i = 0;i < d;i++)
        for (int j = a;j < a + c;j++)
            g[i][j] = '?';

    int x, y, dx;
    if (a & 1) x = b - 1, y = 0, dx = -1;
    else x = 0, y = 0, dx = 1;

    int p = 0;
    for (int i = 0;i < a * b + c * d;i++) {
        if (!num[p]) p++;
        num[p]--;
        g[x][y] = 'a' + p;
        if (x + dx >= 0 && x + dx < A && g[x + dx][y] == '?') x += dx;
        else y++, dx = -dx;
    }
    std::cout << "YES\n";
    for (auto& x : g)   std::cout << x << '\n';
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