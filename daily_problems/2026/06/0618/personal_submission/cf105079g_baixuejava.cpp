#include<iostream>
#include <algorithm>
#include<vector>
#include <stack>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define all(a) a.begin(), a.end()

typedef long long ll;
bool mult_test = false;
const char ln = '\n';
const int mod1 = 998244353, mod2 = 1e9 + 7, N = 3e5 + 7, inf = 1e9 + 7;
const int mv[5] = {-1, 0, 1, 0, -1};



void INIT(){ 
    mult_test = false;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    priority_queue<ll> q;
    ll sum = 0;
    for(int &x : a) q.push(x);
    for(int x : b){
        sum += x;
        ll k = q.top() + sum;
        q.pop();
        k = k - k / 2LL;
        q.push(k - sum);
    }
    ll ans = n * sum;
    while(q.size()){
        ans += q.top();
        q.pop();
    }
    cout << ans << ln;
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    INIT();
    int T = 1;
    if(mult_test) cin >> T; 
    while(T --> 0) solve();
}