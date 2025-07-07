#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
double r1,r2,R1,R2;double  d;
// #define int long long
// if((d<=r1-r)||(d<=r-r2)||(d>=r+r2)) return 1;
int calc(int r,int type){
    if(type==1){
        if(d>=r+R1||d<=(r1-r)||d<=(r-R1)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(d>=(R2+r)||d<=(r2-r)||d<=(r-R2)){
            return 1;
        }
        else{
            return 0;
        }
        
    }

}
void solve(){
    double x1,x2,y1,y2;
    cin>>x1>>y1>>r1>>R1;
    cin>>x2>>y2>>r2>>R2;
    d=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
    int ans=calc(r2,1)+calc(R2,1)+
            calc(r1,2)+calc(R1,2);
    // cout<<calc(r1,2)<<calc(R1,2)<<endl;
    // cout<<calc(r2,1)<<calc(R2,1)<<endl;
    // cout<<d<<endl;
    cout<<ans<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
