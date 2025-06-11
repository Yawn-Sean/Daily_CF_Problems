#include<bits/stdc++.h>
using namespace std;
int a[202020][2];
long long sum[2020][2020],b[2020][2020];
int main(){
    int _;
    cin>>_;
    while(_--){
        int n,i,j,k,q;
        cin>>n>>q;
        for(i=0;i<=1000;i++){
            for(j=0;j<=1000;j++)b[i][j]=sum[i][j]=0;
        }
        for(i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1];
            b[a[i][0]][a[i][1]]+=a[i][0]*a[i][1];
        }
        for(i=1;i<=1000;i++){
            for(j=1;j<=1000;j++){
                b[i][j]+=b[i-1][j];
            }
        }
        for(i=1;i<=1000;i++){
            for(j=1;j<=1000;j++){
                b[i][j]+=b[i][j-1];
            }
        }
        while(q--){
            int x,y,xx,yy;
            cin>>x>>y>>xx>>yy;
            xx--,yy--,x++,y++;
            if(x>xx||y>yy){cout<<0<<'\n';continue;}
            cout<<b[xx][yy]-b[x-1][yy]-b[xx][y-1]+b[x-1][y-1]<<'\n';
        }
    }
}
