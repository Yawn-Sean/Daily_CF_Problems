# Submission link: https://codeforces.com/contest/946/submission/255169512
bit_count = [bin(i).count('1') for i in range(1 << 10)]
def main():
    s = I()
    msk = 0
    for c in s:
        msk ^= 1 << int(c)
    
    n = len(s)
    ans = ''
    if n % 2 == 0:
        for i in range(n - 1, -1, -1):
            msk ^= 1 << int(s[i])
            for j in range(int(s[i]) - 1, -1, -1):
                if i == j == 0: break
                nmsk = msk ^ (1 << j)
                if bit_count[nmsk] <= n - i - 1:
                    ans = s[:i] + str(j) + '9' * (n - i - 1 - bit_count[nmsk]) + ''.join(str(x) for x in range(9, -1, -1) if nmsk >> x & 1)
                    break
            if ans: break
    return ans if ans else '9' * ((n - 1) // 2 * 2)