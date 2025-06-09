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
    int n,t;
    std::cin>>n>>t;
    std::string s;
    std::cin>>s;

    int idx=s.find('.');

    std::string res="";

    auto dfs=[&](auto self,int pos,int v)->void{
        if(pos==idx){
            res+='.';
            self(self,pos-1,v);
            return;
        }
        if(pos<0){
            if(!v) return;
            else{
                res+=v+'0';
                return;
            }
        }
        int d=(s[pos]-'0')+v;
        if(t and pos>idx){
            int nv=d/10;
            if(d%10>=5){
                res.clear();
                nv++;
                t--;
                self(self,pos-1,nv);
            }else{
                res+=d%10+'0';
                self(self,pos-1,nv);
            }
        }else{
            res+=(d%10+'0');
            self(self,pos-1,d/10);
        }
    };
    bool flag=0;
    for(int i=idx+1;i<n;i++){
        if(s[i]>='5'){
            flag=1;
            t--;
            dfs(dfs,i-1,1);
            break;
        }
    }
    if(!flag){
        std::cout<<s<<"\n";
        return;
    }
    reverse(all(res));
    if(res.back()=='.') res.pop_back();
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
