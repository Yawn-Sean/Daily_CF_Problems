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
    if(n&1){
        int len=(n+1)/2;
        std::string res=std::string(len,'4');
        res+=std::string(len,'7');
        std::cout<<res<<"\n";
        return;
    }

    int flag=0,len=n/2;

    std::string ans=std::string(len,'4')+std::string(len,'7');
    std::queue<int> q;
    for(int i=len;i<n;i++) q.push(i);
    std::vector<int> pre(n);
    for(int i=0;i<n;i++){
        if(flag==1) continue;
        else if(flag==0){
            if(ans[i]<s[i]){
                while(q.size()){
                    auto t=q.front();
                    q.pop();
                    if(t<i) continue;
                    std::swap(ans[t],ans[i]);
                    break;
                }
            }else if(ans[i]>s[i]) flag=1;
            else continue;
        }
        if(flag==0 and ans[i]<s[i]) flag=-1;
        if(flag==0 and ans[i]>s[i]) flag=1;
        pre[i]=flag;
    }


    if(flag!=-1){
        std::cout<<ans<<"\n";
        return;
    }

    int la=-1;

    for(int i=n-1;i>=0;i--){
        if(s[i]<'7' and ans[i]=='4' and pre[i]==0){
            if(la!=-1) {
                std::swap(ans[la],ans[i]);
                sort(ans.begin()+i+1,ans.end());
                std::cout<<ans<<"\n";
                return;
            }
        }
        if(ans[i]=='7') la=i;
    }

    n+=2;
    len=n/2;
    ans=std::string(len,'4')+std::string(len,'7');

    std::cout<<ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
