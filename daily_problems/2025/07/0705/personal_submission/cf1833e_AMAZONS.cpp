#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
int fa[N],size[N];
void init(){
    for(int i=0;i<N;i++){
        fa[i]=i;
    }
}
int find(int x) {

    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(x == y) return;
    fa[x] = y;
}
void solve(){
	int n;cin>>n;init();
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        merge(i,v[i]);
    }
    set<int> s;set<pair<int,int>> ss;
    int flag=1;int deg[n+1]={0};
    for(int i=1;i<=n;i++){
        ss.insert({min(v[i],i),max(v[i],i)});
        if(i==v[v[i]]){
            flag=2;
        }
    }
    
    for(auto &it:ss){
        deg[it.first]++;
        deg[it.second]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            cnt++;
        }
    }
    int ans2=0;
    for(int i=1;i<=n;i++){
        s.insert(fa[i]);
        if(fa[i]==i){
            ans2++;
        }
    }

    int ans1=ans2+1-cnt/2;
    // cout<<cnt<<endl;
    if(cnt==0)ans1=ans2;
    cout<<ans1<<" "<<ans2<<endl;
    

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {solve();}
    return 0;
}
