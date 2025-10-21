#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> nums(n);
    nums[0] = a[0] - 1;
    nums[1] = a[1] - 1;
    if (nums[1] > nums[0]) nums[1]--;

    nums[1] += 1LL * n * (n - 1) / 2;
    nums[0] += nums[1] / (n - 1);
    nums[1] %= n - 1;
    nums[0] %= n;

    nums[0]++, nums[1]++;
    if (nums[1] >= nums[0]) nums[1]++;
    vector<int>vis1(n + 1, 0), vis2(n + 1, 1);
    for (int i = 2; i < n; i++) vis1[a[i]] = 1;
    for (int i = 0; i < 2; i++) vis2[nums[i]] = 0;

    int p1 = 1, p2 = 1;
    vector<int>mp(n + 1, 0);
    for (int i = 2; i < n; i++) {
        while(!vis1[p1]) p1++;
        while(!vis2[p2]) p2++;
        mp[p1++] = p2++;
    }

    for (int i = 2; i < n; i++) {
        nums[i] = mp[a[i]];
    }

    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
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
