/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

template<typename T> struct set{
    int rt,tot;
    std::vector<int>fix,sz,ls,rs,rub;
    std::vector<T> val;
    set():rt(0),tot(0) {
        fix.clear(),sz.clear(),ls.clear(),rs.clear(),rub.clear(),val.clear();
    }
    inline int new_node(T x){
        int p;
        if(rub.empty())p=++tot,fix.resize(p+1),sz.resize(p+1),ls.resize(p+1),rs.resize(p+1),val.resize(p+1);
        else p=*rub.rbegin(),rub.pop_back();
        fix[p]=rand(),val[p]=x,ls[p]=rs[p]=0,sz[p]=1;
        return p;
    }
    inline int size(){return tot-rub.size();}
    inline bool empty(){return tot==rub.size();}
    inline void clear(){
        rt=0,tot=0;
        fix.clear(),sz.clear(),ls.clear(),rs.clear(),rub.clear(),val.clear();
    }
    inline void upd(int x){
        sz[x]=1+sz[ls[x]]+sz[rs[x]];
    }
    int merge(int x,int y){
        if(!x || !y)return x|y;
        if(fix[x]<fix[y])return rs[x]=merge(rs[x],y),upd(x),x;
        else return ls[y]=merge(x,ls[y]),upd(y),y;
    }
    void split(int p,T a,int &x,int &y){
        if(!p){x=y=0;return;}
        if(val[p]<=a)x=p,split(rs[p],a,rs[p],y);
        else y=p,split(ls[p],a,x,ls[p]);
        upd(p);
    }
    inline T kth(int k){
        int x=rt;
        while(x){
            if(k<=sz[ls[x]])x=ls[x];
            else if(k==sz[ls[x]]+1)return val[x];
            else k-=sz[ls[x]]+1,x=rs[x];
        }
        return -1;
    }
    inline void insert(T val){
        int x,y;
        split(rt,val-1,x,y);
        rt=merge(merge(x,new_node(val)),y);
    }
    inline void erase(T val){
        int x,y,z;
        split(rt,val-1,x,y),split(y,val,y,z);
        if(y)rub.push_back(y);
        rt=merge(merge(x,merge(ls[y],rs[y])),z);
    }
    inline int rank(T val){
        int x,y;T ans;
        split(rt,val-1,x,y);
        ans=sz[x]+1,rt=merge(x,y);
        return ans;
    }
    inline T pre(T val){
        int x,y;T ans;
        split(rt,val-1,x,y);
        if(!x)return -1;
        rt=x,ans=kth(sz[x]),rt=merge(x,y);
        return ans;
    }
    inline T nxt(T val){
        int x,y;T ans;
        split(rt,val,x,y);
        if(!y)return -1;
        rt=y,ans=kth(1),rt=merge(x,y);
        return ans;
    }
};

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for(int i=0;i<n;i++) std::cin>>a[i];
    
    std::map<int,int> ls,rs;

    set<int> s;
    s.insert(a[0]);
    for(int i=1;i<n;i++){
        int x=a[i];
        int pr=s.pre(x);
        int ne=s.nxt(x);

        if(pr!=-1){
            if(!rs.count(pr)){
                rs[pr]=x;
                std::cout<<pr<<" ";
            }
        }
        if(rs[pr]!=x){
            ls[ne]=x;
            std::cout<<ne<<" ";
        }

        s.insert(x);
    }

    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
