#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100050;
vector <vector<int>> g(N);

void solve(){
    int n, m;
    cin >> n >> m;
    while (m--){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    vector <int> leg(n+1), nums(n+1);
    for (int i = 1; i <= n; ++ i) cin >> leg[i];
    vector <int> ans;
    queue <int> Q;
    for (int i = 1; i <= n; ++ i)
        if (leg[i] == nums[i]) Q.push(i);

    while (!Q.empty()){
        int t = Q.front();
        Q.pop();
        if (leg[t] != nums[t]) continue;
        ans.push_back(t);
        nums[t] += 1;
        for (auto &x : g[t]){
            nums[x] += 1;
            if (nums[x]==leg[x]) Q.push(x);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++ i)
        cout << ans[i] << "\n "[i < ans.size()-1];
}
