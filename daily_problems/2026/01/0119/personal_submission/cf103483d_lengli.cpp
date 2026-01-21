#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> v1(n), v2(n);
    for(int i = 0; i < n; ++i) cin >> v1[i];
    for(int i = 0; i < n; ++i) cin >> v2[i];

    vector<long long> acc1(n+1, 0), acc2(n+1, 0);
    for(int i = 0; i < n; ++i){
        acc1[i+1] = acc1[i] + v1[i];
        acc2[i+1] = acc2[i] + v2[i];
    }

    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;

        bool ok = true;
        long long diff = 0; 

        for(int i = 0; i < n; ++i){
            int left = max(i - mid, 0);
            int right = min(i + mid + 1, n);

            diff = min(diff, acc1[i] - acc2[left]);
            long long cur = acc2[right] - acc1[i+1];

            if(cur + diff < 0){
                ok = false;
                break;
            }
        }

        if(ok) r = mid - 1;
        else l = mid + 1;
    }

    cout << (l < n ? l : -1) << "\n";
    return 0;
}
