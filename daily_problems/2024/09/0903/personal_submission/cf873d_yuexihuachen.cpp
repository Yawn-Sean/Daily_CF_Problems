#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int>pii;
vector<int>ans;
int k;

void unsort(int l, int r){
    if(!k || l+1 >= r) return; //没有交换次数 或单独元素
    k -= 2;
    int mid = (l + r) >> 1;
    swap(ans[mid-1], ans[mid]);
    unsort(l, mid);
    unsort(mid, r);
}

void solve() {
    int n;
    cin >> n >> k;
    if(!(k&1)){
        cout << -1 << endl;
        return;
    }
    ans.resize(n);
    iota(ans.begin(), ans.end(),1);
    k--;
    unsort(0,n);
    if(k){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
  //  cin >> T;
    while (T--)
        solve();
    return 0;
}
