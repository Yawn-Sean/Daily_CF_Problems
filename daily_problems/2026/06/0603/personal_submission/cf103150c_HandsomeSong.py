import sys
input = sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
n=II()
for _ in range(n):
    s=I()
    if s.index('c')>s.index('e') and s.index('c')>s.index('p') and s.index('c')>s.index('z') and s.index('p')>s.index('z'):
        print('YES')
    else:
        print('NO')