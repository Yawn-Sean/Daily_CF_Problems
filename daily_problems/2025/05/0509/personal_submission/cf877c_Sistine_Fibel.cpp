#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数

signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
	int n;
    cin >> n;
    cout << 3 * n / 2 << endl;
    for(int i = 2; i <= n; i += 2)
        cout << i << ' ';
    for(int i = 1; i <= n; i += 2)
        cout << i << ' ';
    for(int i = 2; i <= n; i += 2)
        cout << i << ' ';        
}
