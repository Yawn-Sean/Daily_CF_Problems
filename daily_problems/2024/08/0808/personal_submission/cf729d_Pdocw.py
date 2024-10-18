def main():
    n, a, b, k = MII()
    s = I()

    tmp = []
    cur = 0
    for i in range(n):
        if s[i] == '0':
            cur += 1
            if cur == b:
                tmp.append(i)
                cur = 0
        else:
            cur = 0


    print(len(tmp) - a  + 1)
    print(*(x + 1 for x in tmp[a - 1:]))
    return
