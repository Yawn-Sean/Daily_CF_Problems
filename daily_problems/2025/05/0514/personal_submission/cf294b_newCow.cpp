#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 110,inf = 10000000;

int n,t[N],w[N],f[N][2010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n;
	
	int sum = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> w[i];
		sum += t[i];
	}
	
	for (int i = 1;i <= n; i++) {
		fill(f[i],f[i] + 2010,inf);
	}
	
	for (int i = 1;i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j - w[i] - t[i] >= 0) {
				f[i][j] = min(f[i][j],f[i - 1][j - w[i] - t[i]]);
			}
			
			f[i][j] = min(f[i][j],f[i - 1][j] + t[i]);
		}
	}
	
//	for (int i = 1;i <= n; i++) {
//		for (int j = 0; j <= sum; j++) {
//			cout << f[i][j] << " ";
//		}
//		
//		cout << "\n";
//	}
	
	cout << f[n][sum] << "\n";
	
	return 0;
}
