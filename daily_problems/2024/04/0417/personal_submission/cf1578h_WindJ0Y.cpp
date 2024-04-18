#include <bits/stdc++.h>
using namespace std;

void work() {
    string str; cin >> str;

    stack<string> op;
    stack<int> nums;

    for (int i = str.size() - 1; i >= 0; i--) {
        string cur = str.substr(i, 1);
        if (cur == ")" && i && str[i - 1] == '(') {
            cur = "()";
            i --;
        } else if (cur == ">") {
            cur = "->";
            i --;
        }

        auto calc = [&](){
            while (!op.empty() && op.top() == "->" && nums.size() >= 2) {
                op.pop();
                int va = nums.top(); nums.pop();
                int vb = nums.top(); nums.pop();
                nums.push(max(va + 1, vb));
            }
        };

        if (cur == ")" || cur == "->") {
            op.push(cur);
        } else if (cur == "(") {
            assert(op.top() == ")");
            op.pop();
            calc();
        } else if (cur == "()") {
            nums.push(0);
            calc();
        } else {
            assert(false);
        }
    }
    assert(nums.size() == 1 && op.size() == 0);
    cout << nums.top() << "\n";
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T{1};
    // cin >> T;

    while (T--) {
        work();
    }
}