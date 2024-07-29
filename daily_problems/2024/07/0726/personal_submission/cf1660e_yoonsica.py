import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())

for _ in range(RI()):
    RS()
    n = RI()
    cnt = [0] * n
    for i in range(n):
        s = RS()
        for j in range(n):
            if s[j] == '1':
                cnt[(i - j) % n] += 1
    print(sum(cnt) + n - max(cnt) * 2)