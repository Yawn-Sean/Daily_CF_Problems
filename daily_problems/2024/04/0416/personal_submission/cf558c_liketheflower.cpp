// reference: https://www.cnblogs.com/herumw/p/9464712.html
// submission link: https://codeforces.com/contest/558/submission/256992045
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int MAX_NUM = 2e5;
const int N =MAX_NUM +10;
const int INF = 0x3f3f3f3f;
struct Node{
    int count;
    int steps;
}reachable[N];

void update(int num){
    int x = num;
    int step = 0;
    while (x < MAX_NUM){
        reachable[x].count++;
        reachable[x].steps += step;
        x <<= 1;
        step++;
    }
    x = num;
    step = 0;
    while (x > 0){
        if (x != num){
            reachable[x].count++;
            reachable[x].steps += step;
        }
        if (x != 1 && (x % 2 == 1)){
            int new_step = step + 2;
            int new_x = (x / 2)*2;
            while (new_x < MAX_NUM){
                reachable[new_x].count++;
                reachable[new_x].steps += new_step;
                new_x <<= 1;
                new_step++;
            }
        }
        x >>= 1;
        step++;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (auto x: nums){
        update(x);
    }
    int ret = INF;
    for (int i = 0; i < N; ++i){
        if (reachable[i].count == n){
            ret = min(ret, reachable[i].steps);
        }
    }
    cout << ret << endl;
    return 0;
}
