#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
#define int long long
#define endl '\n'
int f[N], s[N], n, m;

void solve() {
    cin >> n >> m;
    f[1] = 1;
    s[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] += s[i - 1];
        f[i] %= m;
        for (int l = 2, r; l <= i; l = r + 1) {
            int k = i / l;
            r = min(i / k,i);
            f[i]=(f[i]+(r-l+1)*f[k]%m)%m;
        }
        s[i] = (s[i - 1] + f[i])%m;
    }
    cout << f[n];
}   
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
}
