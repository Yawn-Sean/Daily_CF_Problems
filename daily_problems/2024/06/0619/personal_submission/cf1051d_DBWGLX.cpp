#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define PII pair<int,int>
#define int ll

const int maxn = 1e3 + 5;
const int MOD = 998244353;

//0 1 2 3
//w w b b
//w b w b

int n, k;
int dp[maxn][2005][4];
//j列 已经有多少个k了 当前列状态
//         背包
void solve()
{
	cin >> n >> k;
	dp[0][1][0] = 1;
	dp[0][2][1] = 1;
	dp[0][2][2] = 1;
	dp[0][1][3] = 1;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i + 1][j][0] = (dp[i][j][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j-1][3])%MOD;//w多了个b
			if (j > 1)
			{
				dp[i + 1][j][1] = (dp[i][j-1][0] + dp[i][j][1] + dp[i][j-2][2] + dp[i][j-1][3])%MOD;
				dp[i + 1][j][2] = (dp[i][j-1][0] + dp[i][j-2][1] + dp[i][j][2] + dp[i][j-1][3])%MOD;
			}
			dp[i + 1][j][3] = (dp[i][j-1][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j][3]) % MOD;
		}
	}

	cout << (((dp[n - 1][k][0] + dp[n - 1][k][1])%MOD + dp[n - 1][k][2])%MOD + dp[n - 1][k][3])%MOD << endl;
}
signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}
