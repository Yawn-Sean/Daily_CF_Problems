#include <iostream>
#include <vector>

using namespace std;
const int inf=0x3f3f3f3f;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    std::cin>>n>>m;
    vector<long long> cnt(m,0);
    int t=n/m;
    int ts=n%m;
    vector<long long> pre(m,t);
    for(int i=1;i<=ts;i++){
        pre[i]++;
    }
    for(int i=0;i<m;i++){
        cnt[(i*i)%m]+=pre[i];
    }
    long long ans=0;
    ans+=cnt[0]*cnt[0];
    for(long long i=1;i<m;i++){
        ans+=cnt[i]*cnt[m-i];
    }
    cout<<ans<<endl;
}
