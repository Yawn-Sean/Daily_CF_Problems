#include <bits/stdc++.h>
using namespace std;

struct team {
    long long balloons;
    long long weight;
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    long long x, y;
    cin >> x >> y;

    vector<team> teams(n - 1);

    for (int i = 0; i < n - 1; i ++) 
        cin >> teams[i].balloons >> teams[i].weight;
    
    sort(teams.begin(), teams.end(), [&] (team x, team y) {return x.balloons > y.balloons;});
    int pt = 0;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    while ((pt < n - 1) && (x < teams[pt].balloons)) {
        pq.push(teams[pt].weight - teams[pt].balloons + 1);
        pt += 1;
    }

    int ans = (int)pq.size();

    while (!pq.empty() && x >= pq.top()) {
        x -= pq.top();
        pq.pop();
        while ((pt < n - 1) && (x < teams[pt].balloons)) {
            pq.push(teams[pt].weight - teams[pt].balloons + 1);
            pt += 1;
        }
        ans = min(ans, (int)pq.size());
    }
    cout << ans + 1 << '\n';

    return 0;
}