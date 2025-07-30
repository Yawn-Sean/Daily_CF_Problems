#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
typedef long long LL;
const int N = 7010, M = 350;
// 考虑建图
int n;
int st[N][2];
int cnt[N][2];
vector<int> se[2];
int mod(int x)
{
    return (x % n == 0 ? n : x % n);
}
void solve()
{
    cin >> n;
    int k1, k2;
    cin >> k1;
    for (int i = 1; i <= k1; i++)
    {
        cin >> k2;
        se[0].push_back(k2);
    }
    cin >> k2;
    for (int i = 1; i <= k2; i++)
    {
        cin >> k1;
        se[1].push_back(k1);
    }

    for (int i = 2; i <= n; i++)
    {
        cnt[i][0] = se[0].size();
        cnt[i][1] = se[1].size();
    }
    // cout << se[0].size() << ' ' << se[1].size() << endl;
    st[1][0] = st[1][1] = 2;
    queue<PII> q;
    q.push({1, 0});
    q.push({1, 1});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        int last = 1 - y;
        for (auto step : se[last])
        {
            int last_num = mod(x - step + n);
            if (last_num == 1)
                continue;
            if (st[last_num][last] != 0)
                continue;
            if (st[x][y] == 2)
            {
                st[last_num][last] = 1;
                q.push({last_num, last});
            }
            else
            {
                cnt[last_num][last]--;
                if (cnt[last_num][last] == 0)
                {
                    st[last_num][last] = 2;
                    q.push({last_num, last});
                }
            }
        }
    }
    string str[] = {"Loop", "Win", "Lose"};
    for (int j = 0; j <= 1; j++)
        for (int i = 2; i <= n; i++)
        {
            cout << str[st[i][j]] << " \n"[i == n];
        }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
