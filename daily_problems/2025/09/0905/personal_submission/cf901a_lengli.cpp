/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n;
    std::cin>>n;
    n++;
    std::vector<int> a(n+2);

    int sum=0;

    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        sum+=a[i];
    }
    int idx=-1;
    for(int i=1;i<n;i++){
        if(a[i]>=2 and a[i+1]>=2){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        std::cout<<"perfect"<<"\n";
        return;
    }

    std::cout<<"ambiguous"<<"\n";

    {
        int id=1;
        std::vector<int> la,cur;
        std::vector<int> fa(sum+2);
        int p=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++,id++){
                if(i==idx) la.pb(id);
                else if(i==idx+1) cur.pb(id);
                fa[id]=p;
            }
            p=id-1;
        }
        for(int i=1;i<=sum;i++){
            std::cout<<fa[i]<<" ";
        }std::cout<<"\n";
        fa[cur[0]]=la[1];
        fa[cur[1]]=la[0];
        for(int i=1;i<=sum;i++){
            std::cout<<fa[i]<<" ";
        }std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
