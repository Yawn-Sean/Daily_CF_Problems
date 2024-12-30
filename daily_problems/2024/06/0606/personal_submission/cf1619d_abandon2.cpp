#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int f[N];
struct node {
    int x,y,t,id;
}a[N];

int find(int x){
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}

void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    f[x]=y;
}

void solve(){
    //getchar();
    int n,k;cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].t;
        f[i]=i;
        a[i].id=i;
    }  

    sort(a+1,a+1+n,[&](node c,node d)->int{
        if(c.x==d.x)return c.y<d.y;
        return c.x<d.x; 
    });
    for(int i=1;i<n;i++){
        if(a[i].x==a[i+1].x&&a[i+1].y-a[i].y<=k){
            
            merge(a[i].id,a[i+1].id);
        }
    }

    sort(a+1,a+1+n,[&](node c,node d){
        if(c.y==d.y)return c.x<d.x;
        return c.y<d.y; 
    });
    for(int i=1;i<n;i++){
        if(a[i].y==a[i+1].y&&a[i+1].x-a[i].x<=k){
            //cout<<a[i].id<<" "<<a[i+1].id<<"  ccc\n";
            merge(a[i].id,a[i+1].id);
        }
    }
    std::vector<int> vis(n+1,0),ti(n+10,1e9);
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x=find(a[i].id);
        if(!vis[x]){
            vis[x]=++cnt;
        }
        ti[vis[x]]=min(ti[vis[x]],a[i].t);
        //cout<<vis[x]<<" "<<ti[vis[x]]<<" \n";
    }
    //cout<<cnt<<"\n";
    sort(ti.begin()+1,ti.begin()+cnt+1,greater<int>());
    // for(int i=1;i<=cnt;i++){
    //     cout<<ti[i]<<" ";
    // }
    for(int i=cnt+1;i<=n+9;i++)ti[i]=0;
    //cout<<"ccc\n";
    for(int i=0;i<=cnt;i++){
        if(ti[i+2]<=i){
            cout<<i<<"\n";return;
        }
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;while(tt--)
    solve();
    return 0;
}
