# 字符串s中只存在0和1 
# 长度为11的字符串s必定含有s[x] == s[x+k] == s[x+2k]
# 预处理出所有的可能情况即可
def main():
    v = [set() for i in range(12)]
    for i in range(3, 12):
        for j in range(1<<i):
            t = bin(j)[2:].zfill(i)
            f = False
            for m in range(i):
                for z in range(1, i):
                    if m - z < 0 or m + z >= i:
                        break
                    if t[m-z] == t[m] == t[m+z]:
                        f = True
            if f:
                v[i].add(j)
    s = input()
    n = len(s)
    ans = 0
    for i in range(n):
        cur = 0
        for j in range(i, n):
            cur = cur*2 + int(s[j])
            if cur in v[j-i+1]:
                ans += n - j
                break
    print(ans)

if __name__ == '__main__':
    main()