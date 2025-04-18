def main():
    n = II()
    s = I()
    arr = []
    for a, b in groupby(s):
        arr.append(len(list(b)))
    ans = len(arr)
    mx = max(arr)
    if mx >= 3:
        return ans + 2
    two = arr.count(2)
    return ans + fmin(two, 2)


T = 1
for ii in range(T):
    # print(ii)
    print(main())
