# Submission Link: https://codeforces.com/contest/1585/submission/269328765
def main():
    n = II()
    nums = LGMI()
    cnt = [0] * n
    
    for num in nums:
        if cnt[num]:
            return True
        cnt[num] += 1
    
    fen = FenwickTree(n)
    cnt = 0
    for i in range(n - 1, -1, -1):
        cnt ^= fen.sum(nums[i] - 1) & 1
        fen.add(nums[i], 1)
    return cnt == 0