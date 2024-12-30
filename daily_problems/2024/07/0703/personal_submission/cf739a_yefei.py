import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())

tcn = 1
for _tcn_ in range(tcn):
    n, m = MI()
    segments = [LI() for _ in range(m)]
    mi = n
    for start, end in segments:
        mi = min(mi, end - start + 1)
    nums = list(range(mi))
    rets = nums * ((n + mi - 1) // mi)
    print(mi)
    print(*rets[:n])
