#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    s = '(' + s + ')';
    std::stack<char> st;
    std::stack<int> order;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            st.push(s[i++]);
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i-1] == '(') {
            st.pop();
            order.emplace(0);
        } else {
            while (st.top() != '(') {
                int a = order.top(); order.pop();
                int b = order.top(); order.pop();
                order.emplace(std::max(b + 1, a));
                st.pop();
            }
            st.pop();
        }
    }

    std::cout << order.top() << '\n';
    return 0;
}
