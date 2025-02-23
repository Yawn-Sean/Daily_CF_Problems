import sys
r = sys.stdin.readline
def _n():
    return int(input())
def _nA():
    return list(map(int, input().split()))
def _nS():
    return input().split()
def solve():
    n,m,k=_nA()
    a=_nA()
    b=_nA()
    a.sort(reverse=True)
    b.sort(reverse=True)
    if n>m or a[0]>b[0]:
        print('YES')
        return 
    for i in range(len(a)):
        if a[i]>b[i]:
            print('YES')
            return
    print("NO")
solve()

