'''
https://codeforces.com/contest/626/submission/273447284
(CF又抽了，一直显示"In Queue"，看了题解跟我的代码一样的，所以先提交了，后面有问题再改)
CF626D
20240730 Y1
probabilities
'''

from collections import Counter
from itertools import combinations, product

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    cn1 = Counter(x - y if x > y else y - x for x, y in combinations(a, 2))
    cn2 = [0] * 5000
    for (k1, v1), (k2, v2) in product(cn1.items(), cn1.items()):
        k = k1 + k2
        if k < 5000:
            cn2[k] += v1 * v2
    for i in range(2, 5000):
        cn2[i] += cn2[i - 1]
    sm = sum(cn2[k - 1] * v for k, v in cn1.items())
    bs = (n * (n - 1) >> 1) ** 3
    # print(cn1)
    # print(cn2[:10])
    # print(sm, bs)
    print(sm / bs)