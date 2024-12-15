'''
https://codeforces.com/problemset/submission/848/296449545
848 A
2024/12/14 Y1
1600
constructive
'''
# ref
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    k = int(input())
    return k

def solve(k: int):
    ans = []
    for i in range(1000, 1, -1):
        while i * (i - 1) >> 1 <= k:
            k -= i * (i - 1) >> 1
            ans.append(i)
    return ''.join(chr(ord('a') + i) * ans[i] for i in range(len(ans))) if ans else 'a'

if __name__ == '__main__':
    k = init()
    ans = solve(k)
    print(ans)
