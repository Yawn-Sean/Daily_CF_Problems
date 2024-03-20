#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	string s; cin >> s;
	int n = s.length();

	vector<bool> rem(n, 0);
	vector<bool> found(4, 0);
	string target = "1689";

	for (int i = 0; i < n; i++){
		int pos = target.find(s[i]);
		if (pos != -1 && pos < 4 && !found[pos]){
			found[pos] = 1;
			rem[i] = 1;
		}
	}
	string cur;
	int zeroCnt = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '0') zeroCnt++;
		else if (!rem[i]){
			cur += s[i];
		}
	}
	//calculate rem
	int sz = cur.length();
	int f = 0;
	for (int i = 0; i < sz; i++){
		f = f * 10 + (cur[i] - '0');
		f %= 7;
	}
	f = f * 10000 % 7;
	//permutation
	do {
		int val = stoi(target);
		val %= 7;
		if ((val + f) % 7 == 0) break;
	} while(next_permutation(target.begin(), target.end()));
	cout << cur << target << string(zeroCnt, '0') << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}
