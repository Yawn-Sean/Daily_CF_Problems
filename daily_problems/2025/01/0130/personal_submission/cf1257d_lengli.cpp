/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct ST{
	std::vector<std::vector<int>> f;
    int n=0,m=0,flag=0;
    ST(){};
	ST(int nn,std::vector<int> &a,bool t=1){
        flag=t,n=nn,m=std::__lg(nn)+1;
        f.resize(n+1,std::vector<int> (m+1));
		for(int len=0;len<m;len++){
			for(int i=1;i+(1<<len)-1<=n;i++){
				if(!len) f[i][len]=a[i];
				else {
                    if(flag) f[i][len]=std::max(f[i][len-1],f[i+(1<<len-1)][len-1]);
                    else f[i][len]=std::min(f[i][len-1],f[i+(1<<len-1)][len-1]);
                }
			}
		}
	}
	int query(int l,int r){
		int k=std::__lg(r-l+1);
		if(flag) return std::max(f[l][k],f[r-(1<<k)+1][k]);
        return std::min(f[l][k],f[r-(1<<k)+1][k]);
	}
};

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    int m;
    std::cin>>m;
    std::vector<std::array<int,2>> b(m);
    for(auto &[p,s]:b) std::cin>>p>>s;
    sort(all(b));
    for(int i=m-2;i>=0;i--){
        b[i][1]=std::max(b[i][1],b[i+1][1]);
    }

    ST tr(n,a);

    int res=0;

    for(int i=1;i<=n;i++){
        int l=i,r=n;

        auto check=[&](int x)->bool{
            int ll=0,rr=m-1;
            int mx=tr.query(i,x);
            int len=x-i+1;
            while(ll<rr){
                int mid=(ll+rr)/2;
                if(b[mid][0]>=mx) rr=mid;
                else ll=mid+1;
            }
            if(b[rr][0]<mx) return 0;
            return b[rr][1]>=len;
        };

        while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        if(!check(l)){
            std::cout<<"-1"<<"\n";
            return;
        }
        i=l;
        res++;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
