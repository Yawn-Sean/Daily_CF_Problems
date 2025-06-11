/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    int n;
    std::cin>>n;

    int minus=0,zero=0,plus=0;
    std::vector<int> a(n);
    for(auto &x:a){
        std::cin>>x;
        if(x>0) plus+=1;
        else if(x==0) zero+=1;
        else minus+=1;
    }

    int mx_minus_idx=-1,mx=-inf;
    for(int i=0;i<n;i++){
        if(a[i]<0 and a[i]>mx){
            mx=a[i];
            mx_minus_idx=i;
        }
    }

    if(zero){
        int idx=0;
        for(int i=0;i<n;i++) if(!a[i]) idx=i;
        
        if(minus&1){
            int target=-1;
            for(int i=0;i<n and target==-1;i++){
                if(i==idx or i==mx_minus_idx or a[i]==0) continue;
                target=i;
            }

            if(target==-1){
                for(int i=0;i<n;i++){
                    if(i==idx) continue;
                    std::cout<<1<<" "<<i+1<<" "<<idx+1<<"\n";
                }
                return;
            }

            for(int i=0;i<n;i++){
                if(i==idx or i==target) continue;
                if(a[i]==0) std::cout<<1<<" "<<i+1<<" "<<idx+1<<"\n";
                else if(a[i]>0) std::cout<<1<<" "<<i+1<<" "<<target+1<<"\n";
                else{
                    if(i==mx_minus_idx) std::cout<<1<<" "<<i+1<<" "<<idx+1<<"\n";
                    else std::cout<<1<<" "<<i+1<<" "<<target+1<<"\n";
                }
            }
            std::cout<<2<<" "<<idx+1<<"\n";
        }else{
            int target=-1;
            for(int i=0;i<n and target==-1;i++){
                if(i==idx or a[i]==0) continue;
                target=i;
            }

            if(target==-1){
                for(int i=1;i<n;i++){
                    std::cout<<1<<" "<<i+1<<" "<<1<<"\n";
                }
                return;
            }

            for(int i=0;i<n;i++){
                if(i==idx or i==target) continue;
                if(a[i]==0) std::cout<<1<<" "<<i+1<<" "<<idx+1<<"\n";
                else if(a[i]>0) std::cout<<1<<" "<<i+1<<" "<<target+1<<"\n";
                else std::cout<<1<<" "<<i+1<<" "<<target+1<<"\n";
            }

            std::cout<<2<<" "<<idx+1<<"\n";
        } 
    }else{
        if(minus&1){
            int target=-1;
            for(int i=0;i<n and target==-1;i++){
                if(i==mx_minus_idx) continue;
                target=i;
            }
            std::cout<<2<<" "<<mx_minus_idx+1<<"\n";
            for(int i=0;i<n;i++){
                if(i==mx_minus_idx or i==target) continue;
                std::cout<<1<<" "<<i+1<<" "<<target+1<<"\n"; 
            }
        }else{
            for(int i=1;i<n;i++){
                std::cout<<1<<" "<<i+1<<" "<<1<<"\n";
            }
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
