/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100010;

struct Node{
    int x,y,ex,ey,id;
}a[N],b[N];

bool cmp(Node l,Node r){
    return l.x+l.y>r.x+r.y or (l.x+l.y==r.x+r.y and l.x-l.y>r.x-r.y);
}

bool cmp1(Node l,Node r){
	return l.x+l.y>r.x+r.y or (l.x+l.y==r.x+r.y and l.ex-l.ey>r.ex-r.ey);
}

void solve(){
    int n,w,h;
    std::cin>>n>>w>>h;
    for(int i=1;i<=n;i++){
        int g,p,t;
        std::cin>>g>>p>>t;
        if(g==1) a[i]={p,-t,p,h,i};
        else a[i]={-t,p,w,p,i};
        b[i]=a[i];
    }
    std::sort(a+1,a+n+1,cmp);
    std::sort(b+1,b+n+1,cmp1);

    std::vector<int> rx(n+2),ry(n+2);

    for(int i=1;i<=n;i++){
        rx[a[i].id]=b[i].ex;
        ry[a[i].id]=b[i].ey;
    }
    for(int i=1;i<=n;i++){
        std::cout<<rx[i]<<" "<<ry[i]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
