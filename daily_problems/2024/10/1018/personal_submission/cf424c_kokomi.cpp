#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll p[N], pre[N];
//模具有周期性
int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        ans ^= p[i];
        pre[i] = pre[i - 1] ^ (i);
    }
    for(int i = 1; i <= n; i++){
        int count = n / i;
        if(count % 2){
            ans ^= pre[i - 1];
        }
        ans ^= pre[n % i];
    }
    cout << ans;
    return 0;
}