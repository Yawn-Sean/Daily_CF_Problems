#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }

    int total = accumulate(nums.begin(), nums.end(), 0);

    if(total % 2){
        cout << -1 << "\n";
        return 0;
    }

    int M = total / 2;
    vector<int> dp(M + 1, -2);
    dp[0] = -1;

    for(int i = 0; i < n; ++i){
        int x = nums[i];
        for(int j = M; j >= x; --j){
            if(dp[j - x] != -2 && dp[j] == -2){
                dp[j] = i;
            }
        }
    }

    if(dp[M] == -2){
        cout << -1 << "\n";
        return 0;
    }

    vector<int> vis(n, 0);
    int cur = M;
    while(cur > 0){
        int idx = dp[cur];
        vis[idx] = 1;
        cur -= nums[idx];
    }

    vector<int> v1, v2;
    for(int i = 0; i < n; ++i){
        if(vis[i]) v1.push_back(nums[i]);
        else v2.push_back(nums[i]);
    }

    int s1 = 0, s2 = 0;
    int pt1 = 0, pt2 = 0;
    vector<int> ans;

    while(pt1 < (int)v1.size() || pt2 < (int)v2.size()){
        if(s1 <= s2){
            s1 += v1[pt1];
            ans.push_back(v1[pt1]);
            pt1++;
        } else {
            s2 += v2[pt2];
            ans.push_back(v2[pt2]);
            pt2++;
        }
    }

    for(int i = 0; i < (int)ans.size(); ++i){
        cout << ans[i] << (i + 1 == (int)ans.size() ? '\n' : ' ');
    }

    return 0;
}
