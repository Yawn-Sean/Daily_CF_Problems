#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N = 105;

ll n,m,k,f[N][N][27],num[27][27];
char s[N];


// 前 i 个字符，可以改 j 次，上一个字符是 last 
ll dfs(int i,int j,int last) {
	if (i < 1) {
		return 0;
	}
	
	if (f[i][j][last] != -1) {
		return f[i][j][last];
	}
	
	ll res = -1000000000000;
	
	// 没改 
	res = max(res,dfs(i - 1,j,s[i] - 'a') + num[last][s[i] - 'a']);
	
	if (j >= 1) {
		for (int c = 25; c >= 0; --c) {
			if (c == s[i] - 'a') {		
				continue;
			} else {   // 改了 
				res = max(res,dfs(i - 1,j - 1,c) + num[last][c]);
			}
		}
	}
	
	f[i][j][last] = res;
	
	return res;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> s + 1 >> k >> m;
	n = strlen(s + 1);
	int d;
	char x,y;

	for (int i = 1;i <= m; i++) {
		cin >> x >> y >> d;
		
		num[y - 'a'][x - 'a'] = d;
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int last = 0; last <= 26; last++) {
				f[i][j][last] = -1;
			}
		}
	}
	
	ll ans = dfs(n,k,26);
	cout << ans << "\n";
	
	return 0;
}
