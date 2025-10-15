#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,m,c[N];
vector<int>e[N];
int dfs(int x,int y){
	c[x]=y;
	for(int i:e[x]){
		if(c[i]==y)return 1;
		if(c[i])continue;
		if(dfs(i,3-y))return 1;
	}
	return 0;
}
void Alice(){
	cout<<"Alice"<<endl;
	for(int i=0;i<n;i++){
		cout<<"1 2"<<endl;
		int x,y;
		cin>>x>>y;
	}
}
void Bob(){
	cout<<"Bob"<<endl;
	int p=1,q=1;
	while(p<=n&&c[p]!=1)p++;
	while(q<=n&&c[q]!=2)q++;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(x==1||y==1){
			if(p<=n)cout<<p++<<" 1"<<endl;
			else cout<<q++<<' '<<x+y-1<<endl;
		}
		else{
			if(q<=n)cout<<q++<<" 2"<<endl;
			else cout<<p++<<' '<<x+y-2<<endl;
		}
		while(p<=n&&c[p]!=1)p++;
		while(q<=n&&c[q]!=2)q++;
	}
}
int main(){
	for(cin>>t;t;t--){
		cin>>n>>m;
		int tt=0;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++)c[i]=0;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
			if(!c[i])
				if(dfs(i,1)){
					tt=1;
					break;
				}
		if(tt)Alice();
		else Bob();
	}
	return 0;
}
