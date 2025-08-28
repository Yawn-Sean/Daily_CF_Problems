#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

const int N = 100010;
const ll inf = 1LL << 60;

ll b[N],pre[N],n;

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> n;

    ll sum = 0,ans = -inf;

    for (int i = 1;i <= n; i++) {
        cin >> b[i];
        b[i] = -b[i];
        sum += b[i];
        pre[i] = pre[i - 1] + b[i];
    }

    ll mx = 0;
    for (int i = 1; i <= n; i++) {
    	  mx = max(mx,pre[i]);
        ans = max(ans,sum - 2 * pre[i] + 2 * mx);
    }

    cout << ans << "\n";

    return 0;
}
