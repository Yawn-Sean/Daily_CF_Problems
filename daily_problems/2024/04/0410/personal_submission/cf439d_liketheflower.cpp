// submission: https://codeforces.com/contest/439/submission/255942503
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;
using LL = long long;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    unordered_set<int> nums(a.begin(), a.end());
    for(int i = 0; i < m; i++){
        nums.insert(b[i]);
    }
    vector<LL> prefix_suma(n+1, 0), prefix_sumb(m+1, 0);
    for (int i = 0; i < n; ++i){
        prefix_suma[i+1] = prefix_suma[i] + a[i];
    }
    for (int i = 0; i < m; ++i){
        prefix_sumb[i+1] = prefix_sumb[i] + b[i];
    }
    LL ret = INF;
    for(auto x: nums){
        auto ia = lower_bound(a.begin(), a.end(), x) - a.begin();
        auto ib = upper_bound(b.begin(), b.end(), x) -  b.begin();
        LL suma = x*ia - prefix_suma[ia];
        LL sumb = prefix_sumb[m] - prefix_sumb[ib] - x*(m-ib);
        ret = min(ret, suma + sumb);
    }
    cout << ret << endl;
    return 0;
}
