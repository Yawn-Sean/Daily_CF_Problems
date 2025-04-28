def main():
    n,k = MII()
    s,t = map(str,input().split('.'))
    m = len(s)

    def cal(s):
        m = len(s)
        i = m - 1
        while i:
            if s[i] == '9':
                i -= 1
            else:
                break
        if i == -1:
            return '1' + '0' * m
        else:
            return s[:i] + str(int(s[i]) + 1) + '0' * (m - i - 1)
    for i in range(len(t)):
        x = t[i]
        if x >= '5':
            for j in range(i - 1, -2,-1):
                if j == -1:
                    return print(cal(s))
                if t[j] != '4':
                    break
                k -= 1
                if k == 0:
                    break
            return print(s + '.' + t[:j] + str(int(t[j]) + 1))
    print(s + '.' + t)

