//我们可以先填好第一行和第一列，不填左上角，其他位置填0即可。
//然后只考虑左上角那个位置填什么可以让矩阵满足条件
//首先将所有行与列异或的总和应该是0，否则无解。
//不难发现n行的异或和，在异或第一行，在异或第二行的结果，是左上角和(2,n)行与(2,m)列组成矩阵的异或和
//那(2,n)行与(2,m)列组成矩阵的异或和是0，因为我没都是填充的0，那其实这个异或值就是左上角的值。

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> res(n,vector<int>(m,0));
    vector<int> a(n),b(m);
    int l=0,r=0;
    for(auto &x:a) cin>>x,l^=x;
    for(auto &x:b) cin>>x,r^=x;
    if(l!=r){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<n;i++) res[i][0]=a[i];
    for(int j=1;j<m;j++) res[0][j]=b[j];
    res[0][0]=a[0]^b[0]^l;
    for(auto x:res){
        for(auto y:x) cout<<y<<" ";
        cout<<endl;
    }
 
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
