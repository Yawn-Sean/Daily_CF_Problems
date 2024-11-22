#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<array<int, 3>> circles(n);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 3; j ++) {
            cin >> circles[i][j];
        }
    }

    sort(circles.begin(), circles.end(), [&] (array<int, 3> x, array<int, 3> y) {return x[2] > y[2];});

    auto sqr = [&] (int x) -> long long {
        return 1ll * x * x;
    };

    auto isin = [&] (int x, int y) -> bool {
        return sqr(circles[x][0] - circles[y][0]) + sqr(circles[x][1] - circles[y][1]) <= sqr(circles[x][2] - circles[y][2]);
    };

    vector<int> times(n);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            if (isin(i, j)) {
                times[i] ++;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i ++)
        ans += sqr(circles[i][2]) * ((max(0, times[i] - 1) & 1) ? -1 : 1);

    cout << fixed << setprecision(20) << acosl(-1) * ans;

    return 0;
}