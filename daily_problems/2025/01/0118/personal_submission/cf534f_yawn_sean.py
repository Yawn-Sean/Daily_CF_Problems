# Submission link: https://codeforces.com/contest/534/submission/301501447
def main():
    n, m = MII()
    nums1 = LII()
    nums2 = LII()

    msk_seps = [[] for _ in range(n + 1)]
    for i in range(1 << n):
        cnt = 0
        cur = 0
        for j in range(n):
            if i >> j & 1:
                if cur == 0:
                    cnt += 1
                cur = 1
            else:
                cur = 0
        msk_seps[cnt].append(i)

    total_msk = 6 ** 5 * 2 ** 5
    total = 1 << n
    pw6 = [6 ** i for i in range(5)]

    left = m // 2
    right = m - m // 2

    dp_left = [[-2] * total_msk for _ in range(left + 1)]
    dp_left[0][0] = -1

    for i in range(left):
        for msk in range(total_msk):
            if dp_left[i][msk] != -2:
                status, border = divmod(msk, total)
                for nborder in msk_seps[nums2[i]]:
                    nstatus = status
                    new_pos = nborder - (border & nborder)
                    for j in range(n):
                        if new_pos >> j & 1:
                            nstatus += pw6[j]
                    nmsk = nstatus * total + nborder
                    dp_left[i + 1][nmsk] = msk

    dp_right = [[-2] * total_msk for _ in range(right + 1)]
    dp_right[0][0] = -1

    for i in range(right):
        for msk in range(total_msk):
            if dp_right[i][msk] != -2:
                status, border = divmod(msk, total)
                for nborder in msk_seps[nums2[m - 1 - i]]:
                    nstatus = status
                    new_pos = nborder - (border & nborder)
                    for j in range(n):
                        if new_pos >> j & 1:
                            nstatus += pw6[j]
                    nmsk = nstatus * total + nborder
                    dp_right[i + 1][nmsk] = msk

    for msk1 in range(total_msk):
        if dp_left[left][msk1] != -2:
            status1, border1 = divmod(msk1, total)
            v = status1
            tmp = []
            for _ in range(n):
                tmp.append(v % 6)
                v //= 6
            
            for border2 in range(1 << n):
                share = border1 & border2
                
                flg = True
                status2 = 0
                for i in range(n):
                    target = nums1[i] - tmp[i]
                    if share >> i & 1:
                        target += 1
                    if not 0 <= target < 6:
                        flg = False
                    status2 += target * pw6[i]
                
                if not flg: continue
                
                msk2 = status2 * total + border2
                if dp_right[right][msk2] != -2:
                    l_ans = []
                    for i in range(left, 0, -1):
                        l_ans.append(msk1 % total)
                        msk1 = dp_left[i][msk1]
                    r_ans = []
                    for i in range(right, 0, -1):
                        r_ans.append(msk2 % total)
                        msk2 = dp_right[i][msk2]
                    ans = l_ans[::-1] + r_ans
                    
                    out = [['.'] * m for _ in range(n)]
                    for i in range(n):
                        for j in range(m):
                            if ans[j] >> i & 1:
                                out[i][j] = '*'
                    
                    print('\n'.join(''.join(x) for x in out))
                    exit()