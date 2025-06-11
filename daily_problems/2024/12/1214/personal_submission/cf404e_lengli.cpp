/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=2000010;

int st[N];

void solve(){
    std::string s;
    std::cin>>s;

    i64 res=0;

    int n=s.size();

    {
        std::vector<int> tmp={1000000};
        st[tmp[0]]=1;
        for(int i=0,j=1000000;i<n;i++){
            if(s[i]=='L') j--;
            else j++;
            if(i==n-1){
                if(!st[j]) res++;
            }
            tmp.pb(j);
            st[j]=1;
        }
        for(auto x:tmp) st[x]=0;

        if(res){
            std::cout<<res<<"\n";
            return;
        }
    }

    if(s.back()=='L'){
        auto check=[&](int x){
            bool flag=0;
            std::vector<int> tmp={1000000};
            st[tmp[0]]=1;
            for(int i=0,j=1000000;i<n;i++){
                if(s[i]=='L') j--;
                else if(j+1<x) j++;
                if(i==n-1){
                    if(!st[j]) flag=1;
                }
                tmp.pb(j);
                st[j]=1;
            }
            for(auto c:tmp) st[c]=0;
            return flag;
        };

        int l=1000001,r=2000000;
        while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        if(check(l)) res+=l-1000000;
    }else{
        auto check=[&](int x){
            bool flag=0;
            std::vector<int> tmp={1000000};
            st[tmp[0]]=1;
            for(int i=0,j=1000000;i<n;i++){
                if(s[i]=='R') j++;
                else if(j-1>x) j--;
                if(i==n-1){
                    if(!st[j]) flag=1;
                }
                tmp.pb(j);
                st[j]=1;
            }
            for(auto c:tmp) st[c]=0;
            return flag;
        };

        int l=0,r=999999;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        if(check(r)) res+=1000000-r;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
