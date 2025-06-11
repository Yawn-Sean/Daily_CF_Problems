#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
/*
	假设alice的图的边是红色的，bob的图的边是蓝色的
	那么我们统计每个点出去的红蓝边的总和，那么损失的三元环就是它的两倍(以为会多统计一次)
*/
void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> degs(n);
    for (int i = 0,u,v; i < m; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        degs[u] += 1, degs[v] += 1;
    }
    long long rare = 0;
    for (int i = 0; i < n; ++ i){
        rare += 1ll * degs[i] * (n-1-degs[i]);
    }
    assert(rare%2 == 0);
    rare /= 2;
    cout << n*(n-1)*(n-2)/6 - rare << "\n";
}
