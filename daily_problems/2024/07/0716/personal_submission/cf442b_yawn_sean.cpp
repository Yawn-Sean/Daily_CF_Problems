#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<double> probs(n);
    for (auto &prob: probs) cin >> prob;
    
    sort(probs.begin(), probs.end(), [&](double x, double y) {return x > y;});

    double p0 = 1, p1 = 0, ans = 0;

    for (auto &prob: probs)
        p1 = p1 * (1 - prob) + p0 * prob, p0 *= 1 - prob, ans = max(ans, p1);

    cout << setprecision(15) << ans;

    return 0;
}