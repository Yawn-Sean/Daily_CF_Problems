#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    std::cin >> input; 
    auto len = size(input);

    stack<char> operators;
    stack<int> operands;
    for (auto i = 0; i < len; ++i) {
        if (input[i] == '(') {
            if (i + 1 < len && input[i + 1] == ')') {
                operands.push(0);
                i++;
            } else {
                operators.push('(');
            }
        } else if (input[i] == '-') {
            operators.push('-');
            i++;
        } else if (input[i] == ')') {
            while (!empty(operators) && operators.top() == '-') {
                auto second = operands.top();
                operands.pop();
                auto first = operands.top();
                operands.pop();
                operands.push(max(first + 1, second));

                operators.pop();
            }
            operators.pop();
        }
    }

    while (!empty(operators)) {
        auto second = operands.top();
        operands.pop();
        auto first = operands.top();
        operands.pop();
        operands.push(max(first + 1, second));
        operators.pop();
    }

    cout << operands.top() << endl;

    return 0;
}
