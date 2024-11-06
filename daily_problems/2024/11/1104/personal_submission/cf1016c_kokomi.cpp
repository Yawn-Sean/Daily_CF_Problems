#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
ll a[N], b[N];
ll ans;
ll da[N], db[N], sa[N], sb[N], ra[N], rb[N];
//一共只有两种移动方式（样例给出）可以前i列用方案1，后n-i列用方案2，对i进行枚举
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = n; i >= 1; i--){
        da[i] = da[i + 1] + a[i];
        db[i] = db[i + 1] + b[i];
        sa[i] = sa[i + 1] + da[i + 1];
        sb[i] = sb[i + 1] + db[i + 1];
        ra[i] = ra[i + 1] + 1LL * (n - i) * a[i];
        rb[i] = rb[i + 1] + 1LL * (n - i) * b[i];
    }
    ll s = 0;
    int t = 0;
    //对分割点i枚举
    for(int i = 1; i <= n; i++){
        if(i % 2 == 1){//奇数列
            ans = max(ans, s + sa[i] + rb[i] + 1LL * t * da[i] + 1LL * (t + n - i + 1) * db[i]);
            s += 1LL * t * a[i];
            t++;
            ans = max(ans, s + sb[i] + ra[i + 1] + 1LL * t * db[i] + 1LL * (t + n - i + 1) * da[i + 1]);
            s += 1LL * t * b[i];
            t++;
        }else{
            ans = max(ans, s + sb[i] + ra[i] + 1LL * t * db[i] + 1LL * (t + n - i + 1) * da[i]);
            s += 1LL * t * b[i];
            t++;
            ans = max(ans, s + sa[i] + rb[i + 1] + 1LL * t * da[i] + 1LL * (t + n - i + 1) * db[i + 1]);
            s += 1LL * t * a[i];
            t++;
        }
    }
    cout << ans << endl;

}