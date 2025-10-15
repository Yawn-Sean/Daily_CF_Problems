#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
vector<int> siz(N,1),fa(N,0);vector<int> cir(N,0),self(N,0);
void init(){
    for(int i=0;i<N;i++){fa[i]=i;}
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int f1=find(x),f2=find(y);
    if(f1!=f2)
    {
        fa[f1]=f2;
        self[f2]|=self[f1];
        siz[f2]+=siz[f1];
        siz[f1]=0;
    }
    else{
        cir[f2]=1;
    }
}

void solve(){
	int n;cin>>n;init();
    int x,y;vector<pair<int,int>> vp(2*n+1);
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(x==y)self[x]=1;
        vp[i]={x,y};
        merge(x,y);
    }
    //树结构为n，环结构为2，基环树为2,单点为1
    int ans=1;
    for(int i=1;i<=2*n;i++){
        if(fa[i]==i&&!self[i]){
            if(cir[i])ans=(ans*2)%mod;
            else ans=(ans*siz[i])%mod;
            // cout<<siz[i]<<" ";
        }
    }
    cout<<ans%mod<<endl;

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
