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

const int N = 100000;

double dist(double a, double b, double c, double d)
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(8);

    long long ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    int n;
    cin >> n;

    double sum = 0.0;
    multiset<double> saves;
    double x[N], y[N], save[N];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        sum += 2 * dist(tx, ty, x[i], y[i]);
        save[i] = dist(bx, by, x[i], y[i]) - dist(tx, ty, x[i], y[i]);
        saves.insert(save[i]);
    }

    double ans = sum + *saves.begin();
    saves.insert(0.0);

    for (int i = 0; i < n; i++)
    {
        saves.erase(saves.find(save[i]));
        ans = min(ans, sum - dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]) + *saves.begin());
        saves.insert(save[i]);
    }

    cout << ans << "\n";
}
