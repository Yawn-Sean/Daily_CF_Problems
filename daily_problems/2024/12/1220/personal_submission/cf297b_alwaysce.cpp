#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		上一次操作 前面剩下的人数 => 发现 剩下的是一个人+一段连续的后缀
	*/
	
	int n, m, k;
	cin >> n >> m >> k;
	map<int,int> cnt;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cnt[x]--;
	}
	
	int suf = 0;
	for (auto pr = cnt.rbegin(); pr != cnt.rend(); pr++) {
		suf += pr->second;
		if (suf > 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
