/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> res(2,std::vector<int>(4,-1));

    auto query=[&](int l,int r,int a,int b){
        std::cout<<"? "<<l<<" "<<r<<" "<<a<<" "<<b<<std::endl;
        int x;
        std::cin>>x;
        return x;
    };

    auto get=[&](int a,int b,int x,int y){
        std::vector<int> ans(4);
        {
            int l=a,r=x;
            while(l<r){
                int mid=(l+r+1)/2;
                int v=query(mid,b,x,y);
                if(v>=1) l=mid;
                else r=mid-1;
            }
            ans[0]=l;
        }
        {
            int l=a,r=x;
            while(l<r){
                int mid=(l+r)/2;
                int v=query(a,b,mid,y);
                if(v>=1) r=mid;
                else l=mid+1;
            }
            ans[2]=r;
        }
        {
            int l=b,r=y;
            while(l<r){
                int mid=(l+r+1)/2;
                int v=query(a,mid,x,y);
                if(v>=1) l=mid;
                else r=mid-1;
            }
            ans[1]=l;
        }
        {
            int l=b,r=y;
            while(l<r){
                int mid=(l+r)/2;
                int v=query(a,b,x,mid);
                if(v>=1) r=mid;
                else l=mid+1;
            }
            ans[3]=r;
        }
        return ans;
    };

    auto xx=[&](){
        int l=1,r=n;
        while(l<r){
            int mid=(l+r+1)/2;
            int v=query(mid,1,n,n);
            if(v>=1) l=mid;
            else r=mid-1;
        }
        if(query(l,1,n,n)!=1 or query(1,1,l-1,n)!=1) return;
        res[0]=get(1,1,l-1,n);
        res[1]=get(l,1,n,n);
    };
	auto yy=[&](){
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)/2;
            int v=query(1,1,n,mid);
            if(v>=1) r=mid;
            else l=mid+1;
        }
        if(query(1,1,n,r)!=1 or query(1,r+1,n,n)!=1) return;
        res[0]=get(1,1,n,r);
        res[1]=get(1,r+1,n,n);
    };

    auto print=[&](){
        std::cout<<"! ";
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++) std::cout<<res[i][j]<<" ";
        }
        std::cout<<std::endl;
    };
    xx();
    if(res[0][0]!=-1) print();
    else{
        yy();
        print();
    }
}

signed main(){
    //fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
