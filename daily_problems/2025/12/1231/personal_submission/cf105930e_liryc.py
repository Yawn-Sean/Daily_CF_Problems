'''
https://codeforces.com/gym/105930/submission/355946708
'''
# def all_factors(n: int): ## 从大到小枚举n的所有因子
pc = [0] * 1000001
def solve(n: int, k: int, a: list[int]) -> int:
    global pc
    a.sort()
    i = 0
    for x in a:
        while i < x:
            pc[i + 1] = pc[i]
            i += 1
        pc[i] += 1
    sum_a = sum(a)
    sum_all =  sum_a + k
    max_a = a[-1]
    for f in all_factors(sum_all):
        if f == 1:
            return 1
        if f >= max_a:
            c = f * n - sum_a
            if c <= k:
                return f
        else:
            sm = 0
            for l in range(0, max_a, f):
                t = r = l + f
                if r > max_a:
                    r = max_a
                sm += t * (pc[r] - pc[l])
                if sm > sum_all:
                    break
            else:
                return f
