#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int deg[N];

void solve(){
    int n;double k;
    scanf("%d%lf",&n,&k);
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        deg[a]++,deg[b]++;
    }
    double cnt=0;
    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            cnt++;
        }
    }
    printf("%.18lf\n",2.0*k/cnt);
}

signed main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
