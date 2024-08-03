from collections import defaultdict
import math


def main():
    n, b = map(int, input().split())

    dict1 = defaultdict(int)
    dict2 = defaultdict(int)

    # 计算b的质因数分解
    for i in range(2, int(math.sqrt(b)) + 1):
        while b % i == 0:
            dict1[i] += 1
            b //= i
    if b > 1:
        dict1[b] += 1

    # 计算n的阶乘分解后每个质因数的次数
    for k, v in dict1.items():
        x = k
        tmp = n
        while tmp >= x:
            dict2[x] += tmp // x
            tmp //= x

    # 如果不存在质因数分解结果，则输出0
    if not dict1 or not dict2:
        print(0)
        return

    # 寻找满足条件的最小阶乘结果
    ans = math.inf
    for k, v in dict1.items():
        ans = min(ans, dict2[k] // v)
    print(ans)


if __name__ == '__main__':
    main()
