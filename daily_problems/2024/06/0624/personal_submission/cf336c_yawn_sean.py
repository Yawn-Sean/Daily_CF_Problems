# Submission Link: https://codeforces.com/contest/336/submission/267110553
def main():
    n = II()
    nums = LII()

    for i in range(29, -1, -1):
        tmp = []
        msk = -1
        for num in nums:
            if num >> i & 1:
                tmp.append(num)
                msk &= num
        if msk & -msk == 1 << i:
            print(len(tmp))
            print(' '.join(map(str, tmp)))
            break
