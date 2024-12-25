#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int fa[N];
int find(int x){
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
int op[105], idx;
int main(){
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=2*n;i++) fa[i]=i;
	while(m--){
		int a, b, c;
		cin>>a>>b>>c;
		if(c){
			if(find(a)==find(b+n)){
				cout<<"Impossible";
				return 0;
			}
			fa[find(a)]=find(b);
			fa[find(a+n)]=find(b+n);
		}else{
			if(find(a)==find(b)){
				cout<<"Impossible";
				return 0;
			}
			fa[find(a)]=find(b+n);
			fa[find(a+n)]=find(b);
		}
	}
	op[++idx]=1;
//	for(int i=2;i<=n;i++){
//		if(find(1)==find(i)) op[++idx]=i;
//	}
	for(int i=2;i<=n;i++){
		bool fg=1;
		for(int j=1;j<=idx;j++){
			if(find(i)==find(op[j]+n)){
				fg=0;
				break;
			}
		}
		if(fg) op[++idx]=i;
	}
    //整个图不一定连通，可能有多个连通块
	cout<<idx<<endl;
	for(int i=1;i<=idx;i++) cout<<op[i]<<" ";
	return 0;
}
