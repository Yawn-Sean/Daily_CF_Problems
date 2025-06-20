def func(x):
    nearest_sqrt = round(x ** 0.5)
    return abs(nearest_sqrt ** 2 - x)

def solve():
    n = II()
    cnt = LMII()
    cur = []
    for num in cnt:
        dis = func(num)
        cur.append([dis, num])
    cur.sort()
    half = n // 2
    sum1 = sum(item[0] for item in cur[:half])
    sum2 = sum((item[0] == 0) + (item[1] == 0) for item in cur[half:])

    print(sum1 + sum2)
