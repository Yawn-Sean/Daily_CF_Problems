#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/739/B

//   st倍增 + 树上差分 
//

//日期： 2024-4-2
//格式化： ctrl+shift+ a

const int MAX=2e5+10;
const int MAX_M=18;
typedef long long ll;
typedef pair<int,ll> pp;
typedef vector<pp> vv;

int st[MAX][MAX_M];
ll st_sum[MAX][MAX_M];
ll ans[MAX];
int h[MAX];             //树的高度  

int n;
ll nums[MAX];
vector<vv> g;

int log_2(int x) {
	int ans=0;
	while((1<<ans) <= (x>>1)) {
		ans++;
	}
	return ans;
}

void dfs(int cur,int fa,ll dist) {
	st[cur][0]=fa;
	st_sum[cur][0]=dist;
	h[cur]=h[fa]+1;
	for(int i=1; (1<<i)<=h[cur] ; i++) {
		int tmp=st[cur][i-1];
		st[cur][i]=st[tmp][i-1];
		st_sum[cur][i]=st_sum[cur][i-1]+st_sum[tmp][i-1];
	}
	for(pp p:g[cur]) {
		int son=p.first;
		ll len=p.second;
		if(son==fa) continue;
		dfs(son,cur,len);
	}
}

void get_ans(int x,ll dist) {
	if(st_sum[x][0]>dist)
		return ;
	
	ans[st[x][0]]+=1;   //最初 x 的父节点 +1 
	 
	int k=log_2(h[x]);

	for(int i=k;i>=0;i--){    //找路径距离 <=dist 的最远祖先 
		ll tmp=st_sum[x][i];
		if(tmp<=dist && st[x][i]!=0 ){  //不能跳出树的头节点 
			dist-=tmp;
			x=st[x][i];
		}
	}	
	
	x=st[x][0];   // 满足 <=dist 的最远祖先的 父节点 -1 
	ans[x]-=1; 
}

void dfs_2(int cur,int fa){
	for(pp p:g[cur]){
		int son=p.first;
		if(son==fa) continue;
		
		dfs_2(son,cur);
		ans[cur]+=ans[son];
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	g=vector<vv>(n+2,vv());
	
	for(int i=1; i<=n; i++) {
		cin>>nums[i];
	}
	int fa;
	ll dist;
	for(int i=2; i<=n; i++) {
		cin>>fa>>dist;
		g[fa].push_back(pp(i,dist));
		g[i].push_back(pp(fa,dist));
	}
    
    h[0]=0;
	dfs(1,0,INT_MAX);
	for(int i=2; i<=n; i++) {
		get_ans(i,nums[i]);
	}
	
	dfs_2(1,0);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}
/*
7
3 3 4 7 8 9 6
1 3
1 1
3 3
3 12
4 4
4 3


*/

