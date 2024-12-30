# Submission link 1: https://codeforces.com/contest/1129/submission/259815494
# Submission link 2: https://codeforces.com/contest/1129/submission/259816027
def main():
    n, m = MII()
    to_move = [n] * n
    cnt = [0] * n

    for _ in range(m):
        a, b = GMI()
        to_move[a] = min(to_move[a], (b - a) % n)
        cnt[a] += 1

    # 简单做法，O(n^2 + m)
    ans = [0] * n
    for i in range(n):
        for step in range(n):
            j = (i + step) % n
            if cnt[j]:
                ans[i] = max(ans[i], step + (cnt[j] - 1) * n + to_move[j])

    print(' '.join(map(str, ans)))
    
    # 效率更优的做法 O(n + m)
    nums = [0] * (2 * n)
    for i in range(n):
        if cnt[i]:
            nums[i] = i + (cnt[i] - 1) * n + to_move[i]

    for i in range(n, 2 * n):
        if nums[i-n]:
            nums[i] = nums[i-n] + n

    queue = [0] * (2 * n)
    l = r = 0
    for i in range(n):
        while r > l and nums[queue[r - 1]] <= nums[i]:
            r -= 1
        queue[r] = i
        r += 1

    ans = [0] * n

    for i in range(n):
        ans[i] = nums[queue[l]] - i
        
        if queue[l] == i: l += 1
        
        while r > l and nums[queue[r - 1]] <= nums[i + n]:
            r -= 1
        queue[r] = i + n
        r += 1

    print(' '.join(map(str, ans)))