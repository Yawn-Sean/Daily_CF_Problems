# Submission link: https://codeforces.com/contest/367/submission/317684874
def main():
    rnd = random.getrandbits(30)

    n, m, p = MII()
    nums1 = [x ^ rnd for x in MII()]
    nums2 = [x ^ rnd for x in MII()]

    cnt2 = Counter(nums2)

    ans = [0] * n

    for i in range(p):
        if i + (m - 1) * p < n:
            cnt1 = Counter()
            cnt = 0
            
            def add_element(x):
                global cnt
                if x in cnt2:
                    if cnt1[x] == cnt2[x]:
                        cnt -= 1
                    cnt1[x] += 1
                    if cnt1[x] == cnt2[x]:
                        cnt += 1
            
            def del_element(x):
                global cnt
                if x in cnt2:
                    if cnt1[x] == cnt2[x]:
                        cnt -= 1
                    cnt1[x] -= 1
                    if cnt1[x] == cnt2[x]:
                        cnt += 1
            
            for j in range(m):
                add_element(nums1[i + j * p])
            
            if cnt == len(cnt2): ans[i] = 1
            
            for ni in range(i, n, p):
                if ni + m * p >= n: break
                del_element(nums1[ni])
                add_element(nums1[ni + m * p])
                if cnt == len(cnt2):
                    ans[ni + p] = 1

    print(sum(ans))
    print(' '.join(str(i + 1) for i in range(n) if ans[i]))