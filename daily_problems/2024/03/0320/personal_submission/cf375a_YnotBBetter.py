import sys
input = lambda: sys.stdin.readline().strip()

# 对于一个数 x = a + b，只要满足 a % 7 + b % 7 == 7，就可以保证 x % 7 == 0
# 题目保证必定包含1689四个数字，我们将这四个数放在最低4位，则形如 xxxx1689 的数可以拆分为 xxxx0000 + 1689
# 交换1689四个数字可以得到哪些余数是可以预处理得到的，只要算出xxxx0000的余数，就可以得到1689的摆放方法

def main():
    x = [int(c) for c in input()]
    n = len(x)
    res_val = ["1869", "6189", "1689", "6198", "1698", "1986", "1896"]

    seen = [-1] * 10
    for i, d in enumerate(x):
        seen[d] = i

    for i, j in enumerate(sorted(map(lambda v: seen[v], [1, 6, 8, 9]), reverse=True)):
        x[n-i-1], x[j] = x[j], x[n-i-1]

    if x[0] == 0:
        i = 1
        while i < n - 4 and x[i] == 0:
            i += 1
        if i == n - 4:
            print(res_val[0] + "0" * (n - 4))
            return
        x[0], x[i] = x[i], x[0]

    res = 0
    for i in range(n-4):
        res = (res * 10 + x[i]) % 7
    res = res * 10000 % 7
    print("".join(map(str, x[:-4])) + res_val[(7 - res) % 7])


main()
