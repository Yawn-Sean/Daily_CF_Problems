// submission link: https://codeforces.com/contest/622/submission/271174759

#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    // 严重怀疑这题考的是这个cin和cout的解绑，给我整红温了
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, l, r, x;
    cin >> n >> m;
    vector<int> nums(n + 1), left(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> nums[i];
        left[i] = nums[i] == nums[i - 1] ? left[i - 1] : i;
    }
 
    while(m --){
        cin >> l >> r >> x;
        if(nums[r] == x){
            cout << (l > left[r] - 1 ? -1 : left[r] - 1) << endl;
        }else{
            cout << r << endl;
        }
    }
 
    return 0;
}