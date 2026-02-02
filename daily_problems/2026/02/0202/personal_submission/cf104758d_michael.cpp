#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    ll ans = 0;
    int lmax = arr[0],rmax = arr[n - 1];
    ll lcur = 0,rcur = 0;
    int l = 1,r = n - 2;
    while(l <= r){
        if(lmax <= rmax){
            if(arr[l] < lmax){
                lcur += lmax - arr[l];
                ans = max(lcur,ans);
            }else{
                lcur = 0;
                lmax = arr[l];
            }
            l++;
        }else{
            if(arr[r] < rmax){
                rcur += rmax - arr[r];
                ans = max(rcur,ans);
            }else{
                rcur = 0;
                rmax = arr[r];
            }
            r--;
        }
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}