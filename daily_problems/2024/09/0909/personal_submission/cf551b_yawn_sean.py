# Submission link: https://codeforces.com/contest/551/submission/280381501
def main():
    a = I()
    b = I()
    c = I()

    cnt_a = [0] * 26
    cnt_b = [0] * 26
    cnt_c = [0] * 26

    for x in a: cnt_a[ord(x) - ord('a')] += 1
    for x in b: cnt_b[ord(x) - ord('a')] += 1
    for x in c: cnt_c[ord(x) - ord('a')] += 1

    x, y = 0, 0

    for i in range(len(a) // len(b) + 1):
        cnt = len(a)
        flg = True
        for j in range(26):
            if cnt_a[j] < cnt_b[j] * i:
                flg = False
            if cnt_c[j]:
                cnt = fmin(cnt, (cnt_a[j] - cnt_b[j] * i) // cnt_c[j])
        if not flg: break
        if i + cnt > x + y:
            x, y = i, cnt

    outs = []
    outs.append(b * x)
    outs.append(c * y)

    for i in range(26):
        outs.append((cnt_a[i] - cnt_b[i] * x - cnt_c[i] * y) * chr(ord('a') + i))

    print(''.join(outs))