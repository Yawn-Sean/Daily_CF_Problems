
from collections import defaultdict
def main():
    k,n = map(int, input().split())
    d = defaultdict(list)
    for _ in range(k):
        s,a = input().split()
        a = int(a)
        d[s].append(a)
    for v in d:
        d[v].sort()
    ans = 0
    md = 0
    for s in d:
        rev_s = s[::-1]
        if rev_s == s:
            while len(d[s]) > 1 and d[s][-1] + d[s][-2] > 0:
                md = max(md, -d[s][-2])# 减去
                ans += d[s].pop() + d[s].pop()
            if len(d[s]):
                md = max(md, d[s][-1]) # 加上
        elif rev_s in d:
            while len(d[s]) and len(d[rev_s]) and d[s][-1] + d[rev_s][-1] > 0:
                ans += d[s].pop() + d[rev_s].pop()
    print(ans + md)

main()