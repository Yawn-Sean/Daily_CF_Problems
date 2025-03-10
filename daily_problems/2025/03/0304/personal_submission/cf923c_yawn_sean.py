# Submission link: https://codeforces.com/contest/923/submission/308861726
def main():
    zero = [0] * (10 ** 7)
    one = [0] * (10 ** 7)
    cnt = [0] * (10 ** 7)
    pt = 0

    def insert(x):
        nonlocal pt
        cur = 0
        for i in range(29, -1, -1):
            if x >> i & 1:
                if one[cur] == 0:
                    pt += 1
                    one[cur] = pt
                cur = one[cur]
            else:
                if zero[cur] == 0:
                    pt += 1
                    zero[cur] = pt
                cur = zero[cur]
            cnt[cur] += 1

    def delete(x):
        cur = 0
        for i in range(29, -1, -1):
            cur = one[cur] if x >> i & 1 else zero[cur]
            cnt[cur] -= 1

    def minXor(x):
        cur = 0
        ans = 0
        for i in range(29, -1, -1):
            if x >> i & 1:
                if one[cur] and cnt[one[cur]]:
                    cur = one[cur]
                else:
                    cur = zero[cur]
                    ans |= 1 << i
            else:
                if zero[cur] and cnt[zero[cur]]:
                    cur = zero[cur]
                else:
                    cur = one[cur]
                    ans |= 1 << i
        return ans

    n = II()
    nums1 = LII()
    nums2 = LII()

    for v in nums2:
        insert(v)

    ans = []
    for v in nums1:
        x = minXor(v)
        delete(v ^ x)
        ans.append(x)

    print(' '.join(map(str, ans)))