#include<bits/stdc++.h>
using namespace std;
int a[10],b[30]; //如题意
bool ans[6][30];//保存答案
int nowc[6][30];//这一行现在纵向连通块个数
int w[30];//遍历每一种情况的临时数组
int n,m;//如题意 
int trie[30][1000006][2];//各个行连通块所要的 01trie
int f[30];//各个行连通块所要的 01trie 末编号
void insert(int o,int p){//01trie 插入
	//o：01trie 编号
	//p：要插入的值 
	int now=0;
	for(int i=1;i<=m;i++){
		int r=(p>>i)&1;
		if(trie[o][now][r]==0)trie[o][now][r]=++f[o];
		now=trie[o][now][r];
	}
}
void dfs(int dep,int now,int j,int at){
	//dep：当前搜索的行号
	//now：当前搜索的列号
	//j：当前这一行的值
	//at：当前在这个 01trie 的编号
	//可以用 trie[a[dep]] 来找到这一行对应的 trie
	if(dep==n+1){//搜索到结束 
		for(int j=1;j<=m;j++){//判断是否合法
			if(nowc[n][j]!=b[j])return;
		}
		for(int i=1;i<=n;i++){//输出方案
			for(int j=1;j<=m;j++){
				if(ans[i][j])cout<<'*';
				else cout<<'.';
			}
			cout<<endl;
		}
		exit(0);//结束
	}
	if(now==m+1){//这一行搜索到结束
		int y=j;
		for(int j=1;j<=m;j++)ans[dep][j]=(y>>j)&1;
		for(int j=1;j<=m;j++){//统计连通块数量 
			if(ans[dep][j]&&!ans[dep-1][j]){
				nowc[dep][j]=nowc[dep-1][j]+1;
			}else{
				nowc[dep][j]=nowc[dep-1][j];
			}
		}
		bool t=true; 
		for(int j=1;j<=m;j++){
			//(n-dep+1-ans[dep][j])/2：理论最多还能加上的连通块的个数。
			//如果不满足要求，那么没有必要搜索了。
			if(nowc[dep][j]>b[j]||nowc[dep][j]+(n-dep+1-ans[dep][j])/2<b[j]){
				t=false;
				break;
			}
		}
		if(t)dfs(dep+1,1,0,0);
		return;
	}
	bool t=rand()%2;//随机分支 
	if(t)if(trie[a[dep]][at][0])dfs(dep,now+1,j,trie[a[dep]][at][0]);
	if(ans[dep-1][now]||nowc[dep-1][now]!=b[now]){ 
		//即：如果上一行是空的，或者这一列的连通块数量没有达到极限，
		//且下一步可行，那么向下搜索。
		if(trie[a[dep]][at][1])dfs(dep,now+1,j+(1<<now),trie[a[dep]][at][1]);
	}
	if(!t)if(trie[a[dep]][at][0])dfs(dep,now+1,j,trie[a[dep]][at][0]);
}
int main(){
	srand(time(0));//随机化 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=0;i<1<<m;i++){//遍历每一种情况 
		int y=i<<1;//将 0-(m-1) 区间转换成 1-m 区间 
		int q=0;
		for(int j=1;j<=m;j++)w[j]=(y>>j)&1; 
		for(int j=1;j<=m;j++)if(w[j]&&!b[j])continue;//如果有 0 的位置，那么就这一列什么都不能放。
		for(int j=1;j<=m;j++)if(w[j]&&!w[j-1])q++;//统计这一行的连通块数量 
		insert(q,y);//插入到对应的 trie 中
	}
	dfs(1,1,0,0); //开始搜索
	//cout<<-1; 
	return 0;
}
