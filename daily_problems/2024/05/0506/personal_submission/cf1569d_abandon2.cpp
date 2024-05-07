#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
typedef pair<int,int>PII;
typedef long long LL;
int x[N],y[N];
 
void solve(){
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
 
	vector<PII>xx,yy;
	vector<LL>cntx(n+1),cnty(m+1);
	for(int i=1;i<=m;i++)
		cin>>y[i];
	for(int i=1;i<=k;i++){
		int u,v;cin>>u>>v;
		int fx=binary_search(x+1,x+1+n,u);
		int fy=binary_search(y+1,y+1+m,v);
		if(fx&&fy)continue;//在焦点上一定不是
		if(fx){//在x上
			int p=lower_bound(y+1,y+1+m,v)-y-1;//查找离他最近的y的坐标
			cnty[p]++;xx.push_back({u,p});
		}
		else{
			int p=lower_bound(x+1,x+1+n,u)-x-1;//查找离他最近的y的坐标
			cntx[p]++;yy.push_back({v,p});
		}
	}
	LL res=0;
	for(int i=1;i<=n;i++){
		res+=(cntx[i]-1)*cntx[i]/2;
	}
	for(int i=1;i<=m;i++){
		res+=(cnty[i]-1)*cnty[i]/2;
	}

	for(auto p:{xx,yy}){
		sort(p.begin(),p.end());
		for(int l=0,r;l<(int)(p.size());l=r){
			//cout<<p[l].first<<" "<<p[r].first<<"\n";
		    for(r=l;r<(int)(p.size())&&p[l]==p[r];r++);
		    res-=1ll*(r-l)*(r-l-1)/2;
		}
		
	}
	cout<<res<<"\n";
 
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--)
		solve();
	return 0;
}
