#include<bits/stdc++.h>
using namespace std;
const int N =1e5;
const int mod=1e9+7;
#define int long long
double dis(double x1,double y1,double z1,double x2,double y2,double z2,double x3,double y3,double z3){
    return sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)+(z1-z3)*(z1-z3))+sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)+(z2-z3)*(z2-z3))+
           sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
void solve(){
	int n;cin>>n;
    vector<int> px(n+1),py(n+1),pz(n+1);
    for(int i=1;i<=n;i++){
        int x,y,z;cin>>x>>y>>z;
        x+=N;y+=N;z+=N;
        px[i]=x;
        py[i]=y;
        pz[i]=z;
    }
    double ans=1e9+7;

    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(i==j)continue;
            ans=min(ans,dis(px[i]*1.0,py[i]*1.0,pz[i]*1.0,px[j]*1.0,py[j]*1.0,pz[j]*1.0,px[1]*1.0,py[1]*1.0,pz[1]*1.0));
        }
    }
    printf("%.10lf\n",ans/2);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
