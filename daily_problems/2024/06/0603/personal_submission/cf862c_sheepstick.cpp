#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, x; cin >> n >> x;
	if (x == 0 && n == 2){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	if (n == 1){
		cout << x << "\n";
	}
	else if (n == 2){
		cout << x <<" "<< 0 << "\n";
	}
	else {
		for (int i = 1; i <= n - 2; i++){
			if (i == n - 2 && x == i) {
				x ^= i + 1;
				cout << i + 1 << " ";
			}
			else {
				x ^= i;
				cout << i <<" ";
			}
			
		}
		// a ^ b = x and a, b \notin [1, n - 3]
		cout << (((1 << 18) ^ x) + (1 << 17)) << " ";
		cout << ((1 << 18) + (1 << 17)) << "\n";
	}


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}