# https://codeforces.com/problemset/problem/1238/C
# https://codeforces.com/contest/1238/submission/309577289
def main():
    q = II()
    while q > 0:
        q -= 1
        h, n = MII()
        nums = LII()

        nums.append(0)

        f = [n] * (n + 1)
        f[-1] = f[-2] = 0
        for i in range(n - 2, -1, -1):
            # 用，只去掉 nums[i]，一定可以无伤掉到 nums[i + 1]
            res = f[i + 1] + 1
            # 不用，需要保证从 nums[i] = x + 1（或者更大，但是可以变到x + 1)
            # 到 nums[i + 1] = x 到 nums[i + 2] = y? 不会摔死
            # 即 y == x - 1，这样 同时移除 nums[i] 和 nums[i+1]
            # 从 nums[i] 掉到 nums[i + 2] 才可以无伤
            if nums[i + 2] == nums[i + 1] - 1:
                res = min(res, f[i + 2])

            f[i] = res

        print(f[0])

        # 记忆化搜索做法
        # @cache
        # def dfs(i):
        #     if i >= n - 1:
        #         return 0
            
        #     res = inf
        #     # 用，只去掉nums[i]，一定可以无伤掉到 nums[i + 1]
        #     res = min(res, dfs(i + 1) + 1)
        #     # 不用，需要保证从 nums[i] = x + 1（或者更大，但是可以变到x + 1)
        #     # 到 nums[i + 1] = x 到 nums[i + 2] = y? 不会摔死
        #     # 即 y == x - 1，这样 同时移除 nums[i] 和 nums[i+1]
        #     # 从 nums[i] 掉到 nums[i + 2] 才可以无伤
        #     if nums[i + 2] == nums[i + 1] - 1:
        #         res = min(res, dfs(i + 2))
        #     return res

        # print(dfs(0))

if __name__ == "__main__":
    main()