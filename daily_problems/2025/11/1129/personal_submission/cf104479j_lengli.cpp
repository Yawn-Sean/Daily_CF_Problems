#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 mod = 998244353;

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n):n(n),f(n+1,0){}
    void add(int i,int v){ for(++i;i<=n;i+=i&-i) f[i]+=v; }
    int sum(int i){ int s=0; for(++i;i>0;i-=i&-i) s+=f[i]; return s; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<vector<int>> lsts(n);
    vector<int> vals;

    for(int i=0;i<n;i++){
        int k; cin>>k;
        lsts[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>lsts[i][j];
            vals.push_back(lsts[i][j]);
        }
        sort(lsts[i].begin(), lsts[i].end());
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();
    Fenwick fen(m);

    auto rk=[&](int x){
        return int(lower_bound(vals.begin(), vals.end(), x)-vals.begin());
    };

    vector<int> ans;

    for(int i=0;i<n;i++){
        auto &A = lsts[i];
        int l = A.size();

        int r0 = rk(A[0]);
        int base = fen.sum(m-1)-fen.sum(r0-1);
        int chosen = A[0];

        for(int j=1;j<l;j++){
            int rj = rk(A[j]);
            int v = fen.sum(m-1)-fen.sum(rj-1);
            if(v!=base) break;
            chosen = A[j];
        }

        fen.add(rk(chosen),1);
        ans.push_back(chosen);
    }

    vector<int> st_range(n);
    iota(st_range.begin(), st_range.end(), 0);
    stable_sort(st_range.begin(), st_range.end(), [&](int i,int j){
        return ans[i] < ans[j];
    });

    int last_i = n;
    vector<int> cur(1,0), dp(1,1);

    for(int i: st_range){
        vector<int> ncur, ndp;
        int pt=0, res=0;
        auto &A = lsts[i];
        int l = A.size();

        for(int j=0;j<l;j++){
            if(A[j] > ans[i]) break;
            while(pt < (int)cur.size() && (cur[pt] < A[j] || (cur[pt]==A[j] && last_i < i))){
                res += dp[pt];
                if(res>=mod) res-=mod;
                pt++;
            }
            ncur.push_back(A[j]);
            ndp.push_back(res);
        }

        cur.swap(ncur);
        dp.swap(ndp);
        last_i = i;
    }

    int64 res=0;
    for(int x:dp){ res+=x; if(res>=mod) res-=mod; }
    cout<<res;
    return 0;
}
