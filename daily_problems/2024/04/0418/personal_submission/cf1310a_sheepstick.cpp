#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<array<i64,2>> a(n);
	vector<i64> b(n);
	for (int i = 0; i < n; i++){
		i64 x; cin >> x;
		a[i] = {x, i};
	}
	for (auto &bi : b){
		cin >> bi;
	}
	sort(a.begin(), a.end());
	i64 res = 0;

	i64 surplus = 0, t = a[0][0];
	int idx = 0;
	priority_queue<i64> pq;

	while(idx < n || !pq.empty()){
		while(idx < n && a[idx][0] == t){
			pq.push(b[a[idx][1]]);
			surplus += b[a[idx][1]];
			idx++;
		}
		if (pq.empty()){
			t = a[idx][0];
			continue;
		}
		auto mx = pq.top(); pq.pop();
		surplus -= mx;
		res += surplus;
		t++;
	}
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}