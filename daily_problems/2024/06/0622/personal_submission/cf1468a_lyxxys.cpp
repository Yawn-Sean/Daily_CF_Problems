#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 500055, inf = 1e9;
struct segTree {
    vector <int> tr;
    segTree(): tr(4*N+1, 0){}
    void init(int o, int l, int r){
        tr[o] = 0;
        if (l == r) return;
        int mid = l+r>>1;
        init(o*2, l, mid), init(o*2+1, mid+1, r);
    }
    void pull(int o){
        tr[o] = max(tr[o*2], tr[o*2+1]);
    }
    void modify(int o, int l, int r, int pos, int v){
        if (l == r){
            tr[o] = v;
            return;
        }
        int mid = l+r >> 1;
        if (pos <= mid) modify(o*2, l, mid, pos, v);
        else modify(o*2+1, mid+1, r, pos, v);
        pull(o);
    }
    int query(int o, int l, int r, int L, int R){
        if (L > R) return 0;
        if (l >= L && r <= R) return tr[o];
        int res = 0;
        int mid = l+r >> 1;
        if (L <= mid) res = query(o*2, l, mid, L, R);
        if (R > mid) res = max(res, query(o*2+1, mid+1, r, L, R));
        return res;
    }    
};

void solve(){
    static segTree trs;
    int n;
    cin >> n;
    trs.init(1, 1,n);
    vector <int> nums(n+1), last(n+1, 0);
    for (int i = 1; i <= n; ++ i) cin >> nums[i];

    {
        vector <int> stk;
        for (int i = 1; i <= n; ++ i){
            auto it = &stk.back();
            while (stk.size() && nums[*it] < nums[i]){
                stk.pop_back(), -- it;
            }
            if (stk.size()) last[i] = *it;
            stk.push_back(i);
        }
    }

    vector <int> p(n+1);
    iota(p.begin(), p.end(), 0);
    stable_sort(p.begin()+1, p.end(), [&](int i, int j){
        return nums[i] < nums[j];
    });

    for (int i = 1; i <= n; ++ i){
        int idx = p[i], v=0;
        if (last[idx] != 0){
            int lst = last[idx];
            v = max(trs.query(1,1,n, 1,lst-1)+2, trs.query(1,1,n, lst,idx)+1);
        } else v = trs.query(1,1,n, 1,idx)+1;
        trs.modify(1,1,n, idx,v);
    }

    cout << trs.query(1,1,n, 1,n) << "\n";
}
