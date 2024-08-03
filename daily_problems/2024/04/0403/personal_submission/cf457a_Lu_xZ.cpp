#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
#define pb emplace_back
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 5;
constexpr long double p = (sqrtl(5) + 1) * 0.5;

int cnt[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	string s, t; cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	for(int i = 0; i < s.length(); ++ i) {
		cnt[i] += s[i] == '1';
	}
	for(int i = 0; i < t.length(); ++ i) {
		cnt[i] -= t[i] == '1';
	}
	for(int i = 1e5; i >= 2; -- i) {
		if(cnt[i] > 1) {
			cout << '>';
			return 0;
		}
		if(cnt[i] < -1) {
			cout << '<';
			return 0;
		}
		cnt[i - 1] += cnt[i];
		cnt[i - 2] += cnt[i];
	}
	if(cnt[0] == 0 && cnt[1] == 0) {
		cout << '=';
		return 0;
	}
	cout << (cnt[1] < -cnt[0] / p ? '<' : '>');
	return 0;
}
