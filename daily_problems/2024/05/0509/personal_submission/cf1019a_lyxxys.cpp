#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
const ll INF = 1e18;

void solve(){ 
    int n, m;
    cin >> n >> m;
    vector <int> p(n+1), cost(n+1);
    vector <Pii> dic;
    for (int i = 1; i <= n; ++ i)
        cin >> p[i] >> cost[i], dic.push_back({cost[i], i});
    sort(dic.begin(), dic.end(), greater<Pii>());
    ll res = INF;    //n次
    for (int x = 0; x <= n; ++ x){ //表示投票数政党1 大于x，非政党1 小于等于 x 的最花费
        ll vote = 0, sum = 0;
        vector <int> cnt(m+1), used(n+1);
        for (auto &it : dic){
            int i = it.second;
            if (p[i] != 1){
                if (cnt[p[i]] < x) ++ cnt[p[i]], used[i] = 1;
                else ++ vote, sum += cost[i];
            }
            else ++ vote;
        }

        for (int i = dic.size()-1; i >= 0; -- i){
            int k = dic[i].second;
            if (vote <= x && used[k])
                sum += cost[k], ++ vote;
        }
        res = min(sum, res);
    }

    cout << res << "\n";
}
