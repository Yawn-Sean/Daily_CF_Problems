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
    std::string s;
    std::cin>>s;

    int n=s.size();
    std::vector<int> a(n+2),b(n+2);

    std::vector<int> cnt(n+2);
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i-1];
        if(s[i-1]=='[') cnt[i]++;
    }

    std::stack<int> q;

    int la=-1,err=1;
    int res=0,l=-1,r=-1;

    auto insert=[&](int idx){
        if(err and q.empty()){
            la=idx+1;
            err=0;
        }
        q.push(idx);
    };

    auto update=[&](int ll,int rr){
        int k=cnt[rr]-cnt[ll-1];
        if(k>res){
            res=k;
            l=ll,r=rr;
        }
    };

    auto del=[&](int idx){
        if(s[idx]==']'){
            if(q.size() and s[q.top()]=='['){
                q.pop();
                if(q.empty()) update(la,idx+1);
                else update(q.top()+2,idx+1);
            }else{
                err=1;
                q=std::stack<int>();
            }
        }else{
            if(q.size() and s[q.top()]=='('){
                q.pop();
                if(q.empty()) update(la,idx+1);
                else update(q.top()+2,idx+1);
            }else{
                err=1;
                q=std::stack<int>();
            }
        }
    };

    for(int i=1;i<=n;i++){
        if(s[i-1]=='[') insert(i-1);
        else if(s[i-1]=='(') insert(i-1);
        else del(i-1);
    }

    
    std::cout<<res<<"\n";
    if(res){
        for(int i=l;i<=r;i++){
            std::cout<<s[i-1];
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
