#include <bits/stdc++.h>
using namespace std;

void solve(){
    const int N = 1e6;
    vector <int> sg(N+1);
    map <int,int> cnt;
    long long l = 0, r = 0;
    for (int i = 1; i <= N; ++ i){
        while (l*l*l*l < i){
            cnt[sg[l]] -= 1;
            l += 1;
        }
        while (r*r <= i && r < i){
            cnt[sg[r]] += 1;
            r += 1;
        }
        while (cnt[sg[i]]) sg[i] += 1;
    }

    int n;
    cin >> n;
    vector <long long> nums(n);
    for (auto &x : nums) cin >> x;
    sort(nums.begin(), nums.end());
    cnt.clear();

    l = 0, r = 0;
    long long res = 0;
    for (auto &x : nums){
        while (l*l*l*l < x){
            cnt[sg[l]] -= 1;
            l += 1;
        }
        while (r*r <= x && r < x){
            cnt[sg[r]] += 1;
            r += 1;
        }
        long long ans = 0;
        while (cnt[ans]){
            ans += 1;
        }
        res ^= ans;
    }

    cout << (res ? "Furlo" : "Rublo") << "\n";
}
