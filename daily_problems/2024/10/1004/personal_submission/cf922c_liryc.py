'''
https://codeforces.com/contest/922/submission/284252997
922C
2024/10/4 Y1
1600
math
'''

def solve(n: int, k: int) -> str:
    for i in range(1, k + 1):
        if n % i != i - 1:
            return "No"
    return 'Yes'

if __name__ == '__main__':
    n, k = map(int, input().split())
    print(solve(n, k))

