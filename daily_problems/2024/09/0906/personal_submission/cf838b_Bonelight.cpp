#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

struct Edge {
    int y,w;
};

struct Tree {
    #define fa (o >> 1)
    #define ls (o << 1)
    #define rs (o << 1 | 1)
    vector<int> deep, Min, Tag;
    vector<int> up;
    void pull(int o){
        Min[o] = min(Min[ls], Min[rs]);
    }
    void apply(int o, int tag){
        Tag[o] += tag, Min[o] += tag;
    }
    void push(int o){
        apply(ls,Tag[o]), apply(rs, Tag[o]);
        Tag[o] = 0;
    }


    Tree(){}
    Tree(vector<int> &in_up, vector<int> &in_dist, vector<int> &id, int n): up(4 * n), deep(4 * n), Min(4 * n), Tag(4 * n){
        function<void(int,int,int)> build = [&](int o, int l, int r){
            if(l == r){
                up[o] = in_up[id[l]];
                deep[o] = in_dist[id[l]];
                Min[o] = up[o] + deep[o];
                return;
            }
            int mid = l + r >> 1;
            build(ls,l,mid), build(rs,mid + 1, r);
            pull(o);
        }; build(1,1,n);
    }

    void modify1(int o, int l, int r, int L, int R, int val){
        assert(l <= r); 
        if(L <= l && r <= R){
            apply(o,val);
            return;
        }
        if(Tag[o]) push(o);
        int mid = l + r >> 1;
        if(mid >= L) modify1(ls, l, mid, L, R, val);  
        if(mid + 1 <= R) modify1(rs, mid + 1, r, L, R, val);  
        pull(o);
    }

    void modify2(int o, int l, int r, int tar, int val){
        assert(l <= r);
        if(l == r){
            up[o] += val;
            Min[o] = up[o] + deep[o] + Tag[o];
            return;
        } 
        if(Tag[o]) push(o);
        int mid = l + r >> 1;
        if(mid >= tar) modify2(ls, l, mid, tar, val);  
        else modify2(rs, mid + 1, r, tar, val);  
        pull(o);
    }

    int query(int o, int l, int r, int L, int R){
        assert(l <= r);
        if(L <= l && r <= R){
            return Min[o];
        }
      
        if(Tag[o]) push(o);
        int mid = (l + r) >> 1;
      
        int mi = 2e18;
        if(mid >= L) mi = query(ls, l, mid, L, R);
        if(mid < R) mi = min(mi, query(rs, mid + 1, r, L, R));
        return mi;
    }

    int find(int o, int l, int r, int tar){
        assert(l <= r);
        if(l == r){
            return deep[o] + Tag[o];
        }
        if(Tag[o]) push(o);
        int mid = l + r >> 1;
        if(mid >= tar) return find(ls, l, mid, tar);
        return find(rs, mid + 1, r, tar); // else
    }
};

void solve()
{
    int n,q; cin >> n >> q;
    vector<vector<Edge>> g(n + 1);
    vector<int> L(n + 1), R(n + 1), up(n + 1), id(n + 1);
    vector<int> dist(n + 1);
    vector<array<int, 3>> edge(2 * n - 1);
    for(int i = 0; i < n - 1; i ++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        // g[b].push_back({a,c});
        edge[i + 1] = {a,b,c};
    }

    int tot = 0;
    function<void (int)> dfs = [&](int o){
        L[o] = ++ tot;
        id[tot] = o;
        for(auto [p,w]:g[o]){
            dist[p] = dist[o] + w;
            dfs(p);
        }
        R[o] = tot;
    }; dfs(1);
    
    assert(tot == n);

    for(int i = 0; i < n - 1; i ++){
        int a,b,c;
        cin >> a >> b >> c;
        up[a] = c;
        edge[n + i] = {a,b,c};
    }

    Tree tr(up, dist, id, n);
    // for(int i = 0; i <= n; i ++) cout << L[i] << ' ';
    // cout << endl; 
    // for(int i = 0; i <= n; i ++) cout << R[i] << ' ';
    // cout << endl; 
    while(q --){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            auto &[u,v,w] = edge[x];
            if(x <= n - 1){
                if(L[u] > L[v]) swap(u,v);
                tr.modify1(1, 1, n, L[v], R[v], y - w);
            }
            else {
                assert(v == 1);
                tr.modify2(1, 1, n, L[u], y - w);
            }
            w = y;
        } 
        else {
            int dx = tr.find(1, 1, n, L[x]);
            int dy = tr.find(1, 1, n, L[y]);
            if(L[x] <= L[y] && L[y] <= R[x]){
                cout << dy - dx << endl;
            } else {
                int mi = tr.query(1,1,n, L[x], R[x]);
                cout << mi + dy - dx << endl;
            }
        }
    }
}


signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
