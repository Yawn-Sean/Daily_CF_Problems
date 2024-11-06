#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<vector<int>>g(n+1);
	vector<int>dis1(n+1,-1),dis2(n+1,-1),dis3(n+1,-1);
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	 
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==1)
		{
			queue<int>q;
			q.push(i);
			dis1[i]=0;
			while(!q.empty())
			{
				auto u=q.front();
				q.pop();
				for(auto v:g[u])
				{
					if(dis1[v]==-1)
					{
						dis1[v]=dis1[u]+1;
						q.push(v);
					}
				}
			}
			int x=max_element(dis1.begin(),dis1.end())-dis1.begin();
			q.push(x);
			dis2[x]=0;
			while(!q.empty())
			{
				auto u=q.front();
				q.pop();
				for(auto v:g[u])
				{
					if(dis2[v]==-1)
					{
						dis2[v]=dis2[u]+1;
						q.push(v);
					}
				}
			}
			int rt=0;
			for(int i=1;i<=n;i++)
			{
				if(dis1[i]==k&&dis2[i]==k)
				{
					rt=i;
				}
			}
			if(g[rt].size()<3)
			{
				cout<<"No\n";
				return;
			}
			q.push(rt);
			dis3[rt]=0;
			while(!q.empty())
			{
				auto u=q.front();
				q.pop();
				for(auto v:g[u])
				{
					if(dis3[v]==-1)
					{
						dis3[v]=dis3[u]+1;
						q.push(v);
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(i!=rt)
				{
					if(dis3[i]<k)
					{
						if(g[i].size()<4)
						{
							cout<<"No\n";
							return;
						}
					}
					else if(dis3[i]==k&&g[i].size()!=1)
					{
							cout<<"No\n";
							return;
					}
				}
			}
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
