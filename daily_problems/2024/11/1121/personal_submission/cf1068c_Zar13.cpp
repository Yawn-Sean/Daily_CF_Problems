#include<bits/stdc++.h>
using namespace std;
struct node{
	int x, y;
};
int n, m;
vector<node> g[105];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) g[i].push_back({i, i});
	int a, b, idx=n;
	while(m--){
		idx++;
		cin>>a>>b;
		int x1=g[a][0].x, x2=g[b][0].x;
		g[a].push_back({x1, idx});
		g[b].push_back({x2, idx});
	}
	for(int i=1;i<=n;i++){
		cout<<g[i].size()<<endl;
		for(auto t:g[i]){
			cout<<t.x<<" "<<t.y<<endl;
		}
	}
	return 0;
}
