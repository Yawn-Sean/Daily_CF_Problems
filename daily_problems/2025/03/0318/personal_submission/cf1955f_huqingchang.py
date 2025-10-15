def main():
    res = [0] + LII()
    ans = 0
    for i in range(1, 5):
        tmp = res[i] // 2
        ans += tmp
        res[i] -= tmp * 2
    return ans + min(res[1: 4])


T = II()
for ii in range(T):
    print(main())
