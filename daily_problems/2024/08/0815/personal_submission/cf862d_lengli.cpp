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
    auto query=[&](std::string s){
        std::cout<<"? "<<s<<std::endl;
        int x;
        std::cin>>x;
        return x;
    };
    auto print=[&](int a,int b){
        std::cout<<"! "<<a<<" "<<b<<std::endl;
        return;
    };

    std::string s=std::string(n,'0');
    auto cl=query(s);s[0]='1';
    auto cr=query(s);
    std::array<int,2> res={-1,-1};
    if(cl>cr) {
        res[1]=0,s[0]='1';
        int l=1,r=n-1;
        cr=query(s);
        auto check=[&](int x){
            char c=s[l];
            char t=(c=='1' ? '0' : '1');
            for(int i=l;i<=x;i++) s[i]=t;
            auto cnt=query(s);
            int len=x-l+1;
            if(c=='1' and cnt-cr==len){
                cr=cnt;
                return 0;
            }else if(c=='0' and cr-cnt==len){
                cr=cnt;
                return 0;
            }
            cr=cnt;
            return 1;
        };
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        res[0]=r;
    }else {
        res[0]=0,s[0]='0';
        int l=1,r=n-1;
        cr=query(s);
        auto check=[&](int x){
            char c=s[l];
            char t=(c=='1' ? '0' : '1');
            for(int i=l;i<=x;i++) s[i]=t;
            auto cnt=query(s);
            int len=x-l+1;
            if(c=='1' and cr-cnt==len){
                cr=cnt;
                return 0;
            }else if(c=='0' and cnt-cr==len){
                cr=cnt;
                return 0;
            }
            cr=cnt;
            return 1;
        };
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        res[1]=r;
    }

    print(res[0]+1,res[1]+1);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
