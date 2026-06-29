# Submission link: https://codeforces.com/gym/106020/submission/380545741
def main():
    n, k = MII()
    nums = LII()
    
    idxs1 = list(range(0, n, 2))
    idxs2 = list(range(1, n, 2))
    
    idxs1.sort(key=lambda x: nums[x])
    idxs2.sort(key=lambda x: nums[x])
    
    def output(x):
        print(x + 1, flush=True)
        II()
    
    for i in range(k):
        v = II()
        
        if v == 1:
            resid = k - i
            if nums[idxs1[-1]] >= nums[idxs2[-resid]]:
                output(idxs1.pop())
            else:
                output(idxs2.pop())
        else:
            output(idxs2.pop())