#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int>minp,primes;

void sieve(int n){
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if(minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
bool isprime(int n) {
    return minp[n] == n;
}

void solve(){
    sieve(1e7 + 5);
    int len = 0;
    map<int, int>mp;
    int n;
    cin >> n;
    int gcdnum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (gcdnum == 0) gcdnum = a[i];
        else gcdnum = __gcd(gcdnum, a[i]);
    }

    for (int i = 0; i < n; i++) {
        a[i] /= gcdnum;
        while (a[i] != 1) {
            if (mp[minp[a[i]]] != 0) {
                cout << "NO" << endl;
                return;
            }
            else {
                int tmp = minp[a[i]];
                while (a[i] % tmp == 0) a[i] /= tmp;
                mp[tmp] = 1;
            }
        }
    }

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
