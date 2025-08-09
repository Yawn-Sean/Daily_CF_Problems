from typing import List


def main(nums: List[int], k: int) -> None:
    nums.sort(reverse=True)

    ans = []

    def dfs(i: int, c: int, cur: List[int]) -> None:
        if len(cur) == c:
            ans.append(cur[:])
            return
        if i >= len(nums):
            return

        dfs(i + 1, c, cur + [nums[i]])
        dfs(i + 1, c, cur)

    for c in range(1, len(nums) + 1):
        dfs(c - 1, c, nums[:c - 1])
        if len(ans) >= k:
            break
    for i in range(k):
        print(f"{len(ans[i])} {' '.join(map(str, ans[i]))}")


if __name__ == "__main__":
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    main(nums, k)