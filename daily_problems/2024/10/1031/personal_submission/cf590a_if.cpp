#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int>p(n, -1);
    p[0] = a[0];
    p[n - 1] = a[n - 1];
    vector<int>b;
    vector<int>tar;
    tar.push_back(0);
    tar.push_back(n - 1);
    bool k = false;
    for(int i = 1; i < n - 1; i ++){
        if(a[i - 1] == a[i] or a[i + 1] == a[i]){
            tar.push_back(i);
            p[i] = a[i];
            k = false;
        }
        else{
            
            if(k){
                b[b.size() - 1] ++;
            }
            else{
                b.push_back(1);
                k = true;
            }
        }
    }
    sort(tar.begin(), tar.end());
    for(int i = 0; i < n; i++){
        if(p[i] == -1){
            int id1 = upper_bound(tar.begin(), tar.end(), i) - tar.begin();
            if(abs(tar[id1] - i) < abs(tar[id1 - 1] - i)){
                p[i] = a[tar[id1]];
            }
            else{
                p[i] = a[tar[id1 - 1]];

            }
        }
    }
    int ans = 0;
    for(auto i : b){
        ans = max((i + 1) / 2, ans);
    }
    cout << ans << endl;
    for(auto i : p){
        cout << i << " ";
    }
    return;

}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
