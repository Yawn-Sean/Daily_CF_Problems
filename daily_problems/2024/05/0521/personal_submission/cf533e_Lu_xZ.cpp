#include<bits/stdc++.h>
using namespace std;

using ll = long long;

set<string> ans;

void check(string &s, string &t, int n) {	//len(s) = len(t) + 1
	int pre = 0, suf = 0;
	for(int i = 0; i < n; ++ i) {
		if(s[i] == t[i]) {
			++ pre;
		}
		else break;
	}
	for(int i = n - 1; i >= 0; -- i) {
		if(s[i + 1] == t[i]) {
			++ suf;
		}
		else break;
	}
	for(int i = 0; i <= pre; ++ i) {
		int sf = n - i;
		if(sf > suf) continue;
		string tmp = t;
		tmp.insert(i, 1, s[i]);
		ans.insert(tmp);
	}
}

string s, t;
int n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> s >> t;
	
	for(int i = 0; i < n; ++ i) {
		if(s[i] != t[i]) {
			string tmp = t;
			tmp.insert(i, 1, s[i]);
			check(tmp, s, n);
			
			
			tmp = s;
			tmp.insert(i, 1, t[i]);
			check(tmp, t, n);
			break;
		}
	}
	cout << ans.size();
	return 0;
}
