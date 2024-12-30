#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5050, mod = 998244353;

void solve(){
    int n;
    cin >> n;
    vector <int> nums(n+1);
    vector <array<int,2>> b(n+1);
    for (int i = 1; i <= n; ++ i) cin >> nums[i], b[i][0] = nums[i], b[i][1] = i;//b[i][1]第i个数在nums数组的位置

    sort(b.begin()+1, b.end(), [&](array<int,2> &t1, array<int,2> &t2){
        return t1[0] < t2[0];
    });
    vector <array<int,2>> ans;
    int gap = n/2;
    for (int i = 1; i <= n; ++ i){
        int pos = b[i][1];
        if (nums[i] == i) continue;
        int delta = abs(pos-i);
        if (delta >= gap){
            b[nums[i]][1] = pos, b[i][1] = i;  
            swap(nums[pos], nums[i]);
            ans.push_back({i, pos});
        } else {
            b[nums[i]][1] = pos, b[i][1] = i;
            swap(nums[pos], nums[i]);

            if (n - pos >= gap){
                ans.push_back({pos, n}), ans.push_back({i, n}), ans.push_back({pos, n});  //1:以第n个为跳板
            } else {
                if (i <= gap){
                    ans.push_back({1, pos}), ans.push_back({1, n}), ans.push_back({i, n});   //2:交换1，pos,转化为1
                    ans.push_back({1, n}), ans.push_back({1, pos});                   
                } else {
                    ans.push_back({1, pos}), ans.push_back({1, i}), ans.push_back({1, pos});  //以第i个为跳板
                }
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto it : ans)
        cout << it[0] << " " << it[1] << "\n";
    
}
