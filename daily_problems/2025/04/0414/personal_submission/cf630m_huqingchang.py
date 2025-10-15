def main():
    x = II()
    diff = 360
    ans = 0
    for i in range(4):
        tmp = (x - 90 * i) % 360
        tmp_diff = fmin(tmp, 360 - tmp)
        if tmp_diff < diff:
            diff = tmp_diff
            ans = i
    return ans


T = 1
for ii in range(T):
    # print(ii)
    print(main())
