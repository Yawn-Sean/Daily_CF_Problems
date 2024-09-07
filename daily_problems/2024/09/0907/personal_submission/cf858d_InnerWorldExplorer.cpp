#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<string> contacts(n);
	map<string, int> f;
	for (int k = 0; k < n; k ++) {
		cin >> contacts[k];
		set<string> s;
		for (int len = 1; len < 10; len ++) {
			for (int i = 0; i < 10 - len; i ++) {
				string cur = contacts[k].substr(i, len);
				s.insert(cur);
			}
		}
		for (auto x : s) {
			f[x] ++;
		}
	}
	for (int k = 0; k < n; k ++) {
		bool v = false;
		for (int len = 1; len < 10 && !v; len ++) {
			for (int i = 0; i < 10 - len && !v; i ++) {
				string cur = contacts[k].substr(i, len);
				if (f[cur] == 1){
					cout << cur << endl;
					v = true;
				}
			}
		}
	}
	return 0;
}
