def solve():
    import sys

    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0] * (1001)
    #     print(666666)
    for i in a:
        # print(i)
        cnt[i] += 1
    num1, num2, num4 = 0, 0, 0
    if n % 2 == 0:
        num4 = n * n // 4
    else:
        num1 = 1
        num2 = n - 1
        num4 = (n * n - 2 * n + 1) // 4
    # print(num1, num2, num4)
    gap = [[0] * (n + 1) for _ in range(n + 1)]

    num2l, num2r = 1, n
    flag = 0
    num4l, num4r = 1, n
    flag4 = 0
    # print(num1, num2, num4)
    for i in range(1, 1001, 1):
        while cnt[i] > 0:
            if cnt[i] >= 4 and num4 > 0:

                num4 -= 1
                cnt[i] -= 4
                gap[1 + flag4][num4l] = gap[1 + flag4][num4r] = gap[n - flag4][
                    num4r
                ] = gap[n - flag4][num4l] = i
                # print(cnt[i], i, num4l, num4r)
                num4l += 1
                num4r -= 1
                # print(cnt[i], i, num4l, num4r)
                if num4l >= num4r:
                    num4l, num4r = 1, n
                    flag4 += 1
            elif cnt[i] >= 2 and num2 > 0:
                num2 -= 1
                cnt[i] -= 2
                if flag == 0:
                    gap[num2l][(n + 1) // 2] = gap[num2r][(n + 1) // 2] = i
                else:
                    gap[(n + 1) // 2][num2l] = gap[(n + 1) // 2][num2r] = i
                num2l += 1
                num2r -= 1
                if num2l == num2r:
                    num2l, num2r = 1, n
                    flag = 1
            elif cnt[i] > 0 and num1 > 0:
                num1 -= 1
                cnt[i] -= 1
                gap[(n + 1) // 2][(n + 1) // 2] = i
            else:
                break
        # if i == 1 or i == 3:
        #     print(cnt[i])
    if num1 > 0 or num2 > 0 or num4 > 0:
        print("NO")
    else:
        print("YES")
        for i in range(1, n + 1, 1):
            for j in range(1, n + 1, 1):
                print(gap[i][j], end=" ")
            print()


if __name__ == "__main__":
    solve()
