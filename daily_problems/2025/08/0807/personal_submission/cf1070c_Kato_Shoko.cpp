#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e6 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

struct Node {
    ll cnt;
    ll sum;
    Node(): cnt(0), sum(0) {}
};

struct SegmentTree {
    int n;
    vector<Node> t;
    int maxP;
    SegmentTree(int _maxP) {
        maxP = _maxP;
        t.assign(4 * (maxP + 1), Node());
    }
    void update(int u, int l, int r, int idx, ll dc) {
        if (l == r) {
            t[u].cnt += dc;
            t[u].sum += dc *(ll)idx;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) update(u<<1, l, mid, idx, dc);
        else           update(u<<1|1, mid+1, r, idx, dc);
        t[u].cnt = t[u<<1].cnt + t[u<<1|1].cnt;
        t[u].sum = t[u<<1].sum + t[u<<1|1].sum;
    }
    ll query_cnt(int u, int l, int r, int ql, int qr) {
        if (ql > qr || qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return t[u].cnt;
        int mid = (l + r) >> 1;
        return query_cnt(u<<1, l, mid, ql, qr)
             + query_cnt(u<<1|1, mid+1, r, ql, qr);
    }
    ll query_sum(int u, int l, int r, int ql, int qr) {
        if (ql > qr || qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return t[u].sum;
        int mid = (l + r) >> 1;
        return query_sum(u<<1, l, mid, ql, qr)
             + query_sum(u<<1|1, mid+1, r, ql, qr);
    }
    // 找最小 pos, 使得前缀 cnt >= k
    int kth(int u, int l, int r, ll k) {
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (t[u<<1].cnt >= k) return kth(u<<1, l, mid, k);
        else return kth(u<<1|1, mid+1, r, k - t[u<<1].cnt);
    }
};

il void solve(){
    ll n,k,m;
    cin>>n>>k>>m;
    struct P{
        ll l,r,c,p;
    };
    vector<P>p(m);
    ll maxP=0;
    for(auto &[l,r,c,p]:p){
        cin>>l>>r>>c>>p;
        maxP=max(maxP,p);
    }

    vector<vector<pair<ll,ll>>>event(n+2);
    for(auto [l,r,c,p]:p){
        event[l].push_back({c,p});
        event[r+1].push_back({-c,p});
    }
    SegmentTree st(maxP);
    ll cnt=0,ans=0;

    for(int day=1;day<=n;day++){
        for(auto [c,idx]:event[day]){
            cnt+=c;
            st.update(1,1,maxP,idx,c);
        }
        ll minn=min(k,cnt);
        if(minn<=0)continue;
        int pos=st.kth(1,1,maxP,minn);
        ll low_cnt=st.query_cnt(1,1,maxP,1,pos-1);
        ll low_sum=st.query_sum(1,1,maxP,1,pos-1);
        ll need=minn-low_cnt;
        ll sum=need*pos;
        ans+=low_sum+sum;
    }
    cout<<ans;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {
    
        solve();

    }

    return 0;
}
