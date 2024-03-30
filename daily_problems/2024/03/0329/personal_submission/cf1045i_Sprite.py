import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()

ans = 0
dic = {}
for _ in range(int(input())):
    now = Counter(input())
    ins = 0
    for i in now:
        if now[i] & 1:
            ins += 1 << ord(i) - ord('a')
    if ins in dic:
        ans += dic[ins]
    else:
        dic[ins] = 0
    dic[ins] += 1

    for i in range(26):
        f = ins ^ 1 << i
        if f in dic:
            ans += dic[f]
print(ans)
