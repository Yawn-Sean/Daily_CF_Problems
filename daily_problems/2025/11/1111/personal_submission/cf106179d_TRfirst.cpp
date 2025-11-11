#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 5);
    for (int i = 1; i <= n; i++) cin >> nums[i];
    int cnt = 0;
    for (int i = 1; i <= n / 2; i++) if (nums[i] > n / 2) cnt++;
    if (cnt == n / 2 || cnt == 0) {
        cout << 1 << endl;
        cout << n << " ";
        for (int i = 1; i <= n; i++) cout << nums[i] << " ";
        cout << endl;
        return;
    }
    cout << 2 << endl;
    cout << cnt * 2 << " ";
    for (int i = 1; i <= n / 2; i++) if (nums[i] > n / 2) cout << nums[i] << " ";
    for (int i = n / 2 + 1; i <= n; i++) if (nums[i] <= n / 2) cout << nums[i] << " ";
    cout << endl;
    cout << n - cnt * 2 << " ";
    for (int i = 1; i <= n / 2; i++) if (nums[i] <= n / 2) cout << nums[i] << " ";
    for (int i = n / 2 + 1; i <= n; i++) if (nums[i] > n / 2) cout << nums[i] << " ";
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}