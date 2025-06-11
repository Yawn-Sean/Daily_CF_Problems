#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node{
	int w, f, idx;
} e[N];
bool cmp(node &x, node &y){
	if(x.w==y.w){
		return x.f>y.f;
	}
	return x.w<y.w;
}
int n, m, a_u[N], a_v[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>e[i].w>>e[i].f;
		e[i].idx=i;
	}
	sort(e+1, e+1+m, cmp);
	int cur=1, fm=2, to=3; 
	for(int i=1;i<=m;i++){
		int idx=e[i].idx;
		if(e[i].f){
			a_u[idx]=1, a_v[idx]=++cur;
		}else{
			if(fm==to){
				fm=2; to++;
			}
			if(to>cur){
				cout<<-1;
				return 0;
			}
			a_u[idx]=fm++, a_v[idx]=to;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a_u[i]<<" "<<a_v[i]<<"\n";
	}
	return 0;
}
