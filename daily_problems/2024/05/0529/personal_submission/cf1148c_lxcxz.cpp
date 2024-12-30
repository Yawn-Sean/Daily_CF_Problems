#include <bits/stdc++.h>
using i64 = long long;
typedef std::pair<int, int> pii;
#define N 300100
int a[N], b[N];
int t;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int res = 0;
    std::cin >> n;
    std::vector<int> l, r;
    std::vector<int> m(n + 100), mp(n + 100);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], m[a[i]] = i;
    auto cal = [&](int x, int y)
    {
        int X = a[x], Y = a[y];
        m[X] = y, m[Y] = x;
        std::swap(a[x], a[y]);
        l.push_back(x), r.push_back(y);
    };
    //很明显1，n当做中介，前面的和n换后面的和1，
    //前一半小于n/2和n否则和1
    //后一半小于n/2，和1否则是n
    
    //注意特判1n
    for (int i = 2; i <= n / 2; i++)
    {
        if (m[i] <= n / 2)
        {
            cal(m[i], n);
            cal(n, i);
        }
        else
        {
            cal(m[i], 1);
            cal(1, n);
            cal(i, n);
        }
    }
    for (int i = n / 2 + 1; i < n; i++)
    {
        if (m[i] <= n / 2)
        {

            cal(m[i], n);
            cal(1, n);
            cal(1, i);
        }
        else
        {
            cal(m[i], 1);
            cal(1, i);
        }
    }
        if (m[1] != 1)
            cal(1, n);
        // for (int i = 1; i <= n; i++)
        //     std::cout << m[i] << " ";
        std::cout << l.size() << "\n";
        for (int i = 0; i < l.size(); i++)
            std::cout << l[i] << " " << r[i] << "\n";
        return 0;
    }
