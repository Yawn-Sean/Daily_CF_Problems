#include <bits/stdc++.h>
using namespace std;
const int N = 15000000;

void solve(){
    int n, b;
    cin >> n >> b;
    vector <long long> ans(n, -1);
    vector <array<int,2>> p(n);
    for (auto &it : p) cin >> it[0] >> it[1];
    
    queue <int> Q;
    long long cur = p[0][0] + p[0][1];
    ans[0] = cur;
    for (int i = 1; i < n; ++ i){
        auto &it = p[i];
        if (Q.size() < b && it[0] < cur) Q.push(i);
        else if (it[0] >= cur){
            while (!Q.empty() && it[0] >= cur){
                auto pj = p[Q.front()];
                cur = max(1ll*pj[0], cur);
                cur += pj[1];
                ans[Q.front()] = cur;
                Q.pop();
            }
            Q.push(i);
        }
    }
    while (!Q.empty()){
        auto pj = p[Q.front()];
        cur = max(1ll*pj[0], cur);
        cur += pj[1];
        ans[Q.front()] = cur;
        Q.pop();
    }

    for (auto &x : ans) cout << x << " ";
    cout << "\n";
}
