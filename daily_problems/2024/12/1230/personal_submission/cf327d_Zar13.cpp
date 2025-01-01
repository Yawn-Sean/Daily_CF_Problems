#include<bits/stdc++.h>
using namespace std;
const int N=505;
char g[N][N];
bool vis[N][N];
struct node{
	char c;
	int x, y;
} op[1000005];
int n, m, idx;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x, int y, int fx, int fy){
	op[++idx]={'B', x, y};
	for(int i=0;i<4;i++){
		int xx=x+dx[i], yy=y+dy[i];
		if(xx>0&& xx<=n&& yy>0&& yy<=m&& vis[xx][yy]==0&& (xx!=fx|| yy!=fy)&& g[xx][yy]=='.'){
			vis[xx][yy]=1;//
			dfs(xx, yy, x, y);			
		}
	}
	if(fx!=-1|| fy!=-1){
		op[++idx]={'D', x, y};
		op[++idx]={'R', x, y};
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!vis[i][j]&& g[i][j]=='.'){
				vis[i][j]=1;//
                dfs(i, j, -1, -1);
			}
		}
	}
	cout<<idx<<"\n";
	for(int i=1;i<=idx;i++){
		cout<<op[i].c<<" "<<op[i].x<<" "<<op[i].y<<"\n";
	}
	return 0;
}
