def main():
    t = II()
    outs = []

    for _ in range(t):
        n, k = MII()
        nums = LII()

        seg = SegTree(fmax, 0, nums)
        pt = 0
        
        ans = [0] * n
        while pt < n:
            x = seg.prod(pt, fmin(pt + k, n))
            for i in range(pt, n):
                ans[i] = x
                if nums[i] == x:
                    orig_pt = pt
                    pt = i + 1
                    for j in range(i + 1, n):
                        if j >= orig_pt + k or seg.prod(j, fmin(j + k, n)) > x:
                            break
                        ans[j] = x
                        pt = j + 1
                    break
        
        outs.append(' '.join(map(str, ans)))

    print('\n'.join(outs))