#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2050, mod = 1e9 + 7, inf = 1e9;
struct fenwick {
    vector <ll> info;
    int n;
    fenwick(){}
    fenwick(int n): info(n+1), n(n){}
    void init(int n){
        info.resize(n+1), this->n = n;
        for (int i = 0; i <= n; ++ i) info[i] = 0;
    }
    void modify(int x, ll c){
        while (x <= n) info[x] += c, x += x&-x;
    }
    ll query(int x) {
        ll res = 0;
        while (x) res += info[x], x -= x&-x;
        return res;
    }
};
vector<fenwick> Y;
/*
    维护k+1个树状数组
    Y[j].info[x] 表示序列长度为 j 且 以 x 结尾的上升子序列个数
    Y[j].query(x) 将长度为j的的序列中 每个 以 小于等于 x 的数字结尾 的上升子序列个数 求和 
    把树状数组理解成求前缀和的自动机
    树状数组转移的时候可以滚动
    时间复杂度 O(n*k*logn)
*/
void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> A(n+1);
    for (int i = 1; i <= n; ++ i) cin >> A[i];
    Y.resize(k+2);
    for (int i = 0; i <= k+1; ++ i)
        Y[i].init(n);

    for (int i = 1; i <= n; ++ i){
        Y[1].modify(A[i], 1);
        /*倒序遍历消除影响*/
        for (int j = k+1; j >= 2; -- j){
            ll v = Y[j-1].query(A[i]-1);
            Y[j].modify(A[i], v);
        }
    }

    cout << Y[k+1].query(n) << "\n";
}
