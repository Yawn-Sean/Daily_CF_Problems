#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+9;
//#define lowbit(x) (x&(-x))
//#define bp push_back
//#define sz size
//#define cl clear
const int maxn = 1e5+114;
map< pair<int,int> ,int> mp;
int m;
set<int> Out[maxn],In[maxn];
set<int> q;
int x[maxn],y[maxn];
bool check(int u){
	for(int v:Out[u])
		if(In[v].size()==1) return false;
	return true;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>x[i]>>y[i];
		mp[make_pair(x[i],y[i])]=i+1;
	}
	for(int i=0;i<m;i++){
		for(int dx=-1;dx<=1;dx++)
			if(mp[make_pair(x[i]+dx,y[i]+1)]!=0){
				Out[i].insert(mp[make_pair(x[i]+dx,y[i]+1)]-1);
				In[mp[make_pair(x[i]+dx,y[i]+1)]-1].insert(i);
			}
	}
	for(int i=0;i<m;i++){
		if(check(i)==true) q.insert(i);
	}
	int ans=0;
	int tot=0;
	while(q.size()>0){
		int u;
		if(tot==0){
			u=(*q.rbegin());
		}else{
			u=(*q.begin());
		}
		q.erase(u); 
		ans=(ans*m+u)%mod;
		tot^=1;
		for(int v:Out[u]){
			In[v].erase(u);
			for(int w:In[v]){
				if(check(w)==false&&q.find(w)!=q.end()) q.erase(w);
			}
		}
		for(int v:In[u]){
			Out[v].erase(u);
			if(check(v)==true&&q.find(v)==q.end()) q.insert(v);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
