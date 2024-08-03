#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, b;
void solve(){
    cin >> n >> b;
    vector <ll> prm, cnt;
    ll k = 1e18;
    for (ll i = 2; i <= b; ++ i)
        if (i*i > b) break;
        else if (!(b%i)){
            int sum = 0;
            while (!(b%i)) b /= i, ++ sum;
            prm.push_back(i), cnt.push_back(sum);
        }
    if (b > 1) prm.push_back(b), cnt.push_back(1);
    for (int i = 0; i < prm.size(); ++ i){
        ll c = 0, sum = n;
        while (sum) sum /= prm[i], c += sum;
        k = min(k, c/cnt[i]);
    }

    cout << k << "\n";
    return;
}

int main(){
    int _ = 1;
    while (_--) solve();
    return 0;
}
