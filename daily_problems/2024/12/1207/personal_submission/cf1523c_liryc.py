'''
https://codeforces.com/problemset/submission/1523/295399635
1523C
2024/12/7 Y1
1600
stack
'''
# ref
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = [0] * n
    for i in range(n):
        a[i] = int(input())
    return n, a

def solve(n: int, a: list[int]):
    ans = []
    stk = []
    for x in a:
        if x == 1:
            stk.append(1)
        else:
            while stk[-1] != x - 1:
                stk.pop()
            stk[-1] = x
        ans.append('.'.join(map(str, stk)))
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(*ans, sep='\n')
