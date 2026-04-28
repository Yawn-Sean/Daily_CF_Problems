# Submission link: https://codeforces.com/gym/106501/submission/372682144
def main():
    n, k = MII()
    nums = LII()
    
    for i in range(n):
        nums[i] -= k
    
    tags = LII()
    
    st_range = sorted(range(n), key=lambda x: -nums[x])
    pos = [0] * n
    
    for i in range(n):
        pos[st_range[i]] = i
    
    seg = SegTree(add, 0, n)
    seg_cnt = SegTree(add, 0, n)
    
    total = 0
    cnt = 0
    
    for i in range(n):
        if tags[i] == 2:
            if nums[i] >= 0:
                total += nums[i]
                cnt += 1
            else:
                seg.set(pos[i], -nums[i])
                seg_cnt.set(pos[i], 1)
    
    p = seg.max_right(0, lambda x: x <= total)
    ans = cnt + seg_cnt.prod(0, p)
    
    for i in range(n):
        if tags[i] == 1:
            if nums[i] >= 0:
                total += nums[i]
                cnt += 1
            else:
                seg.set(pos[i], -nums[i])
                seg_cnt.set(pos[i], 1)
        else:
            if nums[i] >= 0:
                total -= nums[i]
                cnt -= 1
            else:
                seg.set(pos[i], 0)
                seg_cnt.set(pos[i], 0)
    
        p = seg.max_right(0, lambda x: x <= total)
        ans = fmax(ans, cnt + seg_cnt.prod(0, p))
    
    print(ans)