def intersection(s1, s2):
    if not s1 or not s2:
        return list()
    if s2[0] > s1[1]:
        return list()
    return [max(s1[0], s2[0]), min(s1[1], s2[1])]

def main():
    n = int(input())
    segments = list()
    pre = [[0, 10 ** 9 + 1]]
    suf = [[0, 10 ** 9 + 1]]
    for i in range(n):
        s = list(map(int, input().split(" ")))
        segments.append(s[:])
        pre.append(intersection(pre[-1], s))
    pre.pop()
    for i in range(n - 1, -1, -1):
        suf.append(intersection(suf[-1], segments[i]))
    suf.pop()
    suf = suf[::-1]
    ret = 0
    for p, s in zip(pre, suf):
        k = intersection(p, s)
        if not k:
            continue
        ret = max(ret, k[1] - k[0])
    print(ret)


main()
