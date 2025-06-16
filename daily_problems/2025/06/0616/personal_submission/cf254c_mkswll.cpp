#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector <int> cnt(26, 0);
	string s, t;
	cin >> s >> t;
	for(auto i : s) cnt[i - 'A']++;
	for(auto i : t) cnt[i - 'A']--;
	int n = s.size();
	string tt = "";
	for(int i = 0; i < 26; ++i){
		if(cnt[i] < 0) tt += string(-cnt[i], 'A' + i);
	}
	vector <int> rec(26, 0);
	for(int i = 0; i < n; ++i) rec[s[i] - 'A']++;
	int ptr = 0;
	for(int i = 0; i < n; ++i){
		int c = s[i] - 'A';
		if(cnt[c] <= 0) continue;
		if(tt[ptr] < s[i] || rec[c] == cnt[c]){
			--cnt[c];
			s[i] = tt[ptr];
			++ptr;
		}
		--rec[c];
	}
	cout << tt.size() << "\n" << s << "\n";
	return 0;
}