#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1012/B

//  思维+并查集 
//

//日期： 2024-3-26
//格式化： ctrl+shift+ a

const int MAX=4e5+100;
typedef long long ll;

int fa[MAX];
int n,m,q;

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
} 

int U_union(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y){
		return 0;
	}
	fa[x]=y;
	return 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m>>q;
	int ans=n+m;   //起始一共 n+m 个集合 
	
	for(int i=0;i<=n+m+10;i++) fa[i]=i;
	int x,y;
	for(int i=0;i<q;i++){
		cin>>x>>y;
		ans-=U_union(x,y+n);
	}

    cout<<ans-1<<endl;    	//剩下 ans 个集合，添加 ans-1 条边连接即可 


	return 0;
}
/*


*/

