from collections import Counter
from itertools import pairwise

t = int(input())

results = []

for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))

    cnt = Counter(A)

    candidates = [] # 出現至少兩次的長度
    flag = False # 是否有長度出現至少四次
    for k, v in cnt.items():
        if v >= 4:
            print(f"{k} {k} {k} {k}")
            flag = True
            break
        if v >= 2:
            candidates.append(k)
    if flag:
        continue

    assert len(candidates) >= 2
    candidates.sort()

    ans_x, ans_y = 1, 0
    for y, x in pairwise(candidates):
        # if x / y < ans_x / ans_y:
        if x * ans_y < y * ans_x:
            ans_x, ans_y = x, y

    print(f"{ans_x} {ans_x} {ans_y} {ans_y}")
