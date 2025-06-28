#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1076/E

//   dfs + 撤销操作 

//日期： 2024-3-15
//格式化： ctrl+shift+ a

const int MAX=3e5+10;
typedef long long ll;
typedef pair<int,ll> pp;
typedef vector<int> vv;

ll sub[MAX];
ll ans[MAX];
vector<vv> g;
vector<vector<pp>> works;
int n,m;

void dfs(int x,int fa,ll sum,int h) { //来到节点x 高度为y
	sum+=sub[h];
	for(auto p1:works[x]) {
		int down=min(n+1,h+p1.first+1);
		sub[down]-=p1.second;
		sum+=p1.second;
	}
	ans[x]=sum;
	for(int child:g[x]) {
		if(child==fa) continue;
		dfs(child,x,sum,h+1);
	}
    
    //撤销操作 
	for(auto p1:works[x]) {
		int down=min(n+1,h+p1.first+1);
		sub[down]+=p1.second;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	g=vector<vv> (n+5,vv());
	works=vector<vector<pp>> (n+5,vector<pp>());

	int x,y;
	for(int i=1; i<n; i++) {
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}


	cin>>m;
	int id,down;
	ll val;
	for(int i=0; i<m; i++) {
		cin>>id>>down>>val;
		works[id].push_back(pp(down,val));
	}

	dfs(1,0,0,1);

	for(int i=1; i<=n; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}
/*
7
6 7
7 5
3 2
7 2
2 1
1 4
3
5 3 1
7 6 4
4 3 2

0 0 0 2 5 4 4

*/

