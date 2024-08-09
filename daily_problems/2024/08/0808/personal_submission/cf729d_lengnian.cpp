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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            int j = i;
            while (j + 1 < s.size() && s[j + 1] == '0')
                j++;
            res += (j - i + 1) / b;
            i = j;
        }
    }

    vector<int> x;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            int j = i;
            while (j + 1 < s.size() && s[j + 1] == '0')
                j++;
            int pos = i + b - 1;
            while (res >= a && pos <= j)
            {
                res--;
                x.pb(pos);
                pos += b;
            }
            i = j;
        }
    }

    cout << x.size() << "\n";
    for (auto dsak : x)
        cout << dsak + 1 << " ";
    cout << "\n";
    return 0;
}
