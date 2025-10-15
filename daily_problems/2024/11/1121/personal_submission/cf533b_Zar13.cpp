#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
vector<int> g[N];
int a[N], n;
void dfs(int u, int fa, LL &sum0, LL &sum1){
	LL t_s0=0, t_s1=-1e15, q_s0, q_s1;//一开始不存在任何选取奇数个节点的方法，因此应当置为 -inf
	for(auto v:g[u]){
		if(v==fa) continue;
		dfs(v, u, q_s0, q_s1);
		LL t=t_s0;
		t_s0=max(t_s0+q_s0, t_s1+q_s1);
		t_s1=max(t+q_s1, t_s1+q_s0);
	}
	sum0=t_s0;
	sum1=max(t_s1, t_s0+a[u]);
//	cout<<"u:"<<u<<"  s0:"<<sum0<<"  s1:"<<sum1<<endl;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	int p;
	int max_a=0;
	for(int i=1;i<=n;i++){
		cin>>p>>a[i];
		if(p!=-1) g[p].push_back(i);
	}
	LL s1, s2;
	dfs(1, -1, s1, s2);
	cout<<max(s1, s2);
	return 0;
}
