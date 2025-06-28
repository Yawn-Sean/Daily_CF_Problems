/*
1 2 3 4 5 6
先找哪个数只出现了 1 次，这个数必然是第一个或者最后一个数
假设 val 出现了 1 次，则找和 val 同组的出现了两次的那个数
然后第 3 个数就知道了，之后就用已知的两个数去推第三个数
一直这样做下去，就能把整个数列还原出来
如何快速找？
对于每个三元组，取两个排列一下，哈希成一个数作为键，值就是第三个数
*/

struct Group {
    LL a, b, c;
};

LL n, cnt[N];
Group groups[N];
bool used[N];
map<LL, vector<int>> next_val;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n - 2; i++) {
        cin >> groups[i].a >> groups[i].b >> groups[i].c;
        next_val[groups[i].a * (n + 1) + groups[i].b].push_back(groups[i].c);
        next_val[groups[i].b * (n + 1) + groups[i].a].push_back(groups[i].c);
        next_val[groups[i].a * (n + 1) + groups[i].c].push_back(groups[i].b);
        next_val[groups[i].c * (n + 1) + groups[i].a].push_back(groups[i].b);
        next_val[groups[i].b * (n + 1) + groups[i].c].push_back(groups[i].a);
        next_val[groups[i].c * (n + 1) + groups[i].b].push_back(groups[i].a);
        cnt[groups[i].a]++;
        cnt[groups[i].b]++;
        cnt[groups[i].c]++;
    }

    LL first_val = -1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) {
            first_val = i;
            break;
        }
    }
    assert(first_val > 0);
    LL second_val = -1;
    for (int i = 1; i <= n - 2; i++) {
        if (groups[i].a == first_val || groups[i].b == first_val || groups[i].c == first_val) {
            if (cnt[groups[i].a] == 2) {
                second_val = groups[i].a;
                break;
            } else if (cnt[groups[i].b] == 2) {
                second_val = groups[i].b;
                break;
            } else if (cnt[groups[i].c] == 2) {
                second_val = groups[i].c;
                break;
            }
        }
    }
    
    assert(second_val > 0);
    cout << first_val << " " << second_val << " ";
    used[first_val] = true;
    used[second_val] = true;

    for (int i = 3; i <= n; i++) {
        LL key = first_val * (n + 1) + second_val;
        for (auto &val : next_val[key]) {
            if (!used[val]) {
                used[val] = true;
                cout << val << " ";
                first_val = second_val;
                second_val = val;
                break;
            }
        }
    }
}
