#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size(), m;
	cin >> m;
	vector bad(n + 1, n - 1);
	for(int i = 1; i <= m; ++i){
		string t;
		cin >> t;
		int len = t.size();
		for(int j = 0; j + len - 1 < n; ++j){
			bool flag = 1;
			for(int k = 0; k < len; ++k){
				if(s[j + k] != t[k]){
					flag = 0;
					break;
				}
			}
			if(flag){
				bad[j] = min(bad[j], j + len - 2);
			}
		}
	}

	int mx = 0, pos = 0;
	int r = n - 1;
	for(int i = n - 1; ~i; --i){
		r = min(r, bad[i]);
		if(r - i + 1 > mx){
			mx = r - i + 1;
			pos = i;
		}
	}
	cout << mx << " " << pos << "\n";
}