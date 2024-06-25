#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int MAX32=2147483647;
typedef struct{
    int x1,y1,x2,y2;
}jz;
void solve()
{
    int n;
    cin>>n;
    vector<jz> a(n+10);
    vector<int> xzmax(n+10);
    vector<int> yzmax(n+10);
    vector<int> xymin(n+10);
    vector<int> yymin(n+10);
    vector<int> dxzmax(n+10);
    vector<int> dyzmax(n+10);
    vector<int> dxymin(n+10);
    vector<int> dyymin(n+10);
    xzmax[0] = -2e9;
    yzmax[0] = -2e9;
    xymin[0] = 0x3f3f3f3f;
    yymin[0] = 0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        auto& [x1,y1,x2,y2] = a[i];
        cin>>x1>>y1>>x2>>y2;
        xzmax[i] = max(xzmax[i-1],x1);
        yzmax[i] = max(yzmax[i-1],y1);
        xymin[i] = min(xymin[i-1],x2);
        yymin[i] = min(yymin[i-1],y2);
    }
    dxzmax[n+1] = -2e9;
    dyzmax[n+1] = -2e9;
    dxymin[n+1] = 0x3f3f3f3f;
    dyymin[n+1] = 0x3f3f3f3f;
    for(int i=n;i>=1;i--)
    {
        auto& [x1,y1,x2,y2] = a[i];
        dxzmax[i] = max(dxzmax[i+1],x1);
        dyzmax[i] = max(dyzmax[i+1],y1);
        dxymin[i] = min(dxymin[i+1],x2);
        dyymin[i] = min(dyymin[i+1],y2);
    }
    for(int i=1;i<=n;i++)
    {
        int x1 = max(xzmax[i-1],dxzmax[i+1]);
        int y1 = max(yzmax[i-1],dyzmax[i+1]);
        int x2 = min(xymin[i-1],dxymin[i+1]);
        int y2 = min(yymin[i-1],dyymin[i+1]);
        if(x1<=x2&&y1<=y2)
        {
            cout<<x1<<" "<<y1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    t=1;
    while (t--)
    {
        solve();
    }
}
