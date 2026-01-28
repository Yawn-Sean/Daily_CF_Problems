#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n == 3){
        cout << 1 << " " << 1 << " " << 2 << "\n";
        cout << 1 << " " << 4 << " " << 3 << "\n";
        cout << 2 << " " << 3 << " " << 3 << "\n";
    } else {
        vector<vector<long long>> ans(n, vector<long long>(n, 1));

        if(n > 2){
            long long v = 1024 - n;
            if(n % 2 == 0){
                ans[0][0] += v;
                for(int i = 1; i <= n - 2; ++i){
                    ans[i][i + 1] += v;
                }
                ans[n - 1][1] += v;
            } else {
                ans[0][0] += v;
                ans[1][n - 2] += v;
                for(int i = 2; i <= n - 3; ++i){
                    ans[i][i - 1] += v;
                }
                ans[n - 2][n - 1] += v;
                ans[n - 1][n - 3] += v;
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(j) cout << " ";
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
