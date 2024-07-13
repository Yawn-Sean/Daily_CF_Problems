#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 200050, mod = 1e9 + 7, inf = 1e9;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<Pii> segs(n+1), A(n+1);
    for (int i = 1, x,y; i <= n; ++ i){
        cin >> x >> y;
        A[i] = {x, y};
        segs[i] = {x, y};
    }
    sort(segs.begin()+1, segs.end());

    priority_queue<int,vector<int>,greater<int>> pq;
    int res = -1, lp;
    for (int i = 1; i <= n; ++ i){
        while (!pq.empty() && pq.top() < segs[i].first) pq.pop();
        pq.push(segs[i].second);
        if (pq.size() == k){
            int sum = pq.top()-segs[i].first+1;
            if (sum > res){
                res = sum;
                lp = segs[i].first;
            }
            pq.pop();
        }
    }

    if (res == -1){
        cout << 0 << "\n";
        for (int i = 1; i <= k; ++ i) cout << i << " ";
        cout << "\n";
    } else {
        cout << res << "\n";
        vector <int> ids;
        for (int i = 1, cnt = 0; i <= n; ++ i){
            if (A[i].first <= lp && A[i].second >= lp+res-1){
                ++ cnt;
                ids.push_back(i);
                if (cnt == k) break;
            }
        }
        for (auto &x : ids) cout << x << " ";
        cout << "\n";
    }
}
