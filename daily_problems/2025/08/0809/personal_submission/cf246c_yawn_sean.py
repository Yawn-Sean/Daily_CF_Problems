# Submission link: https://codeforces.com/contest/246/submission/333020991
def main():
    n, k = MII()
    nums = LII()
    
    nums.sort(reverse=True)
    outs = []
    
    for i in range(n):
        for j in range(i, n):
            cur = []
            
            for idx in range(i):
                cur.append(nums[idx])
            cur.append(nums[j])
            
            outs.append(f'{len(cur)} {" ".join(map(str, cur))}')
    
    print('\n'.join(outs[:k]))