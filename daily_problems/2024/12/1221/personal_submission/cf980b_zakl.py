import sys
r = sys.stdin.readline
def _n():
    return int(input())
def _nA():
    return list(map(int, input().split()))
def _nS():
    return input().split()
def solve():
    n,m=_nA()
    print('YES')
    print('.'*n)
    if m%2:
        a=min(m,n-2)
        b=m-a
        print('.'*((n-a)//2)+'#'*a+'.'*((n-a)//2))
        print('.'+'#'*(b//2)+'.'*(n-2-b)+'#'*(b//2)+'.')
    else:    
        a=m//2
        b=a
        print(('.'+'#'*a+'.'*(n-1-a)))
        print(('.'+'#'*b+'.'*(n-1-b)))
    print('.'*n)
solve()

