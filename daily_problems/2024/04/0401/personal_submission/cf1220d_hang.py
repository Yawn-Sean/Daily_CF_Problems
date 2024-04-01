# https://codeforces.com/contest/1220/submission/254367581
# 理解二分图的性质
# 必须是偶数环！
from collections import *

def main():
    n = int(input())
    b = list(map(int, input().split()))
    cnt = Counter()
    for x in b:
        cnt[x & -x] += 1
    d = cnt.most_common()[0][0]
    ans = [x for x in b if x & -x != d]
    print(len(ans))
    print(*ans)
main()