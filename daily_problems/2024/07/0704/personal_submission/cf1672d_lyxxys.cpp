#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050, mod = 1e9+7, inf = 1e9;

void solve(){
    int n;
    cin >> n;
    vector <int> A(n+2), B(n+2);
    map<int,int> mp;
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
    }
    for (int i = 1; i <= n; ++ i){
        cin >> B[i];
    }

    int i = n, j = n;
    while (j > 0){
        if (i > 0 && A[i] == B[j]){
            -- i, -- j;
            continue;
        }
        // mp[x] 是后面的数字对前面的贡献
        // 由于 B 是 A 的排列，若B[j] == B[j+1]，则一定能在A[i+1]的前面找到A[k] = A[i+1]，k < i+1
        if (B[j] == B[j+1]){
            ++ mp[B[j]];
            -- j;
        } else if (mp[A[i]]){
            -- mp[A[i]];
            -- i;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
