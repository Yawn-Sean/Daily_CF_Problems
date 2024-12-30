#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 100050, mod = 998244353, inf = 1e9;
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
};

void solve(){
    int n, q;
    cin >> n >> q;
    bool flg = 0;
    vector <int> nums(n+1);

    // 对零进行预处理
    {
        int maxv = 0, idx = -1;
        for (int i = 1, p = 1; i <= n; ++i) {
            cin >> nums[i];
            if (nums[i] == 0) nums[i] = p, idx = i;
            else p = nums[i];
            maxv = max(maxv, nums[i]);
        }
        if (q > maxv){
            if (idx != -1) nums[idx] = q;
            else {
                cout << "NO\n";
                return;
            }
        }
    }

    fenwick Y(n);
    vector <vector<int>> Pos(q+1);
    for (int i = 1; i <= n; ++ i)
        Pos[nums[i]].push_back(i);
    /*
        用树状数组查询两个相同的大的值中间是否存在小的值，如果存在则不满足条件
    */
    for (int i = 1; i <= q; ++ i){
        if (Pos[i].size()){
            if (Y.query(Pos[i].back()) - Y.query(Pos[i][0]) > 0){
                cout << "NO\n";
                return;
            }
            for (auto &x : Pos[i]) Y.add(x, 1);
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++ i) cout << nums[i] << "\n "[i < n];
}
