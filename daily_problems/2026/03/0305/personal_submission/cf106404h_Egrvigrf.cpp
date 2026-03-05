#include <bits/stdc++.h>
using namespace std;
#define int long long

struct nd {
    int id, t;
};

struct path {
    int to, w, lim;
    path(int x, int y, int z = 1e18):to(x), w(y), lim(z) {}
};  

struct node {
    int t, id;
    node(int a, int b): t(b), id(a) {}
    bool operator < (const node& b) const {
        return t < b.t;
    }

    bool operator > (const node& b) const {
        return t > b.t;
    }
};  

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<path>> G(n+1);

    vector<nd> er(n+1);
    vector<int> erupt_t(n+1,1e18);
    // vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> erupt_t[i];
        er[i].t = erupt_t[i];
        er[i].id = i;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        G[u].push_back(path(v,cost));
        G[v].push_back(path(u,cost));
    }

    sort(er.begin(),er.end(),[](nd x, nd y) {
        return x.t < y.t;
    });

    priority_queue<node, vector<node>, greater<node>> T;
    for (int i = 1; i <= n; i++) {
        T.push(node(i,erupt_t[i]));
    }

    while (T.size()) {
        node cur = T.top();
        T.pop();
        if (cur.t > erupt_t[cur.id]) continue;
        for (auto i : G[cur.id]) {
            if (cur.t + i.w < erupt_t[i.to]) {
                erupt_t[i.to] = cur.t + i.w;
                T.push(node(i.to,erupt_t[i.to]));
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << erupt_t[i] << endl;
    // }

    // for (int i = 1; i <= n; i++) {
    //     for (auto& j : G[er[i].id]) {
    //         j.lim = min(er[i].t,a[j.to]);
    //     }
    // }

    priority_queue<node, vector<node>, greater<node>> q;
    vector<int> dis(n+1,1e18);

    if (erupt_t[1] >= 0) {
        dis[1] = 0;
        q.push(node(1, 0));
    }

    // q.push(node(1,0));
    
    while (q.size()) {
        node cur = q.top();
        q.pop();
        if (cur.t > dis[cur.id]) continue; 
        for (auto i : G[cur.id]) {
            if (cur.t + i.w <= min(dis[i.to],erupt_t[i.to])) {
                dis[i.to] = cur.t + i.w;
                q.push(node(i.to,cur.t + i.w));
            }
        }
    }
    
    if (erupt_t[n] < dis[n] && dis[n] <= 1e18) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
       solve();
    }
    return 0;
}