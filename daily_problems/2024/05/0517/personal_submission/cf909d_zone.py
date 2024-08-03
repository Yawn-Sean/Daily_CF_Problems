def main(ac=FastIO()):
    """
    url: 
        question:   https://codeforces.com/problemset/problem/909/D
        submission: https://codeforces.com/contest/909/submission/261316188
    time: 1015 ms
    """
    s = ac.read_str() 
    n = len(s)
    segs = []
    i = 0
    while i < n: 
        j = i 
        while j < n and s[j] == s[i]: j += 1
        segs.append([j - i, s[i]])
        i = j 
    ans = 0
    while len(segs) > 1:
        segs_t = []
        ans += 1 
        for i, [d, v] in enumerate(segs):
            if i == 0 or i == len(segs) - 1: 
                d -= 1 
            else: 
                d -= 2 
            if d <= 0: continue 
            if len(segs_t) == 0 or v != segs_t[-1][-1]: 
                segs_t.append([d, v])
            else: 
                segs_t[-1][0] += d
        segs = segs_t
    print(ans)
