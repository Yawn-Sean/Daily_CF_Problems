#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1E4;
void solve() {
	string s; cin >> s;
	vector<vector<int>> stk(M);

	int cur = 0, n = s.length();
	for (int i = 0; i < n; i++){
		if (s[i] == '('){
			stk[cur++].push_back(0);
		}
		else if (s[i] == ')'){
			int x = 0;
			while(!stk[cur].empty()){
				x = max(x, stk[cur].back());
				stk[cur].pop_back();
				if (!stk[cur].empty()) stk[cur].back()++;
			}
			cur--;
			stk[cur].back() = max(stk[cur].back(), x);
		}
		else {
			i++;
		}
	}
	int x = 0;
	while(!stk[cur].empty()){
		x = max(x, stk[cur].back());
		stk[cur].pop_back();
		if (!stk[cur].empty()) stk[cur].back()++;
	}
	cout << x << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}