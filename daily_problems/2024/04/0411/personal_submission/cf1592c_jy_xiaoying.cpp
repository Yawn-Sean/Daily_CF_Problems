#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1592/C

//      dfs + 转化-思维 + 异或性质
//思路：

//日期：  2024-4-11
//格式化： ctrl+shift+ a


const int MAX=2e5+10;
typedef long long ll;
typedef vector<int> vv;
int t;
int n,k;
vector<vv> g;
int nums[MAX];
int x_or;
bool ans[MAX];
int orz[MAX];

int cnts;

void dfs(int i,int fa) {
	orz[i]=nums[i];
	for(int son:g[i]) {
		if(fa==son) continue;
		dfs(son,i);
		if(orz[son]==x_or)     //断开符合条件的子树 
		     cnts++;
		else                        
			orz[i]^=orz[son];
	}
}

bool solve() {
	if(x_or==0) return 1;
	if(k==2) return 0;

	dfs(1,0);

	//cout<<x_or<<" "<<cnts<<endl;

	if(cnts>=2) return 1;
	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>n>>k;
		g=vector<vv>(n+1,vv());
		x_or=0,cnts=0;

		for(int j=1; j<=n; j++) {
			cin>>nums[j];
			x_or^=nums[j];
		}
		int a,b;
		for(int j=0; j<n-1; j++) {
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		ans[i]=solve();
	}

	for(int i=0; i<t; i++) {
		if(ans[i]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
/*
1
9 8
206683326 87040721 87040721 435543150 514117915 161349195 479545068 479613837 128874544
4 1
2 4
1 5
8 1
5 7
8 3
4 6
1 9

ans:YES

*/

