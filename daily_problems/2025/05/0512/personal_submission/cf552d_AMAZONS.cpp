#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
vector<pair<int,int>> vp;
void solve(){
	int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        vp.push_back({x,y});
    }
    int cnt=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            auto [x1,y1]=vp[i];
            auto [x2,y2]=vp[j];
            double l=(1.0*((double)y2-(double)y1))/(1.0*((double)x2-(double)x1));
            double c=y1-l*x1;
            for(int k=j+1;k<n;k++)
            {
                auto [x3,y3]=vp[k];
                int cross=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
                if(cross!=0) cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
