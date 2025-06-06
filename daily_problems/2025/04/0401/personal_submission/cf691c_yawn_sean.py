# Submission link: https://codeforces.com/contest/691/submission/313299874
def main():
    s = I()

    v1 = []
    v2 = []

    flg = True
    for c in s:
        if c == '.':
            flg = False
        elif flg:
            if v1 or c != '0':
                v1.append(c)
        else:
            v2.append(c)

    if v1:
        val = len(v1) - 1
    else:
        for i in range(len(v2)):
            if v2[i] != '0':
                val = -(i + 1)
                break

    s = ''.join(v1) + ''.join(v2)
    s = s.strip('0')

    x, y = '', ''
    if len(s) == 1: x = s
    else: x = s[0] + '.' + s[1:]

    if val != 0: y = 'E' + str(val)

    print(x + y)