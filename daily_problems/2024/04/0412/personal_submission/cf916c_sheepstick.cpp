#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 1E9;
const int L = 1E5 + 3;
void solve() {
	int n, m; cin >> n >> m;
	cout << L <<" "<< L << "\n";
	for (int i = 1; i < n - 1; i++){
		cout << i <<" "<< i + 1 <<" "<< 1 << "\n";
	}
	cout << n - 1 <<" "<< n << " "<< L - (n - 2) << "\n";

	m -= n - 1;
	while(m){
		for (int i = 1; i <= n - 1 && m; i++){
			for (int j = i + 2; j <= n && m; j++){
				cout << i <<" "<< j <<" "<< INF << "\n";
				m--;
			}
		}
	}


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}