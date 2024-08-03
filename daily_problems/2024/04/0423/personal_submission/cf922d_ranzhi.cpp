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

bool cmp(const string& a, const string& b) {
	int num1 = 0, num2 = 0;
	for (auto& x : a) {
		if (x == 's') num1 += 1;
	}
	for (auto& x : b) {
		if (x == 's') num2 += 1;
	}
	return num1 * b.size() > num2 * a.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end(), cmp);
	string s;
	for (auto& x : arr) s += x;
	vector<int> nums(s.size() + 1);
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'h') nums[i] = nums[i + 1] + 1;
		else nums[i] = nums[i + 1];
	}
	ll ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 's') ans += nums[i];
	}
	cout << ans << endl;
	return 0;
}
