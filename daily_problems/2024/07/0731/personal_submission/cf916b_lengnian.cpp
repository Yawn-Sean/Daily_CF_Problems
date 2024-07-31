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
const int N = 1e5 + 100;
int a[N], *cnt = a + 100000;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 60; i++)
    {
        cnt[i] += n >> i & 1;
        k -= cnt[i];
    }
    if (k < 0)
    {
        cout << "No" << "\n";
        return 0;
    }
    for (int i = 59; i >= -60; i--)
        if (k >= cnt[i])
        {
            k -= cnt[i];
            cnt[i - 1] += 2 * cnt[i];
            cnt[i] = 0;
        }
        else
        {
            int Min = -60;
            while (!cnt[Min])
                Min++;
            while (k--)
            {
                cnt[Min]--;
                cnt[--Min] += 2;
            }
            break;
        }
    cout << "Yes" << "\n";
    for (int i = 59; i >= -100000; i--)
        while (cnt[i]--)
            cout << i << " ";
    cout << "\n";
    return 0;
}
