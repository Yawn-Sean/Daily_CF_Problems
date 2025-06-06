# Submission link: https://codeforces.com/contest/906/submission/323058204
def main():
    n = II()

    msk1 = (1 << 26) - 1
    msk2 = 0

    flg = 0
    ans = 0

    for _ in range(n - 1):
        c, w = LI()
        
        if c != '.':
            ans += flg
        
        cur_msk = 0
        for ch in w:
            cur_msk |= 1 << ord(ch) - ord('a')
        
        if c == '!':
            msk1 &= cur_msk
        else:
            msk2 |= cur_msk
        
        val = msk1 - (msk1 & msk2)
        if val & -val == val:
            flg = 1
        
    print(ans)