#include <bits/stdc++.h>
#define int long long
using namespace std;
int init = []() { return cin.tie(nullptr)->sync_with_stdio(false), 0; }();

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> d(m),f(k);
    for(int i=0;i<m;i++) cin>>d[i];
    for(int i=0;i<k;i++) cin>>f[i];
    ranges::sort(d);
    ranges::sort(f);
    vector<int> dif(n - 1);
    int mxdif = 0;
    for (int i=0;i+1<n;i++) {
        dif[i] = a[i+1]-a[i];
        mxdif = max(mxdif,dif[i]);
    }

    int lo=-1,hi=mxdif+1,ans=mxdif;
    while(lo<hi-1){
        int mid=(lo+hi)>>1;
        int cnt = 0;
        int idx = -1;
        for (int i = 0; i + 1 < n; i++) {
            if (dif[i] > mid) {
                cnt++;
                idx = i;
                if (cnt >= 2)
                    break;
            }
        }
        bool ok=false;
        if(cnt==0){
            ok=true;
        }else if(cnt>=2){
            ok=false;
        }else{
            int L = a[idx], R = a[idx + 1];
            int low = max(R - mid, L + 1);
            int high = min(L + mid, R - 1);
            if (low>high) {
                ok=false;
            }else{
                int i=0,j=k-1;
                while (i<m&&j>=0) {
                    int s=d[i]+f[j];
                    if(s<low){
                        i++;
                    }else if(s>high){
                        j--;
                    }else{
                        ok = true;
                        break;
                    }
                }
            }
        }

        if(ok){
            ans = mid;
            hi = mid;
        }else{
            lo = mid;
        }
    }

    cout<<ans<<'\n';
}

int32_t main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
