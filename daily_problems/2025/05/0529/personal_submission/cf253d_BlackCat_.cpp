#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
// #define fin std::cin
// #define fout std::cout
void solve(){
    int n,m,k;
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    fin>>n>>m>>k;
    std::vector<std::string> a(n+1);
    for(int i=1;i<=n;i++){
        fin>>a[i];
        a[i]=" "+a[i];
    }
    i64 ans=0;
    for(int i=1;i<=n;i++){
        std::vector<int> cnt(m+1);
        for(int l=1;l<=m;l++){
            cnt[l]+=(a[i][l]=='a');
        }
        for(int j=i+1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cnt[l]+=(a[j][l]=='a');
            }
            int sum=0;
            int l=1;
            std::vector<int> c(26,0);
            for(int r=1;r<=m;r++){
                sum+=cnt[r];
                while(sum>k){
                    if(a[j][l]==a[i][l]){
                        c[a[j][l]-'a']--;
                    }
                    sum-=cnt[l];
                    l++;
                }
                if(a[j][r]==a[i][r]){
                    if(l<r){
                        ans+=c[a[j][r]-'a'];
                        
                    }
                    c[a[j][r]-'a']++;
                }
            }
        }
    }
    fout<<ans<<endl;
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
