// submission: https://codeforces.com/contest/863/submission/257115076
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
using PII = pair<int, int>;
const int INF = 0x3f3f3f3f;
// we need consider for u, v and v + 1, so it is 3*2e5
const int MX =  6e5+10;
int spt[MX][25];
void buildST(int n, vector<int> &ar)
{
    for (int i = 0; i < n; i++) spt[i][0] = ar[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            spt[i][j] = min(spt[i + (1 << (j - 1))][j - 1] , spt[i][j - 1]);
        }
    }
}

int query(int l, int r)
// query the min value in the range [l, r]
{
    if(l>r) return INF;
    int j = 31 - __builtin_clz(r - l+1);
    return min(spt[l][j], spt[r - (1 << j) + 1][j]);
}

int main(){
    int n;cin>>n;
    int u, v;
    vector<PII> tvs;
    vector<int> nums;
    unordered_map<int, int> num_idx;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        tvs.push_back({u, v});
        nums.push_back(u);
        nums.push_back(v);
        /* If do not add the following line will fail at this case:
         * 
         * 3
         *3687 7959
         *4918 9822
         *8049 11728
         * */
        nums.push_back(v + 1);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    const int m = nums.size();
    for (int i = 0; i < m; i++) {
        num_idx[nums[i]] = i;
    }
    int i, j;
    vector<int> diff(m+1, 0);
    for (auto [l, r]: tvs) {
        i = num_idx[l];
        j = num_idx[r];
        diff[i]++;
        diff[j+1]--;
    }
    int ret = -1;
    vector<int> num_tvs(m+1, 0);
    int sum = 0;
    for (int i = 0; i < m + 1;i++){
        sum += diff[i];
        num_tvs[i] = sum;
    }
    buildST(m+1, num_tvs);
    int idx = 1;
    for (auto [l, r]: tvs){
        i = num_idx[l];
        j = num_idx[r];
        if (query(i, j) > 1) {ret = idx; break;}
        idx++;
    }
    cout << ret << endl;
    return 0;
}
