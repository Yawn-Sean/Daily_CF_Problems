# Submission link: https://codeforces.com/contest/1579/submission/264188332
def unique(vals):
    ans = []
    last = None
    for x in sorted(vals):
        if x != last: ans.append(x)
        last = x
    return ans

def main():
    n = II()
    nums = LII()
    vals = unique(nums)
    d = {v: i for i, v in enumerate(vals)}
    
    ans = cnt = 0
    fen = FenwickTree(len(vals))
    for num in nums:
        ans += min(fen.sum(d[num] - 1), cnt - fen.sum(d[num]))
        fen.add(d[num], 1)
        cnt += 1
    
    return ans