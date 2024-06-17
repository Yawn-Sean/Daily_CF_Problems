#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 3e5 + 5;

int n, q[N], tp, cnt;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s;
	if((n & 1) || s[0] == ')' || s[n - 1] == '(') {
		cout << ":(";
		exit(0);
	}
	s[0] = '(', s[n - 1] = ')';
	cnt = n / 2 - count(s.begin(), s.end(), '(');
	if(cnt < 0) {
		cout << ":(";
		exit(0);
	}
	for(int i = 1; i <= n - 2; ++ i) {
		if(s[i] == '?') {
			if(cnt) {
				s[i]= '(';
				-- cnt;
			}
			else s[i] = ')';
		}
	}
	cnt = 0;
	for(int i = 1; i <= n - 2; ++ i) {
		cnt += (s[i] == '(' ? 1 : -1);
		if(cnt < 0) {
			cout << ":(";
			exit(0);
		}
	}
	cout << s;
	return 0;
}
