/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    std::vector<int> k(2);
    std::vector<std::string> s(2); 
    std::cin>>k[0]>>k[1]>>s[0]>>s[1];
    std::vector<int> len(2);
    len[0]=s[0].size(),len[1]=s[1].size();
    std::vector<int> nd(len[0],0),ne(len[0],-1);
    for(int i=0;i<len[0];i++){
        int idx=i,cnt=0;
        for(int j=0;j<len[1];j++){
            int t=idx,loss=0;
            while(s[0][t]!=s[1][j]){
                t++;
                t%=len[0];
                loss++;
                if(loss>=len[0]){
                    std::cout<<0<<"\n";
                    return;
                }
            }
            if(t<idx) cnt++;
            else if(j!=len[1]-1 and t==len[0]-1) cnt++;
            if(j!=len[1]-1) idx=t+1,idx%=len[0];
            else idx=t;
        }
        nd[i]=cnt,ne[i]=idx;
    }

    std::vector<int> st(len[0],0),v(len[0],0),d(len[0],0);

    // for(int i=0;i<len[0];i++) std::cout<<nd[i]<<" ";std::cout<<"\n";
    // for(int i=0;i<len[0];i++) std::cout<<ne[i]<<" ";std::cout<<"\n";

    int start=0,xh=0,cnt=0;
    while(1){
        xh+=nd[start];
        start=ne[start];
        cnt+=1;
        if(st[start]){
            cnt=cnt-v[start];
            xh=xh-d[start];
            break;
        }
        st[start]=1;
        v[start]=cnt;
        d[start]=xh;
        if(start==len[0]-1) xh++;
        start=(start+1)%len[0];
    }

    auto check=[&](int x)->bool{
        x*=k[1];
        if(k[0]*len[0]<x*len[1]) return 0;
        if(x==0) return 1;
        int ans=0,idx=0;
        
        if(x>v[start]){
            x-=v[start];
            ans+=d[start];
            int t=x/cnt;
            x%=cnt;
            ans+=t*xh;
            if(!x) return ans<k[0];
            else{
                idx=(start+1)%len[0];
                if(idx==0) ans++;
            }
        }
        while(x){
            x--;
            ans+=nd[idx];
            idx=(ne[idx]+1)%len[0];
        }
        return ans<k[0];
    };
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }

    std::cout<<l<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
