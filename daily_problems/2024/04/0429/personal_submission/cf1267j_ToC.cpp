// https://codeforces.com/contest/1267/submission/258854772
void sol()
{
    cin >> n;
    int x;
    unordered_map<int, int> v2c;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v2c[x]++;
    }
    vector<int> cnt;
    for (auto &[v, c] : v2c) {
        cnt.push_back(c);
    }
    int sup = *min_element(cnt.begin(), cnt.end()) + 1;
    int inf = 2, res = INF;
    for (int s = sup; s >= inf; s--) {
        bool flag = true;
        int tmp = 0;
        for (auto &c : cnt) {
            /*
                先有q个完整的s，最后一个是不完整的r
                如果r == 0或者r == s -1,就不用补最后一个
                如果 1 <= r <= s - 2,那么需要补充s - 1 - r到最后一个
                需要从前面的q个填满的里面，每个取一个放到最后，所以需要q >= s - 1 - r
            */
            int q = c / s, r = c % s;
            if ((r == 0) || (r == s - 1) || (q >= s - 1 - r)) {
                tmp += (c + s - 1) / s;
            } else { 
                flag = false; break;
            }
        }
        if (flag) {
            res = min(res, tmp);
        }
    }
    cout << res << '\n'; 
}
