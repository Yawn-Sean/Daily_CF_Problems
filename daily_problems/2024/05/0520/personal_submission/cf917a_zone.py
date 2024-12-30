def main(ac=FastIO()):
    """
    url: 
        question:   https://codeforces.com/problemset/problem/917/A
        submission: https://codeforces.com/contest/917/submission/261732655
    time: 311 ms
    """
    s   = ac.read_str() 
    ans = 0 
    n   = len(s)
    for l in range(n):       
        if s[l] == ')': continue 
        lst, cnt = 1, 0
        for r in range(l + 1, n):
            lst += 1 if s[r] == '(' else -1
            cnt += s[r] == '?'
            if lst < 0:
                if cnt == 0: break 
                cnt -= 1
                lst += 2
            ans += lst == 0
    print(ans)
