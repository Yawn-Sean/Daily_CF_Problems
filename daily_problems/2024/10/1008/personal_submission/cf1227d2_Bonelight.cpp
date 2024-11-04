/*
    Bonelight * v *
    20241008：国庆放假中~~
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

class Fenwick{
    public:
        int sz;
        vector<int> tr;
        Fenwick(int n): sz(n + 1), tr(sz){
        
        }

        void add(int idx, int val){
            for(int i = idx; i < sz; i += (i & -i)){
                tr[i] += val;
            }
        }

        int get(int idx){
            int res = 0;
            for(int i = idx; i >= 1; i -= (i & -i)) res += tr[i];
            return res;
        }

        int lower_bound(int k){
            int ans = 0, cnt = 0;
            for(int i = 20; i >= 0; i --){
                int ne = ans + (1ll << i);
                if(ne < sz && cnt + tr[ne] < k){
                    ans = ne;
                    cnt += tr[ne];
                }
            }
            return ans + 1;
        }
};


void solve(){
    int n; cin >> n;
    vector<pii> a(n + 1); 
    for(int i = 1; i <= n; i ++) {
        auto &[x,y] = a[i];
        cin >> x; 
        y = i;
    };
    vector<int> idx(n + 1); iota(begin(idx) , end(idx), 0ll);
    sort(begin(idx) + 1, end(idx), [&](int x, int y){
        return a[x].first != a[y].first? a[x].first > a[y].first: a[x].second < a[y].second;
    });
    Fenwick tr(n);

    int m; cin >> m;
    vector<array<int,3>> qs(m);
    for(int i = 0; i < m; i ++){
        auto &[x,y,id] = qs[i];
        cin >> x >> y;
        id = i;
    } 
    sort(begin(qs),end(qs));

    vector<int> ans(m);
    for(int i = 0, cnt = 0; i < m; i ++){
        auto &[x,y,id] = qs[i];
        while(cnt < x){
            tr.add(idx[++cnt], 1);
        }
        ans[id] = a[tr.lower_bound(y)].first;
    }
    for(int i = 0; i < m; i ++) cout << ans[i] << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
