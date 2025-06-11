# Submission link: https://codeforces.com/contest/730/submission/304334332
def main():
    n = II()
    nums = LII()

    ops = []

    def op(idxs):
        for i in idxs:
            nums[i] = fmax(0, nums[i] - 1)
        res = ['0'] * n
        for i in idxs:
            res[i] = '1'
        ops.append(''.join(res))

    while min(nums) != max(nums):
        v = max(nums)
        idxs = [i for i in range(n) if nums[i] == v]
        c = len(idxs)
        
        if c > 1:
            if c % 2 == 0:
                for i in range(0, c, 2):
                    op([idxs[i], idxs[i + 1]])
            else:
                op(idxs[:3])
                for i in range(3, c, 2):
                    op([idxs[i], idxs[i + 1]])
        else:
            idx = -1
            for i in range(n):
                if nums[i] != v and (idx == -1 or nums[i] > nums[idx]):
                    idx = i
            op([idx, idxs[0]])

    print(nums[0])
    print(len(ops))
    print('\n'.join(ops))
