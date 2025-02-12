# Submission link: https://codeforces.com/contest/748/submission/303724247
def main():
    n, k = MII()
    d = defaultdict(list)

    for _ in range(n):
        s, v = LI()
        v = int(v)
        d[s].append(v)

    for s in d:
        d[s].sort()

    ans = 0
    mid = 0

    for s in d:
        rev_s = s[::-1]
        
        if s == rev_s:
            while len(d[s]) > 1 and d[s][-1] + d[s][-2] > 0:
                mid = fmax(mid, -d[s][-2])
                ans += d[s].pop() + d[s].pop()
            
            if len(d[s]): mid = fmax(mid, d[s][-1])
        elif rev_s in d:
            while d[s] and d[rev_s] and d[s][-1] + d[rev_s][-1] > 0:
                ans += d[s].pop() + d[rev_s].pop()

    print(ans + mid)