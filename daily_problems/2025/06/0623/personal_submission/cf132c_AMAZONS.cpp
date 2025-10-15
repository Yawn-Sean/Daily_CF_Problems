#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
const int MAX_S_LEN = 100;
const int MAX_K = 50;

// 使用固定大小的数组
bool dp[2][MAX_K + 1][2 * MAX_S_LEN + 1];
bool ndp[2][MAX_K + 1][2 * MAX_S_LEN + 1];
void solve1(){
	string s;
    cin>>s;
    int n;cin>>n;
    int offset=s.size();
    bool dp[2][n+1][2*s.size()+1];
    bool ndp[2][n+1][2*s.size()+1];
    // cout<<dp[0][]
    memset(dp, 0, sizeof(dp));dp[0][0][offset] = true;
    for(auto& x:s){
        memset(ndp, 0, sizeof(ndp));
        if(x=='F'){
            for(int i=0;i<2;i++){
                for(int j=0;j<=n;j++){
                    for(int k=0;k<2*s.size()+1;k++){
                        if(dp[i][j][k]){
                            //不改变
                            ndp[i][j][k+(i?-1:1)]=1;
                            //改变
                            if(j<n)
                            ndp[i^1][j+1][k]=1;
                        }
                    }
                }
            }
        }
        else{
            for(int i=0;i<2;i++){
                for(int j=0;j<=n;j++){
                    for(int k=0;k<2*s.size()+1;k++){
                        if(dp[i][j][k]){
                            //不改变
                            ndp[i^1][j][k]=1;
                            //改变
                            if(j<n)
                            ndp[i][j+1][k+(i?-1:1)]=1;
                        }
                    }
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    int ans=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<2*s.size()+1;k++){
                if(dp[i][j][k]&&(n-j)%2==0){
                    ans=max(ans,abs(k-offset));
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve1();}
    return 0;
}
