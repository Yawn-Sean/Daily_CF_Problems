# Submission link: https://codeforces.com/gym/100488/submission/340994157
def main():
    def query(l, r):
        print('Q', l, r, flush=True)
        return LII()
    
    def answer(nums):
        print('A', *nums, flush=True)
    
    n = II()
    
    ans = [0] * n
    to_find = set(range(1, n + 1))
    
    if n % 2:
        ans[n - 1] = query(n, n)[0]
        to_find.remove(ans[n - 1])
        n -= 1
    
    if n:
        left = set(query(1, n // 2))
        right = to_find - left
        
        for i in range(2, n // 2 + 1):
            mid = set(query(i, n + 1 - i))
            ans[i - 2] = (left - mid).pop()
            ans[n - i + 1] = (right - mid).pop()
            
            left &= mid
            right &= mid
        
        ans[n // 2 - 1] = left.pop()
        ans[n // 2] = right.pop()
    
    answer(ans)