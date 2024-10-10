/*
    Bonelight * V *
    20241009: CF BOOM~
    No Coding, No Bug 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14

class Tree{
    #define ls (o << 1)
    #define rs (o << 1 | 1)
    public:
        int n;
        vector<int> mxs,add;
        void pull(int o){
            mxs[o] = max(mxs[ls], mxs[rs]);
        }
        void push(int o, int l, int r){
            int mid = l + r >> 1;
            apply(ls,l,mid,add[o]), apply(rs,mid + 1, r, add[o]);
            add[o] = 0;
        }
        void apply(int o, int l, int r, int ad){
            mxs[o] += ad;
            add[o] += ad;
        }

        Tree(){}
        Tree(int n_, vector<int> &a): n(n_), mxs(n * 4, -INF), add(n * 4){
            function<void(int,int,int)> build = [&](int o, int l, int r){
                if(l == r) { mxs[o] = a[l - 1]; return;}
                int mid = l + r >> 1;
                build(ls,l,mid), build(rs,mid + 1,r);
                pull(o);
            }; build(1,1,n);
        }

        void modify(int o, int l, int r, int L, int R, int val){
            assert(l <= r);
            if(L > R) return;
            if(L <= l && r <= R){
                apply(o,l,r,val);
                return;
            }
            push(o,l,r);
            int mid = l + r >> 1;
            if(L <= mid) modify(ls, l, mid, L, R, val); 
            if(mid + 1 <= R) modify(rs, mid + 1, r, L, R, val);
            pull(o);
        }

        int query(int o, int l, int r, int L, int R){
            assert(l <= r && L <= R);
            if(L <= l && r <= R){
                return mxs[o];
            }
            push(o,l,r);
            int res = -INF;
            int mid = l + r >> 1;
            if(L <= mid) res = max(res,query(ls, l, mid, L, R)); 
            if(mid + 1 <= R) res = max(res, query(rs, mid + 1, r, L, R));
            return res;
        }

        void print(){
            for(int i = 1; i < (1 << n); i ++){
                cout << i << ' ' << mxs[i] << ' ' << add[i]<< endl; 
            }
            cout << endl;
        }
};

void solve(){
    int n,m,p; cin >> n >> m >> p;
    vector<int> a1(n),b1(m),ac(n),bc(m);
    vector<int> a2(p),b2(p),c2(p);
    for(int i = 0; i < n; i ++)  cin >> a1[i] >> ac[i]; // a1 -- a2
    for(int i = 0; i < m; i ++)  cin >> b1[i] >> bc[i]; // b1 -- b2 
    for(int i = 0; i < p; i ++)  cin >> a2[i] >> b2[i] >> c2[i];

    vector<int> vb = b1; sort(begin(vb),end(vb));
    vb.erase(unique(begin(vb), end(vb)), end(vb));
    
    int k = vb.size();
    map<int,int> mp;
    for(int i = 0; i < k; i ++) mp[vb[i]] = i;
    
    vector<int> be_tr(k, -INF);
    for(int i = 0; i < m; i ++){
        be_tr[mp[b1[i]]] = max(be_tr[mp[b1[i]]], -bc[i]);
    }
    Tree tr = Tree(k, be_tr);

    vector<int> idx1(n), idx2(p); iota(begin(idx1),end(idx1),0), iota(begin(idx2),end(idx2),0);
    sort(begin(idx1), end(idx1), [&](int x, int y){return a1[x] < a1[y];});
    sort(begin(idx2), end(idx2), [&](int x, int y){return a2[x] < a2[y];});    

    int cur = 0, ans = -INF;
    // tr.print();
    for(auto i:idx1){
        while(cur < p && a1[i] > a2[idx2[cur]]){
            int l = -1, r = k;
            while(l + 1 < r){
                int mid = l + r >> 1;
                if(vb[mid] > b2[idx2[cur]]) r = mid;
                else l = mid;
            }
            // cout << l << "---" << k << endl;
            tr.modify(1,1,k,l+2,k,c2[idx2[cur]]);
            // tr.print();
            cur ++;
        }
        ans = max(ans, tr.query(1,1,k,1,k) - ac[i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
