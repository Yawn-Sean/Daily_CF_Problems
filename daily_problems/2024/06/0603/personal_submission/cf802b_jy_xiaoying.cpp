//链接：https://codeforces.com/problemset/problem/802/B
//      https://codeforces.com/problemset/problem/802/A

#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int MAX=4e5+10;
typedef vector<int> vv;
typedef pair<int,int> pp;

vector<vv> st(MAX);
int arr[MAX];
bool vis[MAX];

int pos[MAX];
bool del[MAX];                            //是否得懒删除 
int n,k;
const int inf=INT_MAX/4;

void build(){                           //初始化+预处理 
	for(int i=0;i<=n;i++){
		st[i].clear();
		st[i].push_back(inf);                //哨兵 
		
		vis[i]=del[i]=0;
		pos[i]=-1;
	}
	for(int i=n;i>=1;i--){
		int u=arr[i];
		st[u].push_back(i);
	}
}


void f(){
	int ans=0;
	auto comp=[](const pp &a,const pp &b){
		return a.y<b.y;
	};
	
	priority_queue<pp,vector<pp>,decltype(comp)> q(comp);
	int cnt=0;
	
	for(int i=1;i<=n;i++){
		int u=arr[i];
		if(vis[u]){
			del[pos[u]]=1;                  //懒删除 
			pos[u]=i;
			st[u].pop_back();
			q.push(pp(i,st[u].back()));
			continue;
		}
		
		ans++;
		while(cnt==k){
			int v=q.top().x;
			q.pop();
			if(!del[v]) {              //懒删除
			    cnt--;
			    vis[arr[v]]=0;
		  }
		}
		
		st[u].pop_back();
		pos[u]=i;
		cnt++;
		vis[u]=1;
		q.push(pp(i,st[u].back()));
	}

	cout<<ans<<"\n";
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	build();
	f();
	return 0;
} 

/*

11 1
1 2 3 5 1 10 10 1 1 3 5

9


80 4
9 9 2 6 3 10 2 5 4 9 6 7 5 5 3 8 5 3 2 10 7 8 5 3 4 9 4 3 9 5 
2 10 8 4 7 3 8 3 5 2 3 7 8 4 2 4 4 7 2 2 5 7 5 8 
10 10 5 1 1 3 5 2 10 8 7 9 7 4 8 3 2 8 7 9 10 9 7 1 5 5

34
*/
