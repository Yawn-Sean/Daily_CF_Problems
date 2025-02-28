'''
https://codeforces.com/problemset/submission/174/293345537
174C
2024/11/26 Y1
1800
stack, range algorithms
'''
# 差分数组+栈
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]) -> int:
    a.append(0)
    stk = []
    ans = []
    cur = 0
    for i, x in enumerate(a):
        while x > cur:
            cur += 1
            stk.append(i)
        while x < cur:
            ans.append(f"{stk[-1] + 1} {i}")
            stk.pop()
            cur -= 1
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(len(ans))
    print(*ans, sep = '\n')
