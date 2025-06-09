/*
题目约定了最后一次肯定是 ?，并且最后一次 ? 之前一定没猜对（当然，最后一次也不一定猜对了）
每次被电，把不在这个字符串的字符从 set 中删了
每次不被电，就把字符从 set 中删了
除了最后一次之外的猜测，都能从 set 中删除一个元素
只要 set 中的元素有多于 1 个从来没被猜过，则确定不了，一次都没少挨电
最后 set 中如果只剩下一个元素，则我们就求出来了到底哪个字母导致被电
接下来只需要重新遍历一遍所有操作，把总共被电以及猜错的次数算一下
期间，算一下从哪一步开始就唯一确定了字母，记录一下这个最小被电次数
*/

struct Operation {
    string op, s;
};

int n;
Operation ops[N];

void meibao() {
    cin >> n;
    set<char> st;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        st.insert(ch);
    }
    for (int i = 1; i < n; i++) {
        cin >> ops[i].op >> ops[i].s;
        if (ops[i].op == "!") {
            if (st.size() == 0) {
                for (auto ch : ops[i].s) {
                    st.insert(ch);
                }
            } else {
                set<char> deleted;
                for (auto ch : st) {
                    bool exist = false;
                    for (auto ch2 : ops[i].s) {
                        if (ch == ch2) {
                            exist = true;
                            break;
                        }
                    }
                    if (!exist) {
                        deleted.insert(ch);
                    }
                }
                for (auto ch : deleted) {
                    st.erase(ch);
                }
            }
        } else if (ops[i].op == ".") {
            for (auto ch : ops[i].s) {
                st.erase(ch);
            }
        } 
    }

    for (int i = 1; i < n; i++) {
        if (ops[i].op == "?") {
            st.erase(ops[i].s[0]);
        }
    }

    cin >> ops[n].op >> ops[n].s;
    if (st.size() > 1) {
        cout << "0\n";
        return;  
    } 

    // 下面应该有 bug
    char target = *st.begin();
    st.clear();
    for (char ch = 'a'; ch <= 'z'; ch++) {
        st.insert(ch);
    }
    int attacked = 0, min_attacked = -1;
    set<char> failed;
    for (int i = 1; i <= n; i++) {
        if (ops[i].op == "!") {
            attacked++;
            if (st.size() == 0) {
                for (auto ch : ops[i].s) {
                    st.insert(ch);
                }
            } else {
                set<char> deleted;
                for (auto ch : st) {
                    bool exist = false;
                    for (auto ch2 : ops[i].s) {
                        if (ch == ch2) {
                            exist = true;
                            break;
                        }
                    }
                    if (!exist) {
                        deleted.insert(ch);
                    }
                }
                for (auto ch : deleted) {
                    st.erase(ch);
                }
            }
        } else if (ops[i].op == ".") {
            for (auto ch : ops[i].s) {
                st.erase(ch);
            }
        } else {
            if (ops[i].s[0] != target) {
                attacked++;
                st.erase(ops[i].s[0]);
                failed.insert(ops[i].s[0]);
            }
        }
        for (auto ch : failed) {
            st.erase(ch);
        }
        if (st.size() == 1 && min_attacked == -1) {
            min_attacked = attacked;
        }
    }

    if (min_attacked >= 0) {
        cout << attacked - min_attacked << "\n";
    } else {
        cout << "0" << "\n";
    }
}
