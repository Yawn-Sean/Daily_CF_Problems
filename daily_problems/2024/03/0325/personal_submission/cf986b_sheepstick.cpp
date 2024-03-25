#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1), visited(n + 1, 0);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int res = 0;
	for (int i = 1; i <= n; i++) if (!visited[i]){
		int j = i, cnt = 1;
		while(!visited[j]){
			cnt ^= 1;
			visited[j] = 1;
			j = a[j];
		}
		res ^= cnt;
	}
	if (((res ^ n) & 1) == 0){
		cout << "Petr\n";
	}
	else cout << "Um_nik\n";



}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}