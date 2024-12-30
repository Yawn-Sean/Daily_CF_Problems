#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
struct fenwick {
    vector <int> info;
    int n;
    fenwick(){}
    fenwick(int n): info(n+1), n(n){}
    void init(int n){
        info.resize(n+1), this->n = n;
        for (int i = 0; i <= n; ++ i) info[i] = 0;
    }
    void add(int x, int c){
        while (x <= n) info[x] += c, x += x&-x;
    }
    int query(int x) {
        int res = 0;
        while (x) res += info[x], x -= x & -x;
        return res;
    }
    int select(int kth){  // 找到 小于kth的 最后一个下标
        int ans = 0, cnt = 0;
        for (int i = 20; i >= 0; -- i){
            ans += 1 << i;
            if (ans >= n || cnt + info[ans] >= kth) ans -= 1 << i;
            else cnt += info[ans];
        }
        return ans+1;
    }
};

void solve(){
    int n, m;
    cin >> n;
    vector <int> A(n+1), p(n+1);
    for (int i = 1; i <= n; ++ i) cin >> A[i];
    iota(p.begin(), p.end(), 0);
    sort(p.begin()+1, p.end(), [&](int x, int y){
        return A[x] != A[y] ? A[x] > A[y] : x < y;
    });

    cin >> m;
    vector <array<int,3>> qys(m);
    vector <int> ans(m);
    for (int i = 0; i < m; ++ i){
        cin >> qys[i][0] >> qys[i][1];
        qys[i][2] = i;
    }
    sort(qys.begin(), qys.end(), [&](array<int,3>&a, array<int,3>&b){
        return a[0] < b[0];
    });

    fenwick Y(n);
    int c = 0;
    for (auto &it : qys){
        while (c < it[0]){
            Y.add(p[++ c], 1);
        }
        ans[it[2]] = A[Y.select(it[1])];
    }   

    for (auto &x : ans) cout << x << "\n";
}
