// problem link: https://codeforces.com/contest/1201/problem/D
// submission link:https://codeforces.com/contest/1201/submission/256729351
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;
const int NINF = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int main(){
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> mn(n, NINF), mx(n, -1);
    int r, c;
    int max_has_treasure = 0;
    for(int i = 0; i < k; i++){
        cin >> r >> c;
        r--; c--;
        max_has_treasure = max(max_has_treasure, r);
        mn[r] = min(mn[r], c);
        mx[r] = max(mx[r], c);
    }
    vector<int> safe_columns(q, 0);
    for (int i = 0; i < q; ++i){
        cin >> safe_columns[i];
        safe_columns[i]--;
    }
    sort(safe_columns.begin(), safe_columns.end());
    LL dis_left_most = INF, dis_right_most = INF;
    LL new_dis_left_most = INF, new_dis_right_most = INF;
    int l0, r0; // prev level left most and right most treasure position
    int l1, r1; // curr level left most and right most treasuer position
    int p; // safe column position idx
    for (int i = 0; i <= max_has_treasure; ++i){
        if (i == 0){
            if (mn[i] == NINF){
                new_dis_left_most = 0;
                new_dis_right_most = 0;
                mn[0] = 0;
                mx[0] = 0;
            } else {
                new_dis_left_most = mx[0] + mx[0] - mn[0];
                new_dis_right_most = mx[0];
            }
        } else {
            if (mn[i] == NINF){
                dis_left_most++;
                dis_right_most++;
                // add one step to move to the top row and 
                // move the prev row's left most and right most position to the current row.
                mn[i] = mn[i-1];
                mx[i] = mx[i-1];
                new_dis_left_most = dis_left_most;
                new_dis_right_most = dis_right_most;
            } else {
                l1 = mn[i]; r1 = mx[i];
                l0 = mn[i-1]; r0 = mx[i-1];
                LL &dl1= new_dis_left_most;
                LL & dr1= new_dis_right_most;
                LL & dl0 = dis_left_most;
                p = lower_bound(safe_columns.begin(), safe_columns.end(), l0) - safe_columns.begin();
                for (int i = -1; i <= 1; ++i){
                    int new_p = p + i;
                    if (new_p < 0 || new_p >= q) continue;
                    int p_loc = safe_columns[new_p];
                    LL dis_to_p = abs(p_loc - l0);
                    LL dis_to_r_to_l = abs(r1 - p_loc) + r1 - l1;
                    LL dis_to_l_to_r = abs(l1 - p_loc) + r1 - l1;
                    dl1 = min(dl1, dl0 + dis_to_p + dis_to_r_to_l + 1);
                    dr1 = min(dr1, dl0 + dis_to_p + dis_to_l_to_r + 1);
                }
                LL& dr0 = dis_right_most;
                p = lower_bound(safe_columns.begin(), safe_columns.end(), r0) - safe_columns.begin();
                for (int i = -1; i <= 1; ++i){
                    int new_p = p + i;
                    if (new_p < 0 || new_p >= q) continue;
                    int p_loc = safe_columns[new_p];
                    LL dis_to_p = abs(p_loc - r0);
                    LL dis_to_r_to_l = abs(r1 - p_loc) + r1 - l1;
                    LL dis_to_l_to_r = abs(l1 - p_loc) + r1 - l1;
                    dl1 = min(dl1, dr0 + dis_to_p + dis_to_r_to_l + 1);
                    dr1 = min(dr1, dr0 + dis_to_p + dis_to_l_to_r + 1);
                }
            }
        }
        dis_left_most = new_dis_left_most;
        dis_right_most = new_dis_right_most;
        new_dis_left_most = INF;
        new_dis_right_most = INF;
    }
    LL ret = min(dis_left_most, dis_right_most);
    cout << ret << endl;
    return 0;
}
