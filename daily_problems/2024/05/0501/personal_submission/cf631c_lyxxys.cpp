#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> a(n+1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int top = -1;
    static Pii stk[N];
    for (int i = 1; i <= m; ++ i){
        int ops, r;
        cin >> ops >> r;
        while (~top && stk[top].first <= r) -- top;
        stk[++ top] = {r, ops};
    }
    vector <int> res(n+1);
    int l = 1, r = n;
    {   
        int rp  = stk[0].first;
        while (r > rp) res[r] = a[r], -- r;
        sort(a.begin()+1, a.begin()+1+rp);
    }
    for (int tp = 0; tp <= top; ++ tp){
        int rp = stk[tp].first, ops = stk[tp].second;
        int pos = tp == top ? 1 : stk[tp+1].first+1;
        int len = rp - pos + 1;
        if (ops == 1){
            for (int i = pos, j = r-len+1; j <= r; ++ i, ++ j)
                res[i] = a[j];
            r -= len;
        }
        else
        {
            for (int i = pos, j = l+len-1; j >= l; ++ i, -- j)
                res[i] = a[j];
            l += len;
        }
    }
    for (int i = 1; i < res.size(); ++ i) cout << res[i] << " ";
    cout << "\n";
}
