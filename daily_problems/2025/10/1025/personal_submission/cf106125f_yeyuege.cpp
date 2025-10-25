#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> num(n + 1, 0);
    while(true) {
        int cnt = 0;
        int l = 1, r = 1;
        for (int i = 1; i <= n; i++) {
            int temp = 0;
            for (int j = i; j <= n; j++) {
                temp += (num[j] == 0);
                if (temp - (j - i + 1 - temp) > cnt) {
                    l = i, r = j;
                    cnt = temp;
                }
            }
        }

        cout << l << " " << r << endl;
        cout.flush();
        for (int i = 1; i <= n; i++) cin >> num[i];
        int p;
        cin >> p;
        if (p >= 70) break;
    }
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
