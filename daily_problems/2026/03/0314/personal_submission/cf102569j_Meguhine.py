# -*- coding: UTF-8 -*-


# print("3\n1 5 5\n3\n3 3 4")


from itertools import product
from sys import exit

if __name__ == "__main__":
    for s in product(range(1, 11), repeat=3):
        sum_s = sum(s)
        for t in product(range(1, 11), repeat=3):
            sum_t = sum(t)
            if sum_s <= sum_t:
                continue
            res_1 = 0
            for x in s:
                for y in t:
                    if x > y:
                        res_1 += 1
                    elif x < y:
                        res_1 -= 1
            if res_1 <= 0:
                continue
            res_2 = 0
            for x in s:
                sx = sum_s - x
                for y in t:
                    ty = sum_t - y
                    if sx > ty:
                        res_2 += 1
                    elif sx < ty:
                        res_2 -= 1
            if res_2 >= 0:
                continue
            print(f"3\n{' '.join(map(str, s))}\n3\n{' '.join(map(str, t))}")
            exit(0)
