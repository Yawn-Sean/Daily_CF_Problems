# Submission Link: https://codeforces.com/contest/570/submission/268852239
def main():
    n, q = MII()
    nums = [1 if c == '.' else 0 for c in 'a' + I() + 'a']

    ans = 0
    cnt = 0
    for x in nums:
        if x: cnt += 1
        else:
            if cnt: ans += cnt - 1
            cnt = 0
    if cnt: ans += cnt - 1

    outs = []
    for _ in range(q):
        idx, c = LI()
        idx = int(idx)
        flg = 1 if c == '.' else 0
        
        if flg != nums[idx]:
            if flg:
                ans += 1
                ans += nums[idx - 1] and nums[idx+1]
                ans -= nums[idx - 1] == 0 and nums[idx + 1] == 0
                
            else:
                ans -= 1
                ans -= nums[idx - 1] and nums[idx+1]
                ans += nums[idx - 1] == 0 and nums[idx + 1] == 0
        nums[idx] = flg
        
        outs.append(ans)

    print('\n'.join(map(str, outs)))