# Submission link: https://codeforces.com/contest/1889/submission/324959496
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, c = MII()
        nums = LII()
        
        st_range = sorted(range(1, n), key=lambda x: x * c - nums[x])
        
        cur = nums[0]
        flg = True
        
        for i in st_range:
            if cur + nums[i] >= c * (i + 1): cur += nums[i]
            else: flg = False
        
        outs.append('Yes' if flg else 'No')

    print('\n'.join(outs))