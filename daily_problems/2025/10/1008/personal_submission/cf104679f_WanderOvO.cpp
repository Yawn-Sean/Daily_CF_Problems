/*
构造一个尽可能长的数组，无重复元素且 >= 0，使得 or = a, xor = b
or = a，限定了只有哪些位上可以有 1
xor = b，限定了上面这些位的 1 的出现次数的奇偶性
一种显然的无解情况是 b 的某位为 1，但 a 的这一位是 0
排除上述情况后，考虑构造出一组解，比如包含两个数，一个数是 a，另一个数是 a 比 b 多的那些为 1 的位
这样有可能会导致没有 1 了，所以要检查一下，这也是可能无解的
a, b <= 1e4，100 组数据
我们先考虑把只有 a 的这些位为 1 的数都筛出来，时间是可以接受的
然后怎么搞呢？
如果都是 0 和 1 这种一位数，做起来是容易的，首先 0 不影响结果可以全选上，1 选奇数/偶数个就好
如果是多位数呢？我们能否考虑，从前 i 个候选数中选，异或出 j 至多能选多少数，这个需要 1e8 的 DP

羊的提示：你其实可以几乎把所有候选数都选上
确实是这样的，都选上之后，你大概只需要去掉一个数，就可以得到想要的异或结果，接着只要检查去掉之后的 or sum 还对不对就好了
*/ 

int a, b;

void meibao() {
    cin >> a >> b;
    for (int i = 15; i >= 0; i--) {
        int b1 = (a >> i) & 1;
        int b2 = (b >> i) & 1;
        if (b1 == 0 && b2 == 1) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> candidates;
    int xor_sum = 0;
    for (int i = 0; i <= a; i++) {
        bool ok = true;
        for (int j = 15; j >= 0; j--) {
            int b1 = (a >> j) & 1;
            int b2 = (i >> j) & 1;
            if (b1 < b2) {
                ok = false;
                break;
            }
        }

        if (ok) {
            candidates.push_back(i);
            xor_sum ^= i;
        }
    }

    if (xor_sum == b) {
        cout << candidates.size() << "\n";
        for (auto val : candidates) {
            cout << val << " ";
        }
        cout << "\n";
    } else {
        int deleted_value = 0;
        for (int j = 15; j >= 0; j--) {
            int b1 = (xor_sum >> j) & 1;
            int b2 = (b >> j) & 1;
            if (b1 != b2) {
                deleted_value += (1 << j);
            }
        }

        bool ok = false;
        int or_sum = 0;
        for (auto val : candidates) {
            if (val == deleted_value) {
                ok = true;
            } else {
                or_sum |= val;
            }
        }
        assert(ok);

        if (or_sum == a) {
            cout << candidates.size() - 1 << "\n";
            for (auto val : candidates) {
                if (val != deleted_value) {
                    cout << val << " ";
                }
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

}   
