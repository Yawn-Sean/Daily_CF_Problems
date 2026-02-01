#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), arr = {4, 8, 15, 16, 23, 42};
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    vector<int> dp(6, 0);
    int ans = 0;
    for(int i = 0;i < n;i++){
        bool flag = false;
        for(int j = 0;j < 6;j++){
            if(a[i] == arr[j]){
                flag = true;
                if(j == 0){
                    dp[j]++;
                }else{
                    if(dp[j - 1] > 0){
                        dp[j - 1]--;
                        dp[j]++;
                    }else{
                        ans++;
                    }
                }
            }
        }
        if(!flag)   ans++;
    }
    for(int i = 0;i < 5;i++){
        ans += dp[i] * (i + 1);
    }
    cout << ans << "\n";
}

int main(){
    solve();
    return 0;
}