import sys
input=sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
t=II()
for _ in range(t):
    n=II()
    a=0
    b=0
    for _ in range(n):
        s=I()
        if 'xxx' in s:
            b^=1
        elif 'xx' in s:
            a^=1
    print('Monocarp' if a or b else 'Polycarp')