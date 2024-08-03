#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7, INF = 1e9, N = 1e5+11;

void solve(){
    int n;
    cin >> n;
    vector <int> nums(n), w(n);
    for (int i = 0; i < n; ++ i) cin >> nums[i], nums[i] -= 1;

    for (int i = 0, mx1 = -1, mx2 = -1; i < n; ++ i){
        if (nums[i] > mx1){  //考虑第i个位置对w产生的贡献
            -- w[nums[i]];
            mx2 = mx1, mx1 = nums[i];
        } else if (nums[i] > mx2){
            ++ w[mx1];
            mx2 = nums[i];
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++ i)
        if (w[i] > w[res]) res = i;
    cout << res+1 << "\n";
}
