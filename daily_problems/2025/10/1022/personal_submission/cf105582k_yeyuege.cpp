#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define endl "\n"

void solve(){
    int n;
    cin >> n;
    if (n & 1) {
        n--;
        cout << 12 << " " << -9 << endl;
        stack<pii>st;
        for (int i = 0; i < n / 2; i++) {
            int x = (i % 2 == 0) ? 0 : 4;
            int y = i * 3;
            st.push({x + 24, y + 7});
            cout << x << " " << y << endl;
        }
        while (!st.empty()) {
            auto [x, y] = st.top();
            st.pop();   
            cout << x << " " << y << endl;
        }
    }
    else {
        stack<pii>st;
        for (int i = 0; i < n / 2; i++) {
            int x = (i % 2 == 0) ? 0 : 3;
            int y = i * 4;
            st.push({x + 4, y + 3});
            cout << x << " " << y << endl;
        }
        while (!st.empty()) {
            auto [x, y] = st.top();
            st.pop();
            cout << x << " " << y << endl;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
