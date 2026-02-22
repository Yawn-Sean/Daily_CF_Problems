#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << "1\n";
        cout << "1\n";
    }else if(n == 2){
        cout << "-1\n";
    }else{
        int base = 3;
        int sum = 3;
        vector<int> nums;
        for(int i = 3;i <= n;i++){
            nums.push_back(base);
            sum += base;
            base *= 2;
        }
        cout << sum << "\n";
        cout << "1 2 ";
        for(int num : nums){
            cout << num << " ";
        }   cout << "\n";
    }
}

int main(){
    solve();
    return 0;
}