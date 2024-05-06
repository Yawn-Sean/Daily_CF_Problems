//由于温度受到距离(下标)的影响，所以我们需要维护左右两侧去除下标影响后的最小值即可
//具体实现为，从左到右扫描，遇到位于下标i，温度为t的空调时，令不受下标影响的温度为x=t-i，用x更新左侧最小值。
//遇到空地时答案即为最小值+i
//再从右至左处理一遍，对于每一个位置取两侧最小值即可。
//需要注意答案上限为1e9+n-1，故inf设置为2e9。

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
const int N=200010,inf=2e9;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<array<int,2>> a(m);
    for(int i=0;i<m;i++) cin>>a[i][0];
    for(int i=0;i<m;i++) cin>>a[i][1];

    sort(all(a));
    vector<int> l(n+2,inf),r(n+2,inf);
    
    int mi=inf;
    for(int i=1,j=0;i<=n;i++){
        while(j<m and a[j][0]<=i) mi=min(mi,a[j][1]-i),j++;
        l[i]=mi+i;
    }
    mi=inf;
    reverse(all(a));
    for(int i=n,j=0;i>=1;i--){
        while(j<m and a[j][0]>=i) mi=min(mi,a[j][1]-(n-i)),j++;
        r[i]=mi+(n-i);
    }
    for(int i=1;i<=n;i++){
        cout<<min(l[i],r[i])<<" ";
    }
    cout<<endl;
}

signed main(){
    fastio;
    
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
