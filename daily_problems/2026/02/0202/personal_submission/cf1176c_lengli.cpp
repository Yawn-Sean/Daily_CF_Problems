#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int,int> d = {
        {4, 1}, {8, 2}, {15, 3},
        {16, 4}, {23, 5}, {42, 6}
    };

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }

    vector<int> cnt(7, 0);
    cnt[0] = n;

    for(int v : nums){
        int x = d[v];  

        if(cnt[x - 1] > 0){
            cnt[x - 1]--;
            cnt[x]++;
        }
    }


    cout << n - 6 * cnt[6] << "\n";

    return 0;
}
