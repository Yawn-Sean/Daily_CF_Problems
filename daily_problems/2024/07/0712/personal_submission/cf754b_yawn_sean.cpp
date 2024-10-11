#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> ls(n), rs(n);
    for (int i = 0; i < n; i ++)
        cin >> ls[i] >> rs[i];
    
    vector<int> sorted_range(n);
    iota(sorted_range.begin(), sorted_range.end(), 0);
    sort(sorted_range.begin(), sorted_range.end(), [&] (int i, int j) {return ls[i] < ls[j];});

    int ans = -1, chosen_l = -1;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto &i: sorted_range) {
        pq.push(rs[i]);
        if (pq.size() > k) pq.pop();
        if (pq.size() == k && pq.top() - ls[i] > ans)
            ans = pq.top() - ls[i], chosen_l = ls[i];
    }

    if (ans == -1) {
        cout << ans + 1 << '\n';
        for (int i = 1; i <= k; i ++) cout << i << ' ';
    }

    else {
        cout << ans + 1 << '\n';
        for (int i = 0; i < n; i ++)
            if (k && ls[i] <= chosen_l && rs[i] >= chosen_l + ans)
                k --, cout << i + 1 << ' ';
    }

    return 0;
}