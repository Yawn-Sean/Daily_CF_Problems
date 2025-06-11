#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int p[N], v[N];
void dfs(int u, int cnt){
	v[u]=cnt;
	if(v[p[u]]==0) dfs(p[u], cnt);
}
int main(){
	int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];  
    }
    int ans=0, cnt=0;
    for(int i=1;i<=n;i++){
        if(v[i]==0) dfs(i, ++cnt);
    }
    if(cnt>1) ans=cnt;
    int res=0;
    int t;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t) res++;
    }
    ans+=(res%2==0);
    cout<<ans;
	return 0;
}
