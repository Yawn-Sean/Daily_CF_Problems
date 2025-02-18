#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    vector<int> vals(n), ts(n);
    for (int i = 0; i < n; i ++)
        cin >> vals[i] >> ts[i];
    
    int ans = 0, tot = 0;
    priority_queue<int> pq;

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&] (int i, int j) {return vals[i] > vals[j];});
    for (auto &i: order) {
        pq.push(ts[i]);
        tot += ts[i];
        if (tot > t) {
            tot -= pq.top();
            pq.pop();
        }
        ans = max(ans, min((int)pq.size(), vals[i]));
    }
    cout << ans << '\n';
    cout << ans << '\n';

    int cnt = 0;
    sort(order.begin(), order.end(), [&] (int i, int j) {return ts[i] < ts[j];});
    for (auto &i: order) {
        if (vals[i] >= ans && cnt < ans) {
            cnt ++;
            cout << i + 1 << ' ';
        }
    }

    return 0;
}