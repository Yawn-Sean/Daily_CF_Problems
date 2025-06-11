#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct cmp {
    bool operator() (array<ll,2> &a, array<ll,2> &b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
};
bitset <155000> dele;
void solve(){
    int n;
    cin >> n;
    vector <ll> a(n+1);
    priority_queue <array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
    for (int i = 1; i <= n; ++ i) cin >> a[i], pq.push({a[i], i});
    
    while (pq.size() > 1){
        auto top1 = pq.top();pq.pop();
        auto top2 = pq.top();pq.pop();
        if (top1[0] != top2[0]){
            pq.push(top2);
        } else {
            ll num = top1[0], pos1 = top1[1], pos2 = top2[1];
            dele[pos1] = true, a[pos2] = 2*num;
            pq.push({2*num, pos2});
        }
    }
    cout << n-dele.count() << "\n";
    for (int i = 1; i <= n; ++ i)
        if (!dele[i]) cout << a[i] << "\n "[i < n];
}
