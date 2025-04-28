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
    std::map<std::string,std::pair<int,std::string>> q;

    auto op=[&](std::string s)->std::pair<int,std::string>{
        int cnt=0;
        while(s.back()=='*') cnt++,s.pop_back();
        reverse(all(s));
        while(s.back()=='&') cnt--,s.pop_back();
        reverse(all(s));
        return std::make_pair(cnt,s);
    };

    auto find=[&](std::string s)->std::pair<int,std::string>{
        int n=q.size();
        auto t=op(s);

        std::vector<std::pair<int,std::string>> a={t};

        int cnt=t.first;
        std::string tmp=t.second;

        while(1){
            if(tmp=="void") break;
            if(!q.count(tmp)){
                q[s]={-1,"errtype"};
                return q[s];
            }
            auto v=q[tmp];
            if(v.second=="errtype"){
                q[s]={-1,"errtype"};
                return q[s];
            }
            a.pb(v);
            tmp=q[tmp].second;
        }

        reverse(all(a));

        int k=0;
        for(auto x:a){
            k+=x.first;
            if(k<0) return q[s]={-1,"errtype"};
        }

        return q[s]={k,"void"};
    };

    for(int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        if(s=="typeof"){
            std::string a;
            std::cin>>a;
            auto [cnt,str]=op(a);
            auto ans=find(str);
            if(ans.second=="errtype" or ans.first+cnt<0){
                std::cout<<"errtype"<<"\n";
                continue;
            }
            std::cout<<"void"+std::string(ans.first+cnt,'*')<<"\n";
        }else{
            std::string a,b;
            std::cin>>a>>b;
            auto [cnt,str]=op(a);
            if(str=="void") q[b]={cnt,str};
            else q[b]=find(a);
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
