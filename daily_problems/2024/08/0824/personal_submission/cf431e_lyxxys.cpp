#pragma GCC otimize(2)
#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2e5+11, mod = 998244353, inf = 1e9;
// 建立值域线段树， 动态查询 第k小数， 前k小数字的和，单点修改
struct Node {
    long long Val, sz;
    Node *l, *r;
    Node(){
        Val = 0, sz = 0, l = nullptr, r = nullptr;
    }
    void pull(Node *u) {
        u->sz = 0, u->Val = 0;
        if (u->l) u->Val += u->l->Val, u->sz += u->l->sz;
        if (u->r) u->Val += u->r->Val, u->sz += u->r->sz;
    }
    void modify(Node *u, int lt, int rt, int pos, int v){
        if (lt == rt){
            u->Val += v*lt, u->sz += v;
            return;
        }
        int mid = lt + rt >> 1;
        if (pos <= mid){
            if (!(u->l)) u->l = new Node();
            modify(u->l, lt, mid, pos, v);
        } else {
            if (!(u->r)) u->r = new Node();
            modify(u->r, mid+1, rt, pos, v);
        }
        pull(u);
    }
    // 查询第k小数， 并返回前k小数字的和
    pair<int, long long> query(Node *u, int lt, int rt, int k){
        if (!u) return {-1, 0};
        if (lt == rt){
            return {lt, k*lt};
        }
        int mid = lt + rt >> 1;
        int szL = u->l ? u->l->sz : 0;
        if (szL < k){
            long long Lval = u->l ? u->l->Val : 0;
            auto it = query(u->r, mid+1, rt, k-szL);
            it.second += Lval;
            return it;
        } else {
            return query(u->l, lt, mid, k);
        }
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    Node *root = new Node();
    vector <int> nums(n);
    for (auto &x : nums){
        cin >> x;
        root->modify(root, 0, 1e9, x, 1);
    }

    function<double(long long)> call = [&](long long x){
        int l = 1, r = n;
        while (l < r){
            int mid = l+r+1 >> 1;
            auto [Max, sum] = root->query(root, 0, 1e9, mid);
            if (x >= 1ll*Max*mid - sum) l = mid;
            else r = mid-1;
        }
        long long sum = root->query(root, 0, 1e9, l).second;
        return (1.0*sum+x)/l;
    };

    while (q--){
        int opt, p;
        long long v;
        cin >> opt;
        if (opt == 1){
            cin >> p >> v;
            -- p;
            root->modify(root, 0, 1e9, nums[p], -1);
            nums[p] = v;
            root->modify(root, 0, 1e9, nums[p], 1);
        } else {
            cin >> v;
            cout << call(v) << "\n";
        }
    }
}
