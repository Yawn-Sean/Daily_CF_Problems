# Submission link: https://codeforces.com/contest/721/submission/259935537
def main():
    n, k, x = MII()
    nums = LII()

    neg = False
    for num in nums:
        if num < 0:
            neg = not neg

    if not neg:
        idx = 0
        for i in range(n):
            if abs(nums[i]) < abs(nums[idx]):
                idx = i
        
        ops = (abs(nums[idx]) - 1) // x + 1
        
        if k >= ops:
            if nums[idx] < 0: neg = not neg
            k -= ops
            nums[idx] += ops * x if nums[idx] < 0 else -ops * x
        else:
            nums[idx] += k * x if nums[idx] < 0 else -k * x
            print(' '.join(map(str, nums)))
            exit()

    # 相当于把 (abs(nums[i]), i) 作为一个数对放入堆中
    hpq = [abs(nums[i]) * n + i for i in range(n)]
    heapify(hpq)

    for _ in range(k):
        i = heappop(hpq) % n
        if nums[i] == 0 and not neg:
            nums[i] = -x
            neg = True
        else:
            nums[i] += x if nums[i] >= 0 else -x
        heappush(hpq, abs(nums[i]) * n + i)

    print(' '.join(map(str, nums)))