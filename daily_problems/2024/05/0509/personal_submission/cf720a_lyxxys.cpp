#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,array<int,2>>;
const int N = 1e4+11;
bool vis[N];

void solve(){ 
    int n, m, k;
    cin >> n >> m;
    vector <int> d;
    auto index = [&](int x, int y)->int{
        return m*(x-1) + y-1;
    };
    cin >> k;
    for (int i = 0, x; i < k; ++ i)
        cin >> x, d.push_back(x);
    sort(d.begin(), d.end());
    priority_queue <Pii> pque;
    for (int i = 0, j = 1; i < k; ++ i){
        while (j < d[i]){
            if (j <= m)
                for (int r = 1, c = j; r <= n && c > 0; ++ r, -- c)
                    pque.push({r+m+1-c, {r, c}});
            else 
                for (int r = j-m+1, c = m; r <= n && c > 0; ++ r, -- c)
                    pque.push({r+m+1-c, {r, c}});
            ++ j;
        }
        if (!pque.size()) return cout << "NO\n", void();
        auto top = pque.top();
        pque.pop();
        int r = top.second[0], c = top.second[1];
        vis[index(r, c)] = true;
    }
    d.clear();
    while (pque.size()) pque.pop();
    cin >> k;
    for (int i = 0, x; i < k; ++ i) cin >> x, d.push_back(x);
    sort(d.begin(), d.end());
    for (int i = 0, j = 1; i < k; ++ i){
        while (j < d[i]){
            if (j <= m){
                for (int r = 1, c = m-j+1; r <= n && c <= m; ++ r, ++ c){
                    if (vis[index(r, c)]) continue;
                    int d = r + c;
                    pque.push({d, {r, c}});
                }
            }
            else {
                for (int r = j-m+1, c = 1; r <= n && c <= m; ++ r, ++ c){
                    if (vis[index(r, c)]) continue;
                    int d = r + c;
                    pque.push({d, {r, c}});
                }
            }
            ++ j;
        }
        if (!pque.size()) return cout << "NO\n", void();
        auto top = pque.top();
        pque.pop();
        int r = top.second[0], c = top.second[1];
        vis[index(r, c)] = true;
    }

    cout << "YES\n";
}
