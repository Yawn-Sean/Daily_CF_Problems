#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
std::vector<int> kmp(std::vector<std::pair<char,i64>>s ) {
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::pair<char,i64>> s1,s2;
    std::string s;

    for(int i=0;i<n;i++){
        std::cin>>s;
        i64 x=std::stoi(s.substr(0,s.size()-2));
        char ss=s.back();
        if(s1.size()!=0&&ss==s1[s1.size()-1].first){
            s1[s1.size()-1].second+=x;
        }
        else{
            s1.push_back(std::make_pair(ss,x));
        }
    }
    n=s1.size();
    for(int i=0;i<m;i++){
        std::cin>>s;
        i64 x=std::stoi(s.substr(0,s.size()-2));
        char ss=s.back();
        if(i!=0&&ss==s2[s2.size()-1].first){
            s2[s2.size()-1].second+=x;
        }
        else{
            s2.push_back(std::make_pair(ss,x));
        }
    }

    m=s2.size();i64 ans=0;
    if(m==1){
        for(auto x:s1){
            if(x.first==s2[0].first){
                ans+=std::max(0ll,x.second-s2[0].second+1);
            }
        }
        std::cout<<ans<<endl;
        return ;
    }
    else if(m==2){
        for(int i=0;i+1<n;i++){
            if(s1[i].first==s2[0].first&&s1[i].second>=s2[0].second){
                if(s1[i+1].first==s2[1].first&&s1[i+1].second>=s2[1].second){
                    ans++;
                }
            }
        }
        std::cout<<ans<<endl;
        return ;
    }
    std::vector need(s2.begin()+1,s2.end()-1);
    auto k=kmp(need);

    int j=0;
    int m1=m-2;
    
    for(int i=0;i<n;i++){
        while (j > 0 && s2[j+1] != s1[i]) {
            j = k[j];
        }
        if (s2[j+1] == s1[i]) {
            j++;
        }
        if(j==m1){
            if(i-m1>=0&&s1[i-m1].first==s2[0].first&&s1[i-m1].second>=s2[0].second){
                if(i+1<n&&s1[i+1].first==s2[m-1].first&&s1[i+1].second>=s2[m-1].second){
                    ans++;
                }
            }
            j=k[j];
        }
    }
    std::cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
