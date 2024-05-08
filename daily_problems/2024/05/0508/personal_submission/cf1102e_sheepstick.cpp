#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	map<int,int> R;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		R[a[i]] = i;
	}

	i64 res = 1;
	int r = R[a[0]];
	for (int i = 1; i < n; i++){
		//cout << i <<" "<< r << "--\n";
		if (r < i){
			res = res * 2 % mod;
		}
		r = max(r, R[a[i]]);
	}
	cout << res << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}