// submission link: https://codeforces.com/contest/933/submission/256858915
#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int ret = 1;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
	cin >> a[i];
    }
    int dp1, dp12, dp121, dp1212;
    for (auto &x: a){
	if (x == 1){
	    dp1 ++;
	    dp121 ++;
	} else {
	    dp12 ++;
	    dp1212 ++;
	}
	dp12 = max(dp12, dp1);
	dp121 = max(dp121, dp12);
	dp1212 = max(dp1212, dp121);
    }

    cout << dp1212 <<endl;
}

int main() {
    solve();
    return 0;
}
