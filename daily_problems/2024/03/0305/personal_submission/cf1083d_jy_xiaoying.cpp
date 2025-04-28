#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1083/A
//日期： 2024-3-5 
//格式化： ctrl+shift+ a

const int inf=INT_MIN;
typedef pair<int,int> pp;
typedef vector<pp> vv;
typedef long long ll;
int n; 
const int MAX=3e5+10;
ll val[MAX]; 
vector<vv> g;

ll ans=0;

ll dfs(int x,int fa){
	if(g[x].size()==1 && g[x][0].first==fa){
		return val[x];
	}
	
	ll big_1=inf,big_2=inf;
	for(auto p1:g[x]){
		int u=p1.first;
		ll v=p1.second;
		v=-v;
		if(u==fa) continue;
		v+=dfs(u,x);
		if(v>big_1){
			big_2=big_1;
			big_1=v;	
		}
		else if(v>big_2){
			big_2=v;
		}
	}
	
	if(big_1>=0 && big_2>=0){
		ans=max(ans,big_1+big_2+val[x]);
	}
	ans=max(ans,big_1+val[x]);
	return max(big_1+val[x],val[x]);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    ans=inf;
    for(int i=1;i<=n;i++) {
    	cin>>val[i];
    	ans=max(ans,val[i]);
	}
    
    g=vector<vv>(n+5,vv(0));
    int a,b,c;
    for(int i=1;i<n;i++){
    	cin>>a>>b>>c;
    	g[a].push_back(pp(b,c));
    	g[b].push_back(pp(a,c));
	}
	
	ll tmp=dfs(1,0);
	
	cout<<ans<<endl;

	return 0;
}


