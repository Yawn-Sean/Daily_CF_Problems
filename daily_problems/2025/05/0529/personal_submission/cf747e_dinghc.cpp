#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1'000'000;
char buff[N + 1], token_string[N + 1];
int curr_pos;
vector<vector<pair<int, int>>> g;

enum class token {
    id, num, comma, eof
};

token current;
int token_start, token_end;

int get_char() {
    return buff[curr_pos++];
}

void unget_char() {
    curr_pos--;
}

token get_next_token() {
    token_start = curr_pos;
    int token_string_pos = 0;
    int c = get_char();
    if (isdigit(c)) {
        do {
            token_string[token_string_pos++] = (char) c;
            c = get_char();
        } while (isdigit(c));
        current = token::num;
        unget_char();
    } else if (isalpha(c)) {
        do {
            token_string[token_string_pos++] = (char) c;
            c = get_char();
        } while (isalpha(c));
        current = token::id;
        unget_char();
    } else if (c == ',') {
        token_string[token_string_pos++] = (char) c;
        current = token::comma;
    } else {
        current = token::eof;
    }
    token_string[token_string_pos] = '\0';
    token_end = token_start + token_string_pos; 
    return current;
}

void match(token expected) {
    assert(current == expected);
    current = get_next_token();
}

void comment(int level = 0) {
    g[level].emplace_back(token_start, token_end);
    match(token::id);
    match(token::comma);
    char num_buff[10];
    sprintf(num_buff, "%.*s", token_end - token_start, buff + token_start);
    int num_of_comment = atoi(num_buff);
    match(token::num);
    for (int i = 0; i < num_of_comment; i++) {
        if (level + 1 == g.size()) g.emplace_back();
        match(token::comma);
        comment(level + 1);
    }
}

void comment_sequence(int level = 0) {
    if (level == g.size()) g.emplace_back();
    current = get_next_token();
    comment(level);
    while (current == token::comma) {
        match(token::comma);
        comment(level);
    }
}

int main() {
    scanf("%s", buff);
    comment_sequence();
    printf("%d\n", g.size());
    for (auto& cm : g) {
        for (auto& [start, end] : cm) {
            printf("%.*s ", end - start, buff + start);
        }
        printf("\n");
    }
    return 0;
}

