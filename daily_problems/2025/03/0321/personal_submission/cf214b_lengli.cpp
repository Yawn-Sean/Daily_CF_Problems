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
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    sort(all(a),std::greater<>());
    if(a.size()==1){
        if(a[0]!=0) std::cout<<"-1"<<"\n";
        else std::cout<<0<<"\n";
        return;
    }
    if(a.back()!=0){
        std::cout<<"-1"<<"\n";
        return;
    }
    if(a[0]==0){
        std::cout<<0<<"\n";
        return;
    }
    int sum=0;
    std::vector<int> cnt(10,0);
    for(auto x:a) sum+=x,cnt[x]++;
    if(sum%3==0){
        for(auto x:a) std::cout<<x;
        std::cout<<"\n";
        return;
    }

    std::vector<std::vector<int>> f(3);
    for(int i=0;i<100;i++){
        int v=i%3;
        f[v].pb(i);
    }

    auto cmp=[&](int x,int y)->bool{
        if(x<10 and y<10) return x<y;
        else if(x<10) return 1;
        else if(y<10) return 0;
        else{
            int lx=x%10,rx=x/10;
            int ly=y%10,ry=y/10;
            if(lx>rx) std::swap(lx,rx);
            if(ly>ry) std::swap(ly,ry);
            if(rx>ry) return 0;
            else if(rx<ry) return 1;
            else return lx<ly;
        }
        return 0;
    };

    auto check=[&](int x)->bool{
        if(x<10) return cnt[x]>0;
        int l=x%10,r=x/10;
        cnt[l]--;cnt[r]--;
        if(cnt[l]<0 or cnt[r]<0){
            cnt[l]++,cnt[r]++;
            return 0;
        }
        cnt[l]++,cnt[r]++;
        return 1;
    };

    int res=99;
    for(auto x:f[sum%3]){
        if(check(x) and cmp(x,res)) res=x;
    }
    if(res==99) std::cout<<"-1"<<"\n";
    else{
        std::string ans="";
        if(res<10) cnt[res]--;
        else cnt[res%10]--,cnt[res/10]--;
        for(int i=9;i>=0;i--){
            while(cnt[i]--) ans+=(i+'0');
        }
        if(ans[0]=='0') std::cout<<0<<"\n";
        else std::cout<<ans<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
