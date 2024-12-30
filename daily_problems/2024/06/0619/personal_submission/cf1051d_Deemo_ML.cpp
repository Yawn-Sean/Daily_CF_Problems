#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod=998244353;
const int N=1000+10;
LL f[N][2*N][4];
int g[4][4]={
    {0,1,1,1},
    {0,0,2,0},
    {0,2,0,0},
    {1,1,1,0}
};

int main()
{
    int n,k;
    cin>>n>>k;
    f[1][1][0]=1;
    f[1][2][1]=1;
    f[1][2][2]=1;
    f[1][1][3]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int z=0;z<=3;z++)
            {
                for(int p=0;p<=3;p++)
                {
                    int w=g[p][z];
                    if(j>=w)
                    {
                        f[i][j][z]+=f[i-1][j-w][p];
                        f[i][j][z]%=mod;
                    }
                }
            }
        }
    }
    LL ans=f[n][k][0]+f[n][k][1]+f[n][k][2]+f[n][k][3];
    ans%=mod;
    cout<<ans<<'\n';
    return 0;
}
