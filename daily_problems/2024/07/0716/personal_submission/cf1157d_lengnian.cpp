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
const int N = 200010;
int a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k == 3 && n == 8)
    {
        cout << "NO" << "\n";
        return 0;
    }
    if (k == 2 && n == 4)
    {
        cout << "NO" << "\n";
        return 0;
    }
    if (n < 1LL * k * (k + 1) / 2)
    {
        cout << "NO" << "\n";
        return 0;
    }

    int st = (n - k * (k - 1) / 2) / k;
    for (int i = 1; i <= k; i++)
    {
        a[i] = st + i - 1;
        n -= a[i];
    }
    for (int i = k; i >= 1; i--)
    {
        if (n == 0)
            break;
        a[i]++, n--;
    }
    if (a[1] == 1 && a[2] == 3)
        a[2]--, a[k]++;
    printf("YES\n");
    for (int i = 1; i <= k; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
