#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'
signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
    int n, ans;
	cin >> n;
    if(n <= 2 or (n & 1) != 1) { puts("-1"); return; }
    vector<int > a(n + 1, 0);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int i = n; i >= 1; i --) {
        if(a[i] <= 0) 
            continue;

        if((i & 1) != 1)
            ans += a[i], a[i + 1] -= a[i], a[i / 2] -= a[i], a[i] = 0;
        else
            ans += a[i], a[i - 1] -= a[i], a[i / 2] -= a[i], a[i] = 0;
    }
    cout << ans;
}
