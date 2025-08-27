#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
typedef pair<int, int> PII;
const int N = 2000005, mod = 998244353;
vector<int> e[N];
string s;
int n;

bool check(int mid)
{
    mid = mid / 2 * 2;
    bool ok = false;
    vector<int> num(n + 1, 0);
    for (int i = 1; i <= n - mid / 2; i++)
    {
        int j = i + mid / 2;
        if (s[i] == s[j] || s[j] == '?' || s[i] == '?')
        {
            num[i] = 1;
        }
        num[i] += num[i - 1];
    }
    for (int i = 1; i <= n - mid + 1; i++)
    {
        int j = i + mid - 1;
        int l = i, r = mid / 2 + i;
        if (num[r - 1] - num[l - 1] >= mid / 2)
            // if (get_hash(i, r - 1, r, j))
            ok = true;
    }
    return ok;
}
void solve()
{

    cin >> s;
    n = s.size();
    s = " " + s;

    for (int i = n; i >= 1; i--)
    {
        if (i % 2 == 1)
            continue;
        if (check(i))
        {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;

    cin >> T;
    while (T--)
        solve();
    // cout << idx << endl;
    return 0;
}
