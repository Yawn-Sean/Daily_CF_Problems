#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 5010;

int n,m,b[N][N];
char a[N][N];

vector<int> col[N];

int main() {
	 ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
//	scanf("%d%d",&n,&m);
	 cin >> n >> m;
	
	for (int i = 1;i <= n; i++) {
//		scanf("%s",a[i] + 1);
		cin >> a[i] + 1;
	}
	
	for (int i = 1;i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '1') {
				b[i][j] = b[i][j - 1] + 1;
			} else {
				b[i][j] = 0;
			}
			// cout << b[i][j] << " ";
		}
		// cout << "\n";
	}
	
	int ans = 0;
	
	for (int j = 1;j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (b[i][j] == 0) continue;
			
			col[j].push_back(b[i][j]);
		}
		
		sort(col[j].begin(),col[j].end());
		
		int size = col[j].size();
		for (int p = size - 1; p >= 0; p--) {
			int area = col[j][p] * (size - p);
			
			ans = max(ans,area);
		}
	}
	
	// printf("%d\n",ans);
	cout << ans << "\n";
	return 0;
}
