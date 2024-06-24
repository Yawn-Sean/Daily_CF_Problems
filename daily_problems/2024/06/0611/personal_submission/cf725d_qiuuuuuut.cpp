#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n,a[N],b[N];
struct cmp1
{
    bool operator()(auto&x,auto&y){
        if(x.first!=y.first) return x.first<y.first;
        return x.second-x.first>y.second-y.first;
    }
};
struct cmp2
{
    bool operator()(auto&x,auto&y){
        return x.second-x.first>y.second-y.first;
    }
};
void solve()
{
	cin>>n;
	priority_queue<PII,vector<PII>,cmp1>q1;
	priority_queue<PII,vector<PII>,cmp2>q2;
	cin>>a[1]>>b[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]>a[1])
		{
			q2.push({a[i],b[i]});
		}
		else q1.push({a[i],b[i]});
	}
	int ans=q2.size()+1;
	for(int i=1;i<=n;i++)
	{
		if(q2.size())
		{
			int x=q2.top().first,y=q2.top().second;
			if(a[1]>y-x)
			{
				q2.pop();
				a[1]-=y-x+1;
				while(q1.size()&&q1.top().first>a[1]) 
				{
					auto t=q1.top();q1.pop();
					q2.push(t);
				}
			}
			ans=min(ans,(long long)q2.size()+1);
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
 } 
