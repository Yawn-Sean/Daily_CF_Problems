#include <bits/stdc++.h>
using namespace std;

enum ELM_TYPE {
    ELM_TYPE_IN,
    ELM_TYPE_AND,
    ELM_TYPE_OR,
    ELM_TYPE_XOR,
    ELM_TYPE_NOT,
};

struct ELM {
    ELM_TYPE type;
    int l;
    int r;
    bool cur_val;
    bool imp;
};
void work() {
    int n; cin >> n;

    vector<ELM> elms(n + 1);
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        int v1; cin >> v1;
        
        elms[i].l = v1;

        if (s == "IN") {
            elms[i].type = ELM_TYPE_IN;
        } else if (s == "AND") {
            elms[i].type = ELM_TYPE_AND;
            int v2; cin >> v2; elms[i].r = v2;
        } else if (s == "OR") {
            elms[i].type = ELM_TYPE_OR;
            int v2; cin >> v2; elms[i].r = v2;
        } else if (s == "XOR") {
            elms[i].type = ELM_TYPE_XOR;
            int v2; cin >> v2; elms[i].r = v2;
        } else if (s == "NOT") {
            elms[i].type = ELM_TYPE_NOT;
        }
    }

    function<bool(int)> df_mark;
    df_mark = [&](int idx) -> bool {
        if (elms[idx].type == ELM_TYPE_IN) {
            elms[idx].cur_val = elms[idx].l;
        } else if (elms[idx].type == ELM_TYPE_AND) {
            elms[idx].cur_val = (df_mark(elms[idx].l) & df_mark(elms[idx].r));
        } else if (elms[idx].type == ELM_TYPE_OR) {
            elms[idx].cur_val = (df_mark(elms[idx].l) | df_mark(elms[idx].r));
        } else if (elms[idx].type == ELM_TYPE_XOR) {
            elms[idx].cur_val = (df_mark(elms[idx].l) ^ df_mark(elms[idx].r));
        } else if (elms[idx].type == ELM_TYPE_NOT) {
            elms[idx].cur_val = !df_mark(elms[idx].l);
        }
        return elms[idx].cur_val;
    };
    df_mark(1);

    function<void(int)> df_impo;
    df_impo = [&](int idx) -> void {
        elms[idx].imp = true;

        if (elms[idx].type == ELM_TYPE_IN) {
            ;
        } else if (elms[idx].type == ELM_TYPE_AND) {
            if (elms[idx].cur_val) {
                df_impo(elms[idx].l);
                df_impo(elms[idx].r);
            } else {
                if (elms[elms[idx].l].cur_val) df_impo(elms[idx].r);
                if (elms[elms[idx].r].cur_val) df_impo(elms[idx].l);
            }
        } else if (elms[idx].type == ELM_TYPE_OR) {
            if (!elms[idx].cur_val) {
                df_impo(elms[idx].l);
                df_impo(elms[idx].r);
            } else if (elms[elms[idx].l].cur_val && elms[elms[idx].r].cur_val) {
                ;
            } else {
                if (elms[elms[idx].l].cur_val) df_impo(elms[idx].l);
                if (elms[elms[idx].r].cur_val) df_impo(elms[idx].r);
            }
        } else if (elms[idx].type == ELM_TYPE_XOR) {
            df_impo(elms[idx].l);
            df_impo(elms[idx].r);
        } else if (elms[idx].type == ELM_TYPE_NOT) {
            df_impo(elms[idx].l);
        }
    };
    df_impo(1);

    for (int i = 1; i <= n; i++) {
        if (elms[i].type == ELM_TYPE_IN) {
            cout << (elms[i].imp ^ elms[1].cur_val);
        }
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}