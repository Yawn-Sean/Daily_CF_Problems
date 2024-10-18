#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1e5+5, inf = 1e9, mod = 998244353;
struct segTree {
    vector<int> tr;
    segTree(){}
    segTree(int n): tr(2*(1<<(32-__builtin_clz(n)))){}
    void build(int o, int l, int r, vector<int>&last){
        if (l == r){
            if (last[l]) tr[o] = l-last[l];
            else tr[o] = inf;
            return;
        }
        int mid = l+r >> 1;
        build(o*2, l, mid, last), build(o*2+1, mid+1, r, last);
        tr[o] = min(tr[o*2], tr[o*2+1]);
    }
    void modify(int o, int l, int r, int pos, int v){
        if (l == r){
            tr[o] = v;
            return;
        }
        int mid = l+r >> 1;
        if (pos <= mid) modify(o*2, l, mid, pos, v);
        else modify(o*2+1, mid+1, r, pos, v);
        tr[o] = min(tr[o*2], tr[o*2+1]);
    }
    int query(int o, int l, int r, int L, int R){
        if (l >= L && r <= R){
            return tr[o];
        }
        int mid = l+r >> 1, res = inf;
        if (L <= mid) res = min(res, query(o*2, l, mid, L, R));
        if (R > mid) res = min(res, query(o*2+1, mid+1, r, L, R));
        return res;
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> a(n+1), last(n+1), next(n+1);
    map<int,int> mp;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        if (mp[a[i]] != 0) last[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    mp.clear();
    for (int i = n; i >= 1; -- i){
        if (mp[a[i]] != 0) next[i] = mp[a[i]];
        else next[i] = n+1;
        mp[a[i]] = i;
    }

    vector<array<int,3>> qys;
    for (int i = 1; i <= m; ++ i){
        int l, r;
        cin >> l >> r;
        qys.push_back({l, r, i});
    }
    sort(qys.begin(), qys.end(), [&](array<int,3> &a, array<int,3> &b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    int len = qys.size()-1;

    static segTree bx(n+1);
    bx.build(1,1,n,last);
    vector<int> ans(m+1);

    for (int i = 0; i <= len; ++ i){
        int l = qys[i][0], r = qys[i][1];
        int v = bx.query(1,1,n,l,r);
        ans[qys[i][2]] = (v==inf ? -1 : v);
        if (i != len){
            for (int j = l; j <= qys[i+1][0]-1; ++ j){
                if (next[j] != n+1 && next[j] >= qys[i+1][0]){
                    bx.modify(1,1,n,next[j],inf);
                }
            }
        }
    }

    for (int i = 1; i <= m; ++ i) cout << ans[i] << "\n";
}
