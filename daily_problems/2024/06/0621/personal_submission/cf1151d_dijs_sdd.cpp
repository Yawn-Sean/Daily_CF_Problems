#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 5005;
const ll mod=1e9+7;
int n;
bool cmp(vector<int> &a,vector<int> &b){
    return a[0]-a[1]>b[0]-b[1];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    vector<vector<int>> a(n,vector<int>(2));
    int x,y;
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a[i][0]=x,a[i][1]=y;
        ans+=1ll*y*n-x;
    }
    sort(a.begin(), a.end(),cmp);
    for(int i=0;i<n;i++){
        int l=a[i][0],r=a[i][1];
        ans+=1ll*(l-r)*(i+1);
    }
    cout<<ans<<'\n';
    return 0;
}

