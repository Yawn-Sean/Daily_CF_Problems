#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pll = pair<ll,ll>;
const ll INF = 4e18;

void solve(){ 
    ll n, k, x;
    cin >> n >> k >> x;
    vector <ll> a(n+1);
    int nega = 0;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        if (a[i] < 0) nega = !nega;
    }
    auto find = [&](int &p)->void{  //找绝对值最小下标
        for (int i = 1; i <= n; ++ i)
            if (abs(a[i]) < abs(a[p])) p = i;
    };

    auto work = [&]()->void{  //将整个数组的的乘积变成负数
        int p = 1;
        find(p);
        ll j = (abs(a[p])-1)/x + 1;
        if (j <= k){
            if (a[p] <= 0) nega = !nega;  //已经减掉一个0且为负数
            k -= j;
            a[p] += a[p] < 0 ? j*x : -j*x;
        }        
        else a[p] += a[p] < 0 ? k*x : -k*x, k = 0;  //不能变成负数
    };

    if (!nega) work();
    if (k){
        priority_queue <Pll, vector<Pll>, greater<Pll>> heap;
        for (int i = 1; i <= n; ++ i) heap.push({abs(a[i]), i});
        while (k--){
            auto top = heap.top();
            heap.pop();
            int pos = top.second;
            if (!a[pos] && !nega) a[pos] = -x, nega = 1;  //一个零-x
            else a[pos] += a[pos] >= 0 ? x : -x;  //剩余的零全部+x
            heap.push({abs(a[pos]), pos});
        }
    }
    for (int i = 1; i <= n; ++ i) cout << a[i] << " ";
    cout << "\n";
}

