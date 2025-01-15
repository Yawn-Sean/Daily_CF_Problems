#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> perm(m,vector<int>(n));
	vector<vector<int>> idx(m+1, vector<int>(n+1));
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++){
			cin>>perm[i][j];
			if(i>0){
				idx[i][perm[i][j]] = j;
			}
		}
	}
	if (m==1){
		cout<<1ll * n * (n+1)/2;
		return 0;
	}
	/*
		m指针
	*/
	i64 ans = 0;
	vector<int> vis(n+1, 0);
	for (int j=0;j<n;j++) {
		int cur = perm[0][j];
		if (!vis[cur]) {
			vis[cur] = 1;
			int ansL = 1;
						
			for(int l=1; ; l++){
				bool ok = true;
				for (int k=1; k<m;k++) {
					int pos_cur = idx[k][cur];
				
					if (pos_cur + l > n) { 
						ok = false;
						break;
					}
				
					if (perm[k][pos_cur+l] != perm[0][j+l]) {
						ok = false;
						break;
					}				
				}
				if (not ok) { break; }
				vis[ perm[0][j+l] ] = 1;
				ansL++;
			}
			
			// 长度为ansL内部的子数组都有效
			ans += 1ll * ansL * (ansL+1)/2;	
		}
	}
	cout<<ans;
	return 0;
}
