def main():
    n, u = map(int, input().split())
    nums = list(map(int, input().split()))

    left, right = 0, 0
    ans = -1

    while left < n:
        while right < n and nums[right] - nums[left] <= u:
            right += 1

        if right - left >= 3:
            ans = max(
                ans, (nums[right - 1] - nums[left + 1]) / (nums[right - 1] - nums[left])
            )

        left += 1

    print(ans)
    return
