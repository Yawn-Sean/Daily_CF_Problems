/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-22 12:00 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123456;

int n;
LL a[N];
vector<LL> nums;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    } 
    sort(a + 1, a + 1 + n);
    int len = std::unique(a + 1, a + 1 + n) - a - 1;
    for (int i = 2; i <= len; i ++) {
        nums.push_back(a[i] - a[i - 1]);
    } 
    sort(nums.begin(), nums.end());
    int q;
    cin >> q;
    nums.push_back(2000000000000000000);
    vector<LL> sum(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); i ++) {
        sum[i] = nums[i - 1] + sum[i - 1];
    }
    while (q --) {
        LL l, r;
        cin >> l >> r;
        LL now = r - l + 1ll;
        int k = lower_bound(nums.begin(), nums.end(), now) - nums.begin();
        cout << sum[k] + now + 1ll * (nums.size() - k - 1ll) * now << ' ';  
    }
    return 0;
}

/*

*/
