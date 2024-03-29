#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 1 << 30;

vector<int> lps(string& p) {
    vector<int> lps(p.length(), 0);
    int len = 0, i = 1;
    while (i < (int) p.length()) {
        if (p[i] == p[len]) { //case 1,2
            lps[i++] = ++len;
        }
        else if (len) { // case 3
            len = lps[len - 1];
        }
        else { // case 3 ending case
            lps[i++] = 0;
        }   
    }
    return lps;
}

void solve() {
	string c, s, t; cin >> c >> s >> t;
	auto ls = lps(s);
	auto lt = lps(t);

	int ms = s.length(), mt = t.length(), delta = 0;
	vector<vector<int>> dp(ms, vector<int>(mt, -INF));
	dp[0][0] = 0;

	auto gao = [&](string &s, vector<int> &lps, int i, char ch, int coeff) -> int {
		while(i && ch != s[i]) i = lps[i - 1];
		if (ch == s[i]){
			if (++i == (int) s.length()){
				delta += coeff;
				i = lps[i - 1];
			}
		}
		return i;
	};

	for (auto ch : c){
		vector<vector<int>> tmp(ms, vector<int>(mt, -INF));
		for (int i = 0; i < ms; i++){
			for (int j = 0; j < mt; j++) if (dp[i][j] > -INF){
				if (islower(ch)){
					delta = 0;
					auto ii = gao(s, ls, i, ch, 1);
					auto jj = gao(t, lt, j, ch, -1);
					tmp[ii][jj] = max(tmp[ii][jj], dp[i][j] + delta);
				}
				else {
					for (char ch = 'a'; ch <= 'z'; ch++){
						delta = 0;
						auto ii = gao(s, ls, i, ch, 1);
						auto jj = gao(t, lt, j, ch, -1);
						tmp[ii][jj] = max(tmp[ii][jj], dp[i][j] + delta);
					}
				}
			}
		}
		swap(dp, tmp);
	}
	int mx = INT_MIN;
	for (int i = 0; i < ms; i++){
		for (int j = 0; j < mt; j++){
			mx = max(mx, dp[i][j]);
		}
	} 
	cout << mx << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}