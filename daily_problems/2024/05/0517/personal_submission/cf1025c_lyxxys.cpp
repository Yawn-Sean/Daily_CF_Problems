#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9, mod = 998244353;
const double eps = 1e-9;

void solve(){
	string s;
	cin >> s;
	int siz = s.size();
	s += s;
	int n = s.size()-1;
	int res = 1;
	for (int i = n-1, lst = n; i >= 0; -- i){
		if (lst-i > siz) -- lst;  //边界处理，包不包在所求串中为:lst-i 不用+1 
		if (i == 0 || s[i] == s[i+1]){
			res = max(res, lst-i);
			lst = i;
		}
	}
	cout << res << "\n";
}
