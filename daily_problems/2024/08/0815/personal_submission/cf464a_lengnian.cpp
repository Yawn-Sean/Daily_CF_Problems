#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
int n, p;
string s;
bool check(int pos)
{
    if (pos == n)
        return true;
    for (; s[pos] - 'a' < p; ++s[pos])
    {
        if (pos && s[pos - 1] == s[pos])
            continue;
        if (pos > 1 && s[pos - 2] == s[pos])
            continue;
        if (check(pos + 1))
            return 1;
    }
    s[pos] = 'a';
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p;

    cin >> s;

    ++s[s.size() - 1];
    if (check(0))
    {
        cout << s << "\n";
    }
    else
    {
        puts("NO");
    }

    return 0;
}
