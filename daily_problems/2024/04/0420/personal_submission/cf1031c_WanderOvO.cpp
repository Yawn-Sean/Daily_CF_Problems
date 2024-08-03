/*
看的总时间不超过 a + b，先算出来上限
考虑 <= a + b 的最大的 1 + 2 + ... + i = s，i 就是最多复习的数量，肯定能凑出来
s = c + d，其中 c <= a，d <= b
我们令 d = b，则 c = s - d 即可
然后就是考虑怎么分
考虑把 c 变成前缀 + 后缀 + 一个中间的，即 1 + 2 + ... + j + k + l + l + 1 + ... + i
可以二分出来最大的满足 1 + 2 + ... + j <= c 的数，然后就可以考虑怎么调整出来了

*/

int T;
LL a, b, sum[N];
bool fi[N];

void solve1() {
    cin >> a >> b;
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + i;
    }
    
    int tot = upper_bound(sum + 1, sum + N, a + b) - sum - 1;
    LL s = sum[tot];
    LL d = b, c = max(s - d, 0LL);
    // cout << "c: " << c << " " << d << "\n";
    int pos = upper_bound(sum + 1, sum + N, c) - sum - 1;
    // cout << "pos: " << pos << "\n";
    int left_pos = pos;
    for (int i = pos; i >= 0; i--) {
        LL ss = sum[i] + sum[tot] - sum[tot - (pos - i)];
        // cout << i << " " << tot - pos + i + 1 << " " << ss << "\n";
        if (ss >= c) {
            left_pos = i;
            break;
        }
    }
    
    LL ss = sum[left_pos] + sum[tot] - sum[tot - (pos - left_pos)];
    vector<int> v1, v2;
    if (ss == c) {
        for (int i = 1; i <= left_pos; i++) {
            fi[i] = true;
            v1.pb(i);
        }
        for (int i = tot - (pos - left_pos) + 1; i <= tot; i++) {
            fi[i] = true;
            v1.pb(i);
        }
    } else {
        int right_pos = tot - (pos - left_pos) + 2;
        for (int i = 1; i <= left_pos; i++) {
            fi[i] = true;
            v1.pb(i);
        }
        for (int i = right_pos; i <= tot; i++) {
            fi[i] = true;
            v1.pb(i);
        }
        for (int i = left_pos + 1; i < right_pos; i++) {
            if (sum[left_pos] + sum[tot] - sum[right_pos - 1] + i == c) {
                fi[i] = true;
                v1.pb(i);
                break;
            }
        }
    }
    for (int i = 1; i <= tot; i++) {
        if (!fi[i]) {
            v2.pb(i);
        }
    }
    cout << v1.size() << "\n";
    for (auto v : v1) {
        cout << v << " ";
    }
    cout << "\n";
    cout << v2.size() << "\n";
    for (auto v : v2) {
        cout << v << " ";
    }
}                                                                                                                  
