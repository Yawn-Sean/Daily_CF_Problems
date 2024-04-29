#include<bits/stdc++.h>
using namespace std;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
	int n = red();
	vector<int> v, p(n + 1);
	int mx = -1, res = n + 1, mn = INT_MAX, cur;
	for(int i = 1; i <= n; ++i) {
		int x = red();
		p[x]++;
		mx = max(mx, x);
	}
	for(int i = 1; i <= mx; ++i) {
		if(!p[i]) {
			continue;
		} 
		v.push_back(p[i]);
		mn = min(mn,p[i]);
	 } 
	 for(int i = 1; i <= mn + 1; ++i) {
	 	cur = 0;
	 	for(int x : v) {
	
	 		int tot = (x - 1) / i + 1;
	 		if(x % i ==0 ) {
				cur += x / i;
	 		} else if((x - tot * (i - 1)) >= 0 && (x - tot * (i - 1)) <= tot) {
	 			cur += tot;
	 		} else {
	 			cur = -1;
	 			break;
	 		}
		 }
		 if(cur > 0) res = min(res, cur);
	 }
	 cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = red();
    while (t--) {
        solve();
    }
}
