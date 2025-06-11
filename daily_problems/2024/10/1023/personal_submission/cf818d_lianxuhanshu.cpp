#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, k, color;

int a[N];
void solve()
{
    cin >> n >> color;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, int> cnt;
    int pos = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != color)
        {
            if (cnt.count(a[i]))
                cnt[a[i]]++;
            else
                cnt[a[i]] += 2;
        }
        else
        {
            pos = i;
            break;
        }
    }

    for (int i = pos; i <= n; i++)
    {
        if (a[i] == color)
        {
            for (auto it = cnt.begin(); it != cnt.end();)
            {
                it->second--;
                if (it->second == 0)
                {
                    auto It = it;
                    it++;
                    cnt.erase(It->first);
                }
                else
                    it++;
            }
        }
        else
        {
            if (cnt.count(a[i]))
                cnt[a[i]]++;
        }
    }

    if (cnt.size() == 0)
        cout << -1 << '\n';
    else
        cout << cnt.begin()->first << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
