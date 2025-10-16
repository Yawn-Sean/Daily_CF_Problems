#include<bits/stdc++.h>
using namespace std;
const int M=3000;
vector<bitset<M>>R,D;
unsigned long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int x;cin>>x;
            a[i][j]=x;
        }
    }
    vector<vector<short>>r(n,vector<short>(n)),d(n,vector<short>(n));
    for(int i=0;i<n;++i) for(int j=n-1;j>=0;--j) r[i][j]=a[i][j]?1+(j+1<n?r[i][j+1]:0):0;
    for(int j=0;j<n;++j) for(int i=n-1;i>=0;--i) d[i][j]=a[i][j]?1+(i+1<n?d[i+1][j]:0):0;
    vector<vector<int>> br(n+1),bd(n+1);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int id=i*n+j;
            if(r[i][j])br[r[i][j]].push_back(id);
            if(d[i][j])bd[d[i][j]].push_back(id);
        }
    }
    R.resize(n),D.resize(n);
    for(int l=n;l;--l){
        for(int id:br[l]){
            int i=id/n,j=id%n;
            R[i].set(j);
        }
        for(int id:bd[l]){
            int i=id/n,j=id%n;
            D[i].set(j);
        }
        int s=l-1;
        for(int i=0;i+l<=n;++i){
            bitset<M> m=R[i]&D[i]&(D[i]>>s)&R[i+l-1];
            ans+=m.count();
        }
    }
    cout<<ans<<'\n';
}
/* 
一个非常简单的方法
r[i][j]=行i中从列j开始连续的1的个数（包括该单元格本身）
d[i][j]=列j中从行i开始连续的1的个数（包括该单元格本身）
R[i]–列j是1 ⇔ r[i][j]>=当前L
D[i]–列j是1 ⇔ d[i][j]>=当前L
两个的增长是单调的
bitset维护R和D即可
*/