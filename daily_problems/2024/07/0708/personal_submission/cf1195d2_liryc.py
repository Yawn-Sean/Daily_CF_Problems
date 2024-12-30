'''
https://codeforces.com/contest/1195/submission/269408089
1195D2
2024/7/8 Y1
1800
计算每个数字的贡献度：每一位数字在第几位上乘了多少次可以计算出来
'''

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]):
    sm = 0
    b = [0] * 11
    for x in a:
        b[len(str(x))] += 1
    for y in a:
        x = y
        i = 0
        while x > 0:
            i += 1
            d = x % 10
            x //= 10
            for j in range(1, 11):
                p = i + j if j < i else i * 2 - 1
                sm = (sm + d * b[j] * 10**(p - 1)) % 998244353
                p = i + j if j < i else i * 2
                sm = (sm + d * b[j] * 10**(p - 1)) % 998244353
    return sm

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)