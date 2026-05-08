import sys
input = sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
t=II()
for _ in range(t):
    n=II()
    s=set(I())
    if min(s)==max(s)or n==3 and len(s)==3:
        print('no')
    else:
        print('yes')