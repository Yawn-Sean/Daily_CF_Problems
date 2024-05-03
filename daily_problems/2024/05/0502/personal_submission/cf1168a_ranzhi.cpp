#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
#define endl '\n'

bool check(int& k, vector<int>& arr, int &m) {
	int pre = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == pre) continue;
		if (arr[i] < pre) {
			int cnt = pre - arr[i];
			if (cnt > k) return false;
		}
		else if (arr[i] > pre) {
			int cnt = m - arr[i] + pre;
			if (cnt > k) pre = arr[i];
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int left = 0, right = m - 1, mid;
	while (left <= right) {
		mid = left + ((right - left) >> 1);
		if (check(mid, arr, m)) right = mid - 1;
		else left = mid + 1;
	}
	cout << left << endl;
	return 0;
}
