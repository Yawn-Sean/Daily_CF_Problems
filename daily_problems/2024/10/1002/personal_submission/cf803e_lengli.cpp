/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,k;
    std::string s;
    std::cin>>n>>k>>s;
    std::vector<std::vector<int>> f(n+2,std::vector<int> (k*2+2,0));
    std::vector<std::vector<int>> la(n+2,std::vector<int> (k*2+2,0));
    f[0][k]=1;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            for(int j=1;j<k*2;j++){
                if(f[i][j]){
                    f[i+1][j-1]=1;
                    la[i+1][j-1]=j;
                }
            }
        }else if(s[i]=='W'){
            for(int j=1;j<k*2;j++){
                if(f[i][j]){
                    f[i+1][j+1]=1;
                    la[i+1][j+1]=j;
                }
            }
        }else if(s[i]=='D'){
            for(int j=1;j<k*2;j++){
                if(f[i][j]){
                    f[i+1][j]=1;
                    la[i+1][j]=j;
                }
            }
        }else{
            for(int j=1;j<k*2;j++){
                if(f[i][j]){
                    f[i+1][j+1]=1;
                    f[i+1][j]=1;
                    f[i+1][j-1]=1;
                    la[i+1][j+1]=j;
                    la[i+1][j]=j;
                    la[i+1][j-1]=j;
                }
            }
        }
    }
    if(!f[n][0] and !f[n][k*2]){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::string res="";
    for(int i=n,j=f[n][0] ? 0 : k*2;i>=1;i--){
        if(la[i][j]<j) res+="W";
        else if(la[i][j]==j) res+="D";
        else res+="L";
        j=la[i][j];
    }
    reverse(all(res));
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
