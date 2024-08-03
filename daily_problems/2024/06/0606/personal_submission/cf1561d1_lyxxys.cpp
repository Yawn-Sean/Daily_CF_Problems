#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using ull = unsigned long long;
const int N = 2000001, mod = 1000001, inf = 1e9;
vector <int> g[N];
int n, p;


void solve(){
    cin >> n >> p;
    vector <int> f(n+1);

    f[n] = 1;
    for (int i = n, last = 0; i >= 1; -- i){
        f[i] = (f[i] + last) % p;

        for (int l = 2, r; l <= i; l = r+1){
            r = i / (i/l);
            f[i/l] = (f[i/l] + 1ll*f[i]*(r-l+1)) % p;
        }
        
        last += f[i], last %= p;
    }

    cout << f[1] << "\n";
}
 
int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
