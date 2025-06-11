//链接：https://codeforces.com/problemset/problem/1286/B

#include<bits/stdc++.h>  
using namespace std;

static const int MAX=2020;
typedef vector<int> vv;
vector<vv> g(MAX);
int cnt[MAX];
int ans[MAX];

int n;
int root;
bool flg;

void build(){
      for(int i=0;i<=n;i++){
      	   g[i].clear();
      	   ans[i]=0;
	  }
	  flg=1;
}

void dfs(int x){
	vector<int> tmp;
	for(int u:g[x]){
		dfs(u);
		for(int v:g[u]) tmp.push_back(v);
	}
	
	for(int v:tmp) g[x].push_back(v);
	
	int k=g[x].size();
	if(k<cnt[x]) flg=0;
	else{
		sort(g[x].begin(),g[x].end(),[&](int a,int b){
			return ans[a]<ans[b];
		});
		for(int i=0;i<cnt[x];i++) {
			int u=g[x][i];
			ans[u]=i+1;
		}
		ans[x]=cnt[x]+1;
		for(int i=cnt[x];i<k;i++){
			int u=g[x][i];
			ans[u]=i+2;
		}
	}
}

void f(){
	dfs(root);
	if(flg){
		cout<<"YES"<<"\n";
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	else{
		cout<<"NO"<<"\n";
	}
}

int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin>>n;
	build();
	int fa=0;
	for(int i=1;i<=n;i++){
		cin>>fa>>cnt[i];
		if(fa==0) root=i;
		else  g[fa].push_back(i);
	}
	
	f();
	return 0;
}


/*

6
6 1
1 3
2 1
3 0
2 0
0 2
  



*/
