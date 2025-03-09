# https://codeforces.com/problemset/problem/803/D
# https://codeforces.com/contest/803/submission/309167182
def main():
    k = II()
    s = I()

    lengths = []
    cnt = 0
    # 依据 '.' 或 '-' 拆分单词
    # '.' 或 '-' 也算单词长度，除最后一个单词不算
    for ch in s:
        cnt += 1
        if ch == "-" or ch == " ":
            lengths.append(cnt)
            cnt = 0
    # 最后一个单词长度
    lengths.append(cnt)

    def check(m):
        # 要求 每一行字母数 <= m
        # 总行数 <= k
        row_cnt = 1
        cur = 0
        for length in lengths:
            if length > m:
                return False
            if cur + length > m:
                row_cnt += 1
                cur = length
            else:
                cur += length
        return row_cnt <= k

    l = max(lengths) - 1  # 每行至少比最长的一个单词长
    r = len(s) + 1
    while l + 1 < r:
        m = l + (r - l) // 2
        if check(m):
            r = m
        else:
            l = m

    print(r)


if __name__ == "__main__":
    main()
