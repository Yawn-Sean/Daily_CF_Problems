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

    int n;
    cin >> n;

    vector<int> cs(n), ps(n);
    
    for (int i = 0; i < n; i ++)
        cin >> cs[i] >> ps[i];
    
    int k;
    cin >> k;

    vector<int> rs(k);
    for (int i = 0; i < k; i ++)
        cin >> rs[i];
    
    vector<int> st_n(n), st_k(k);

    iota(st_n.begin(), st_n.end(), 0);
    iota(st_k.begin(), st_k.end(), 0);

    sort(st_n.begin(), st_n.end(), [&] (int i, int j) {return cs[i] < cs[j];});
    sort(st_k.begin(), st_k.end(), [&] (int i, int j) {return rs[i] < rs[j];});

    priority_queue<pair<int, int>> pq;
    vector<int> ans(n, -1);
    int tot = 0, cnt = 0, pt = 0;

    for (auto &i: st_k) {
        while (pt < n && cs[st_n[pt]] <= rs[i]) {
            pq.push({ps[st_n[pt]], st_n[pt]});
            pt ++;
        }

        if (!pq.empty()) {
            tot += pq.top().first;
            cnt ++;
            ans[pq.top().second] = i;
            pq.pop();
        }
    }

    cout << cnt << ' ' << tot << '\n';

    for (int i = 0; i < n; i ++) {
        if (ans[i] != -1) {
            cout << i + 1 << ' ' << ans[i] + 1 << '\n';
        }
    }

    return 0;
}