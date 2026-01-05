#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a,ll b){
    ll c = 0;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll lcm(int a,int b){
    return (ll)(a / gcd(a,b)) * b;
}

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << c - gcd(1ll * c,lcm(a,b)) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}