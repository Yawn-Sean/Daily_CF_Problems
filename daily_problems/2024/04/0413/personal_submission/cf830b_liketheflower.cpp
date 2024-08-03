// problem link: https://codeforces.com/contest/830/problem/B
// submission link: https://codeforces.com/contest/830/submission/256402873
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class FenwickTreeOneBasedIndexing {
public:
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
	this->n = n + 1;
	bit.assign(n + 1, 0);
    }

    long long sum(int idx) {
	long long ret = 0;
	for (++idx; idx > 0; idx -= idx & -idx)
	    ret += (long long)bit[idx];
	return ret;
    }

    void add(int idx, int delta) {
	for (++idx; idx < n; idx += idx & -idx)
	    bit[idx] += delta;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, vector<int>> num_idxes;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i){
	num_idxes[a[i]].push_back(i);
	cnt[a[i]]++;
    }
    FenwickTreeOneBasedIndexing bit(n);
    for (int i = 0; i < n; i++) bit.add(i, 1);
    long long ret = 0;
    vector<int> unique_nums(a.begin(), a.end());
    sort(unique_nums.begin(), unique_nums.end());
    unique_nums.erase(unique(unique_nums.begin(), unique_nums.end()), unique_nums.end());
    int curr_idx = 0;
    int next_idx = 0;
    for (auto num : unique_nums){

	int num_cnt = cnt[num];
	if (num_cnt == 1) {
	    next_idx = num_idxes[num][0];
	    if (curr_idx == 0){
		ret += bit.sum(next_idx);
	    } else if (next_idx >= curr_idx){
		ret += bit.sum(next_idx) - bit.sum(curr_idx - 1);
	    } else /*next_idx < curr_idx*/{
		ret += bit.sum(n - 1) - bit.sum(curr_idx - 1) + bit.sum(next_idx);
	    }
	    curr_idx = (next_idx + 1 ) % n;
	    bit.add(next_idx, -1);
	    continue;
	}
	while (cnt[num]){
	    cnt[num] --;
	    auto idx = lower_bound(num_idxes[num].begin(), num_idxes[num].end(), curr_idx) - num_idxes[num].begin();
	    if (idx == (int)num_idxes[num].size()){
		next_idx = num_idxes[num][0];
		ret += bit.sum(n - 1) - bit.sum(curr_idx - 1) + bit.sum(next_idx);
	} else {
		next_idx = num_idxes[num][idx];
		ret += bit.sum(next_idx) - bit.sum(curr_idx - 1);
	    }
	    curr_idx = (next_idx + 1) % n;
	    bit.add(next_idx, -1);
	}
    }
    cout << ret << endl;
    return 0;
}
