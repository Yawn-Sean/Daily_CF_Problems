#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<string> a(n);
	for (auto &ai : a){
		cin >> ai;
	}
	vector<i64> h(n), s(n);
	for (int i = 0; i < n; i++){
		for (auto &ch : a[i]){
			if (ch == 'h') h[i]++;
			else s[i]++;
		}
	}
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);

	sort(idx.begin(), idx.end(), [&](int i, int j){return h[j] * s[i] > h[i] * s[j];});


	i64 cnt = 0, Scnt = 0;
	for (int i = 0; i < n; i++){
		for (auto &ch : a[idx[i]]){
			if (ch == 's') Scnt++;
			else cnt += Scnt;
		}
	}

	cout << cnt << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}