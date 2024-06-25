def main():
    n = II()
    nums = LII()
    cnt = [0] * (n + 1)
    max1, max2 = 0, 0
    for num in nums:
        if num > max1:
            cnt[num] -= 1
            max1, max2 = num, max1
        elif num > max2:
            cnt[max1] += 1
            max2 = num
    ans = 1
    for i in range(1, n + 1):
        if cnt[i] > cnt[ans]:
            ans = i
    print(ans)
    return
