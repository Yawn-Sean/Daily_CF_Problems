/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,k;
    std::cin>>n>>k;

    auto query=[&](int x,int y){
        std::cout<<"1 "<<x<<" "<<y<<std::endl;
        std::string s;
        std::cin>>s;
        return s=="TAK";
    };
    auto print=[&](int x,int y){
        std::cout<<"2 "<<x<<" "<<y<<std::endl;
        return;
    };

    auto find=[&](int l,int r){
        while(l<r){
            int mid=(l+r)/2;
            if(query(mid,mid+1)) r=mid;
            else l=mid+1;
        }
        return r;
    };

    int x=find(1,n),y;
    if(x!=1){
		y=find(1,x-1);
		if(!query(y,x)) y=find(x+1,n);
	}else y=find(x+1,n);
	
	print(x,y);

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
