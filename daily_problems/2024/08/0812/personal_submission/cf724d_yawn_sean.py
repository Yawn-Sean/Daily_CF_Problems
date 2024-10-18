# Submission link: https://codeforces.com/contest/724/submission/275874122
def main():
    m = II()
    s = [ord(c) - ord('a') for c in I()]
    n = len(s)

    for i in range(26):
        cur = -1
        flg = True
        for idx in range(n):
            if s[idx] <= i:
                cur = idx
            elif idx - cur >= m:
                flg = False
        if flg:
            cnt = [0] * 26
            cur = -1
            pos = -1
            for idx in range(n):
                if s[idx] < i:
                    cur = idx
                    cnt[s[idx]] += 1
                elif s[idx] == i:
                    pos = idx
                if idx - cur == m:
                    cnt[s[pos]] += 1
                    cur = pos
            print(''.join(chr(ord('a') + i) * cnt[i] for i in range(26)))
            break