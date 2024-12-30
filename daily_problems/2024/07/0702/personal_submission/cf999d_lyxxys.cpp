#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+5, inf = 1e9, mod = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;
    int part = n/m;
    vector <int> vec[m], cnt(m);
    vector <int> a(n+1);
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        // 预处理
        ++ cnt[a[i]%m], vec[a[i]%m].push_back(i);
    }
    ll res = 0;
    vector <int> stk;
    //纸牌均分问题，相邻模数的数字转换 一定是最小的
    for (int i = 0; i < 2*m; ++ i){
        int x = i%m;
        while (!stk.empty() && cnt[x] < part){
            int y = stk.back();
            stk.pop_back();
            int v = (x-a[y]%m+m)%m;
            a[y] += v, res += v;
            ++ cnt[x];
        }
        while (cnt[x] > part){
            stk.push_back({vec[x].back()});
            vec[x].pop_back();
            -- cnt[x];
        }
    }

    cout << res << "\n";
    for (int i = 1; i <= n; ++ i)
        cout << a[i] << "\n "[i < n];
}
