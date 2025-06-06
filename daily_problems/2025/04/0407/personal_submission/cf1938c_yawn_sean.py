# Submission link: https://codeforces.com/contest/1938/submission/314309755
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = LII()
        
        start = (1 << nums[0]) - 1
        
        for i in range(1, n):
            cnt = nums[i - 1] - nums[i] + 1
            if cnt >= 0:
                start = fmax(start, (1 << nums[i - 1] + 1) - (1 << cnt) - i)
        
        flg = True
        for i in range(n):
            if (start + i).bit_count() != nums[i]:
                flg = False
        
        if flg: outs.append(start)
        else: outs.append(-1)

    print('\n'.join(map(str, outs)))