# Submission link: https://codeforces.com/contest/909/submission/261262529
def main():
    s = I()

    chars = [s[0]]
    cnt = [1]

    for i in range(1, len(s)):
        if s[i] == chars[-1]:
            cnt[-1] += 1
        else:
            chars.append(s[i])
            cnt.append(1)

    ans = 0
    while len(chars) > 1:
        ans += 1
        
        nchars = []
        ncnt = []
        if cnt[0] > 1:
            nchars.append(chars[0])
            ncnt.append(cnt[0] - 1)
        
        for i in range(1, len(chars) - 1):
            if cnt[i] > 2:
                if nchars and nchars[-1] == chars[i]:
                    ncnt[-1] += cnt[i] - 2
                else:
                    nchars.append(chars[i])
                    ncnt.append(cnt[i] - 2)
        
        if cnt[-1] > 1:
            if nchars and nchars[-1] == chars[-1]:
                ncnt[-1] += cnt[-1] - 1
            else:
                nchars.append(chars[-1])
                ncnt.append(cnt[-1] - 1)
        
        chars = nchars
        cnt = ncnt

    print(ans)