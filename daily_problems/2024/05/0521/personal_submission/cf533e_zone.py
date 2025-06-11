def main(ac=FastIO()):
    """
    url: 
        question:   https://codeforces.com/problemset/problem/533/E
        submission: https://codeforces.com/contest/533/submission/261956643
    time: 171 ms
    """
    n = ac.read_int()
    s, t = ac.read_str(), ac.read_str()
    l, r = -1, -1
    for i in range(n):
        if s[i] != t[i]:
            if l == -1: l = i 
            r = i  
    print((s[l: r] == t[l + 1: r + 1]) + (s[l + 1: r + 1] == t[l: r]))
