#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n,m,root;
bool ok=1;
vector<int>g[N];
int cnt[N];
vector<int>ans;
vector<int> dfs(int x)
{
	if(!ok) return {};
	vector<int>v;
	for(int &y:g[x])
	{
		for(int &t:dfs(y)) v.push_back(t);
	}
	sort(v.begin(),v.end(),[&](int i,int j){
		return ans[i]<ans[j];
	});
	if(v.size()<cnt[x])
	{
		ok=0;return {};
	}
	for(int i=0;i<cnt[x];i++) ans[v[i]]=i+1;
	ans[x]=cnt[x]+1;
	for(int i=cnt[x];i<v.size();i++) ans[v[i]]=i+2;
	v.push_back(x);
	return v;
}
void solve()
{
	cin>>n;
	ans.resize(n);
	for(int i=0;i<n;i++)
	{
		int j;
		cin>>j;
		j--;cin>>cnt[i];
		if(j>=0) g[j].push_back(i);
		else root=i;
	}
	dfs(root);
	if(!ok) cout<<"NO";
	else 
	{
		cout<<"YES"<<endl;
		for(int x:ans) cout<<x<<" "; 
	}
}
signed main()
{
	int T=1;
	while(T--) solve();
	return 0;
 } 
