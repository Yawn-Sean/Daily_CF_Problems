/*
    Bonelight (=v=)
    20251103 Bonelight's submission for 106159/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
// #define INF 2e9
#define INF (int)2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define ForR(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define RofR(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define For(_i,_l,_r) for(int _i = _l; _i < _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i > _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

void solve(){
    auto kmp = [&](VC &nums) -> VC {
        int n = nums.size();
        VC ne(n);
        for(int i = 1, j = 0; i < n; i ++){
            while(j && nums[i] != nums[j]) j = ne[j - 1];
            if(nums[i] == nums[j]) j ++;
            ne[i] = j;
        }
        return ne;
    };

    int M = 1e4;
    int n,m; cin >> n >> m;
    VC nums1(n), nums2(m);
    For(i,0,n) cin >> nums1[i];
    For(i,0,m) cin >> nums2[i];

    VC vals;
    For(i,1,m) vals.emplace_back((nums2[i] - nums2[i-1] + M) % M); 
    vals.emplace_back(-1); 
    For(i,1,n) vals.emplace_back((nums1[i] - nums1[i-1] + M) % M); 

    VC ne = kmp(vals);
    VC cnt(M);
    For(i,m,n+m-1){
        if(ne[i] == m-1){
            cnt[ (nums2[0] - nums1[i - 2*(m - 1)] + M) % M ] ++;
        }
    }

    auto mx = max_element(all(cnt));
    cout << mx - cnt.begin() << ' ' << *mx << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1;
    while(T --) solve();
    return 0;
}
