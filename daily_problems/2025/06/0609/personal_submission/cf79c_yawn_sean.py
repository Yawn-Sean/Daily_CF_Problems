# Submission link: https://codeforces.com/problemset/submission/79/323557907
def main():
    s = I()
    n = II()
    strs = [I() for _ in range(n)]

    start, length = 0, 0
    mi_start = 0

    for i in range(len(s)):
        for w in strs:
            if i + 1 >= len(w) and s[i + 1 - len(w):i + 1] == w:
                mi_start = fmax(mi_start, i + 1 - len(w) + 1)
        if i + 1 - mi_start > length:
            start = mi_start
            length = i + 1 - mi_start

    print(length, start)