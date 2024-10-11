#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int n, k, m;
int c[N];
int p[N];
int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a, int b){
	int pa=find(a), pb=find(b);
	if(pa!=pb){
		p[pa]=pb;
	}
}
vector<int> a[N];
int main(){
	cin>>n>>m>>k;
	vector<int> ta(N, 0);
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
	}
	int l,r;
	for(int i=1;i<=m;i++){
		cin>>l>>r;
		merge(l, r);
	}
	for(int i=1;i<=n;i++){
		int pi=find(i);
		a[pi].push_back(c[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int s=a[i].size();
		if(s<=1) continue;
		sort(a[i].begin(), a[i].end()); 
		int maxt=0, t=1;
		a[i].push_back(-1);
		for(int j=1;j<=s;j++){
			if(a[i][j]!=a[i][j-1]){
				maxt=max(maxt, t);
				t=1;
			}else{
				t++;
			}
		}
		ans+=s-maxt;
	}
	cout<<ans;
	return 0;
}
