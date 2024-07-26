#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s[N];
        for(int i=1;i<=n;i++){
            cin>>s[i],s[i]+=s[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='1')ans++;
            }
        }
        int sum=0;
        for(int k=0;k<n;k++){
            int sum1=0,sum2=0;
            for(int i=1;i<=n;i++){
                if(s[i][i+k-1]=='1')sum1++;
            }
            sum=max(sum,sum1);
        }
        ans=ans-sum+(n-sum);
        cout<<ans<<'\n';
    }
    return 0;
}
