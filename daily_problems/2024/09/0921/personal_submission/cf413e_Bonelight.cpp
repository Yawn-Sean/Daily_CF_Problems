#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14

class P
{
    public:
        int uu,ud,du,dd;
        P(int a, int b, int c, int d): uu(a),ud(b),du(c),dd(d){}
};
class Tree{
#define ls (o << 1)
#define rs (o << 1 | 1)
    public:
        vector<P> tr;
        
        P merge(P a, P b){
            P res(0,0,0,0);
            auto &[uu,ud,du,dd] = res;
            auto &[uu_a,ud_a,du_a,dd_a] = a;
            auto &[uu_b,ud_b,du_b,dd_b] = b;
            uu = min(uu_a + uu_b, ud_a + du_b) + 1;
            ud = min(uu_a + ud_b, ud_a + dd_b) + 1;
            du = min(dd_a + du_b, du_a + uu_b) + 1;
            dd = min(dd_a + dd_b, du_a + ud_b) + 1;

            uu = min(uu,INF);
            ud = min(ud,INF);
            du = min(du,INF);
            dd = min(dd,INF);
            return res;
        }

        Tree(){};
        Tree(int n, string a, string b): tr(4 * n, P(0,0,0,0)) {// 向右/上下
            function<void(int,int,int)> build = [&](int o, int l, int r){
                if(l == r){
                    auto &[uu,ud,du,dd] = tr[o];
                    ud = du = 1;
                    if(a[l] == 'X') uu = ud = du = INF;
                    if(b[l] == 'X') dd = ud = du = INF;
                    return;
                }
                int mid = l + r >> 1;
                build(ls,l,mid), build(rs,mid + 1,r);
                tr[o] = merge(tr[ls], tr[rs]);
            }; build(1,1,n);
        };

        P query(int o, int l, int r, int L, int R){
            // assert(L <= R);
            // assert(l <= r);
            if(L <= l && r <= R){
                return tr[o];
            }
            int mid = l + r >> 1;
            if(!(L <= mid)) return query(rs, mid + 1, r, L, R);
            if(!(mid + 1 <= R)) return query(ls, l, mid, L, R);
            return merge(query(ls,l,mid,L,R), query(rs, mid + 1, r, L, R));
        }
};

void solve()
{
    int n,q; cin >> n >> q;
    string a,b; cin >> a >> b;
    a = " " + a, b = " " + b;
    Tree tr(n,a,b);
    while(q --){
        int l,r; cin >> l >> r;
        int ly = 0, ry = 0;
        if(l > n) l -= n, ly = 1;
        if(r > n) r -= n, ry = 1;

        if(l > r) swap(l,r), swap(ly,ry);
        P pp = tr.query(1,1,n,l,r);
        auto [uu,ud,du,dd] = pp;

        int ans;
        if(!ly && !ry){
            ans = uu;
        } else if(!ly && ry){
            ans = ud;
        } else if(ly && !ry){
            ans = du;
        } else {
            ans = dd;
        }
        cout << (ans >= INF? -1:ans) << endl;
    }
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
