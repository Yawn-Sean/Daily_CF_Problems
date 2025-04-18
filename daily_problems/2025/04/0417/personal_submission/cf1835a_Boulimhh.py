"""
只会暴力写两重循环，学下一次遍历的写法

有些特例应该可以直接判断输出-1
"""
for _ in range(int(input())):
    a, b, c, k = map(int, input().split())
    if c < a or c < b or c - max(a, b) >= 2:
        print(-1)
        continue
    left, right = 10 ** (c - 1), 10 ** c
    flag = False
    for i in range(10 ** (a - 1), 10 ** a):
        l, r = max(10 ** (b - 1), left - i), min(10 ** b - 1, right - i - 1)
        if r >= l:
            cnt = r - l + 1
            if cnt >= k:
                j = l + k - 1
                print(f"{i} + {j} = {i + j}")
                flag = True
                break
            else:
                k -= cnt
    if not flag: print(-1)
