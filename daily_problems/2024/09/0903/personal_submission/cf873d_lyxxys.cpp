#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

void solve(){            
    int n, k;
    cin >> n >> k;
    vector <int> nums(n);
    iota(nums.begin(), nums.end(), 1);
    // 调用之后才算次数， 并检查当前区间是否继续递归
    function<void(int,int)> halfy = [&](int pl, int pr)->void{
        if (pl+1 == pr || !k) return;
        k -= 2;
        int mid = pl+pr >> 1;
        swap(nums[mid-1], nums[mid]);
        halfy(pl, mid), halfy(mid, pr);
    };

    if (k%2 == 0){
        cout << -1 << "\n";
        return;
    }
    -- k;
    halfy(0, n);
    if (k){
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < n; ++ i){
        cout << nums[i] << "\n "[i < n-1];
    }
}
