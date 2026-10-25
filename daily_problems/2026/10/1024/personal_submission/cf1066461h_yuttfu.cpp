#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

const int N = 2e5+10;
int a[N],b[N];

void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i <= 2*n;i++) cin >> a[i];
    for(int i = 1;i <= 2*n;i++) cin >> b[i],ans -= b[i];
    priority_queue<int> q;
    for(int i = 1;i <= 2*n;i++){
        q.push(a[i] + b[i]);
        if(i % 2){
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}