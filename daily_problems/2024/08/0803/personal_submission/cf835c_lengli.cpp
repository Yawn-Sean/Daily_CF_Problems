/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

template<class T>
struct presum_dynamic{
    std::vector<std::vector<T>> c1, c2, c3, c4;
    int szx,szy;
    presum_dynamic() {}
    presum_dynamic(int n,int m){init(n, m);}
    void init(int n, int m) {
        szx=n;szy=m;
    	c1.clear(),c2.clear(),c3.clear(),c4.clear();
        c1.resize(n+2,std::vector<T> (m+2,0));
        c2.resize(n+2,std::vector<T> (m+2,0));
        c3.resize(n+2,std::vector<T> (m+2,0));
        c4.resize(n+2,std::vector<T> (m+2,0));
    }
    void modify(int x, int y, T s) {
        for(int i=x;i<=szx;i+=(i&-i)){
            for(int j=y;j<=szy;j+=(j&-j)) {
                c1[i][j]+=s;
                c2[i][j]+=s*y;
                c3[i][j]+=s*x;
                c4[i][j]+=s*x*y;
            }
        }
    }
    T query(int x, int y) {
        T s = 0;
        for(int i=x;i;i-=(i&-i)){
            for(int j=y;j;j-=(j&-j)) {
                s+=c1[i][j]*(x+1)*(y+1);
                s-=c2[i][j]*(x+1);
                s-=c3[i][j]*(y+1);
                s+=c4[i][j];
            }
        }
        return s;
    }
    void recmodify(int a, int b, int c, int d,T s) {
        modify(a,b,s);
        modify(a,d+1,-s);
        modify(c+1,b,-s);
        modify(c+1,d+1,s);
    }
    T recquery(int a, int b, int c, int d) {
        return query(c,d)-query(a-1,d)-query(c,b-1)+query(a-1,b-1);
    }
};

void solve(){
    int n,q,c;
    std::cin>>n>>q>>c;
    presum_dynamic<int> tr[11];
    for(int i=0;i<=10;i++) tr[i].init(105,105);
    for(int i=1;i<=n;i++){
        int x,y,s;
        std::cin>>x>>y>>s;
        tr[s].recmodify(x,y,x,y,1);
    }
    for(int i=1;i<=q;i++){
        int t,l,r,ll,rr;
        std::cin>>t>>l>>r>>ll>>rr;
        int res=0;
        for(int i=0;i<=10;i++){
            int v=(i+t)%(c+1);
            res+=tr[i].recquery(l,r,ll,rr)*v;
        }
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
