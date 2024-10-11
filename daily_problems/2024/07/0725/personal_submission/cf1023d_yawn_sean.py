# Submission Link: https://codeforces.com/contest/1023/submission/272463561
def main():
    n, q = MII()
    nums = LII()

    if 0 in nums:
        idx = nums.index(0)
        cur = 1
        for i in range(n):
            if nums[i] == 0:
                nums[i] = cur
            else:
                cur = nums[i]
        if q not in nums:
            nums[idx] = q

    else:
        if q not in nums:
            print('NO')
            exit()

    pos = [[] for _ in range(q + 1)]
    for i in range(n):
        pos[nums[i]].append(i)

    fen = FenwickTree(n)

    for i in range(1, q + 1):
        if len(pos[i]):
            if fen.rsum(pos[i][0], pos[i][-1]):
                print('NO')
                exit()
            for p in pos[i]:
                fen.add(p, 1)

    print('YES')
    print(' '.join(map(str, nums)))