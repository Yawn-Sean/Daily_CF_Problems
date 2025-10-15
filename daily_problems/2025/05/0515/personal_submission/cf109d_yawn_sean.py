# Submission link: https://codeforces.com/contest/109/submission/319705601
def main():
    def check(x):
        while x:
            if x % 10 != 4 and x % 10 != 7:
                return False
            x //= 10
        return True

    n = II()
    nums = LII()

    flg = True
    for i in range(1, n):
        if nums[i] < nums[i - 1]:
            flg = False

    if flg: print(0)
    else:
        idx = -1
        for i in range(n):
            if check(nums[i]):
                idx = i
        
        if idx == -1: print(-1)
        else:
            st_range = sorted(range(n), key=lambda x: nums[x])
            
            cur = list(range(n))
            pos = list(range(n))
            ops = []
            
            def swap(i, j):
                if i == j: return
                i = pos[i]
                j = pos[j]
                ops.append(f'{i + 1} {j + 1}')
                pos[cur[i]], pos[cur[j]] = pos[cur[j]], pos[cur[i]]
                cur[i], cur[j] = cur[j], cur[i]
            
            for i in range(n):
                swap(cur[i], idx)
                swap(st_range[i], idx)

            print(len(ops))
            if ops:
                print('\n'.join(ops))