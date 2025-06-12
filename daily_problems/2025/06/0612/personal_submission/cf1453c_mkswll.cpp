#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int _;
	cin >> _;
	while(_--){
		int n;
		cin >> n;
		vector <string> s(n);
		vector rmx(10, vector <int> (n, -1)), cmx(10, vector <int> (n, -1));
		vector rmn(10, vector <int> (n, n)), cmn(10, vector <int> (n, n));
		vector <int> mxr(10, -1), mxc(10, -1), mnr(10, n), mnc(10, n);
		for(int i = 0; i < n; ++i){
			string s;
			cin >> s;
			for(int j = 0; j < n; ++j){
				int c = s[j] - '0';
				rmx[c][i] = max(rmx[c][i], j);
				cmx[c][j] = max(cmx[c][j], i);
				rmn[c][i] = min(rmn[c][i], j);
				cmn[c][j] = min(cmn[c][j], i);
				mxr[c] = max(mxr[c], i);
				mxc[c] = max(mxc[c], j);
				mnr[c] = min(mnr[c], i);
				mnc[c] = min(mnc[c], j);
			}
		}
		for(int i = 0; i <= 9; ++i){
			if(i == 5){
			}
			int ans = 0;
			if(mxr[i] == -1){
				cout << 0 << " \n"[i == 9];
				continue;
			}
			for(int j = 0; j < n; ++j){
				if(rmx[i][j] != -1)
					ans = max({	ans, 
								(rmx[i][j] - rmn[i][j]) * max(j, n - j - 1), 
								(rmx[i][j] - 0) * max(j - mnr[i], mxr[i] - j), 
								(n - rmn[i][j] - 1) * max(j - mnr[i], mxr[i] - j)});
				if(cmx[i][j] != -1){
					ans = max({	ans, 
								(cmx[i][j] - cmn[i][j]) * max(j, n - j - 1), 
								(cmx[i][j] - 0) * max(j - mnc[i], mxc[i] - j), 
								(n - cmn[i][j] - 1) * max(j - mnc[i], mxc[i] - j)});
				}
				
			}
			cout << ans << " \n"[i == 9];
		}
	}
	return 0;
}