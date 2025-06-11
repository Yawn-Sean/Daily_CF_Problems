#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector <int> nums(n+1);
    vector<vector<int>> Pr(n+1, vector<int>(n+2)), Sf(n+2, vector<int>(n+2));
    for (int i = 1; i <= n; ++ i){
        cin >> nums[i];
        nums[i] += 1;
    }
    
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            Pr[i][j] = Pr[i-1][j] + (nums[i] >= j);
        }
    }
    for (int i = n; i >= 1; -- i){
        for (int j = 1; j <= n; ++ j){
            Sf[i][j] = Sf[i+1][j] + (nums[i] <= j);
        }
    }

    int all = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = i+1; j <= n; ++ j){
            if (nums[i] > nums[j]){
                all += 1;
            }
        }
    }
    auto call = [&](int i, int x)->int{
        int res = Pr[i-1][x+1] + Sf[i+1][x-1];
        return res;
    };
    int res = all, cnt = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = i+1; j <= n; ++ j){
            int ans = all - call(i, nums[i]) - call(j, nums[j]);
            ans += call(i, nums[j]) + call(j, nums[i]);
            ans += 1;
            if (ans < res){
                res = ans;
                cnt = 1;
            } else if (ans == res) cnt += 1;
        }
    }

    cout << res << " " << cnt << "\n";
}
