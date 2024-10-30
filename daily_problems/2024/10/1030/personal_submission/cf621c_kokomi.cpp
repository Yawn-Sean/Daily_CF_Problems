#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
struct node{
    ll l, r;
}a[N];
ll count_multiples(ll l, ll r, ll p){
    if(l % p == 0){
        return r / p - l / p + 1;
    }else{
        return r / p - l / p;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r;
    }
    long double ans = 0.0;
    for(int i = 0; i < n; i++){
        int next = (i + 1) % n;
        ll m1 = count_multiples(a[i].l, a[i].r, p);
        ll m2 = count_multiples(a[next].l, a[next].r, p);
        ll cnt1 = a[i].r - a[i].l + 1;
        ll cnt2 = a[next].r - a[next].l + 1;
        ll total_pairs = cnt1 * cnt2;
        ll valid_pairs = m1 * cnt2 + m2 * cnt1 - m1 * m2;
        ans +=  (long double)valid_pairs / total_pairs;
    }
    cout << fixed << setprecision(20) << ans * 2000 << endl;
    return 0;
}