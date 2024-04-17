#include <bits/stdc++.h>

using namespace std;
char text[10000];
int offset;

enum class token {
    open_paren, close_paren, arrow, eof
};

token next_token(int d = 0) {
    if (text[offset + d] == '(') {
        return token::open_paren;
    } else if (text[offset + d] == ')') {
        return token::close_paren;
    } else if (text[offset + d] == '-' && text[offset + d + 1] == '>') {
        return token::arrow;
    }
    return token::eof;
}

void consume_token(token tok) {
    if (tok == token::open_paren || tok == token::close_paren) {
        offset += 1;
    } else if (tok == token::arrow) {
        offset += 2;
    }
}

int expr();

int term() {
    int res = 0;
    consume_token(token::open_paren);
    token curr = next_token();
    if (curr == token::open_paren) {
        res = expr();
    }
    consume_token(token::close_paren);
    return res;
}

int expr() {
    int res = 0;
    token curr = next_token();
    if (curr == token::open_paren) {
        res = term();
        token nxt = next_token();
        if (nxt == token::arrow) {
            consume_token(token::arrow);
            int res2 = expr();
            res = max(res + 1, res2);
        }
    }
    return res;
}

int main() {
    scanf("%s", text);
    printf("%d\n", expr());
    return 0;
}

