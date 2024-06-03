# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
MI = lambda: map(int, input().split())


def get_bit(num, i):
    return (num & (1 << i)) != 0


tcn = 1
for _tcn_ in range(tcn):
    n, x = MI()
    base = 1 << 18
    if n == 1:
        print('YES')
        print(x)
        continue
    elif n == 2:
        if x == 0:
            print('NO')
        else:
            print('YES')
            print(x, 0)
        continue

    nums = [i + 1 for i in range(n - 2)]
    xor = 0
    for num in nums:
        xor ^= num

    x1, x2 = base, base
    for b in range(18):
        if get_bit(xor, b) == get_bit(x, b):
            continue
        else:
            x2 |= (1 << b)

    nums.append(x1)
    nums.append(x2)
    if x1 == x2:
        nums[-3] |= (1 << 18)
        nums[-2] = 0
    ret = 0
    # for num in nums:
    #     ret ^= num
    # print(ret, x)
    print('YES')
    print(*nums)
