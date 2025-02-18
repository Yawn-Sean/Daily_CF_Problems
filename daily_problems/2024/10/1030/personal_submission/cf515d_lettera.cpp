#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    vector<vector<int>> cnt(n + 1, vector<int>(m + 1));
    vector<array<int, 2>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    string s = "^v><";
    auto check = [&](int i, int j) { 
    return i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] == '.';
     };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int ni = i + d[k][0];
                int nj = j + d[k][1];
                if (a[i][j]=='.'&&check(ni, nj))
                {
                    cnt[i][j]++;//(i,j)是空的时周围空的格子的数目
                }
            }
        }
    }
    auto dfs = [&](auto self, int i, int j) -> void {
    	//首先(i,j)是突破点,然后我们把这两个点涂黑
			for(int k=0;k<4;k++){
				int ni=i+d[k][0];
				int nj=j+d[k][1];
				if(check(ni,nj))
				{
					cnt[i][j]=cnt[ni][nj]=0;
					a[ni][nj]=s[k];
					a[i][j]=s[k^1];
					for(int o=0;o<4;o++)
					{
						int nni=ni+d[o][0],nnj=nj+d[o][1];
						if(check(nni,nnj)){
							cnt[nni][nnj]--;
							if(cnt[nni][nnj]==1)
							{
								self(self,nni,nnj);
							}
						}
					}
					return;
				}			 
			}
			
    };
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		if(cnt[i][j]==1)
    		{
    			dfs(dfs,i,j);
    		}
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		if(a[i][j]=='.')
    		{
    			cout<<"Not unique\n";
    			return;
    		}
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		cout<<a[i][j];
    	}
    	cout<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
