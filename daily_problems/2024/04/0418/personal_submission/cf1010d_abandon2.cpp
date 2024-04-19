// Problem: Mars rover
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1010D
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
	int l,r;
	char op;
}tr[N];
int n,m,sx[N],ans[N],st[N];//是否需要改变

int dfs(int u){
	if(tr[u].op=='I')return ans[u]=tr[u].l;//到达叶子节点
	if(tr[u].op=='A')return ans[u]=dfs(tr[u].l)&dfs(tr[u].r);
	if(tr[u].op=='O')return ans[u]=dfs(tr[u].l)|dfs(tr[u].r);
	if(tr[u].op=='X')return ans[u]=dfs(tr[u].l)^dfs(tr[u].r);
	if(tr[u].op=='N')return ans[u]=!dfs(tr[u].l);
	return 1;
}

void change(int u){
	if(tr[u].op=='I')st[u]=1;//说明这个节点需要更改
	if(tr[u].op=='A'){
		if(ans[tr[u].l]==1&&ans[tr[u].r]==0)change(tr[u].r);
		if(ans[tr[u].l]==0&&ans[tr[u].r]==1)change(tr[u].l);
		if(ans[tr[u].l]==1&&ans[tr[u].r]==1)change(tr[u].r),change(tr[u].l);
	}
	if(tr[u].op=='O'){
		if(ans[tr[u].l]==1&&ans[tr[u].r]==0)change(tr[u].l);
		if(ans[tr[u].l]==0&&ans[tr[u].r]==1)change(tr[u].r);
		if(ans[tr[u].l]==0&&ans[tr[u].r]==0)change(tr[u].r),change(tr[u].l);
	}
	if(tr[u].op=='X')change(tr[u].r),change(tr[u].l);
	if(tr[u].op=='N')
		change(tr[u].l);
}


void solve(){
	memset(sx,-1,sizeof sx);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		if(s=="AND"){
			int l,r;cin>>l>>r;
			tr[i]={l,r,'A'};
		}
		if(s=="IN"){
			int x;cin>>x;
			tr[i]={x,0,'I'};
			sx[i]=x;//叶子节点
		}
		if(s=="OR"){
			int l,r;cin>>l>>r;
			tr[i]={l,r,'O'};
		}
		if(s=="XOR"){
			int l,r;cin>>l>>r;
			tr[i]={l,r,'X'};
		}
		if(s=="NOT"){
			int l;cin>>l;
			tr[i]={l,0,'N'};
		}
	}
	dfs(1);
	change(1);
	
	for(int i=1;i<=n;i++){
		if(ans[1]==0){
			if(sx[i]!=-1){
				cout<<st[i];
			}
		}
		else{
			if(sx[i]!=-1)
			cout<<!st[i];
		}
	}

	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


