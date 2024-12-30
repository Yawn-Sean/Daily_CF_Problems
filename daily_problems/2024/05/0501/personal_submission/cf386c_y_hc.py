'''
1.考虑以j结尾的子字符串 i开始是在j这个位置 i在向前移动的过程中 移动到哪些位置会让diversity加1
'''
def solve():
    s = I()
    n = len(s)
  
    d = len(set(s))
    ans = [0] * (d + 1)
    ans[0] = d
    last_index = [-1] * 27
  
    for end in range(n):
        last_index[ord(s[end]) - 97] = end
        tmp = last_index.copy()
        tmp.sort(reverse = True)
        d = 0
        for i in range(26):
            if tmp[i] == -1: break
            d += 1
            ans[d] += tmp[i] - tmp[i + 1]

    print(*ans, sep = '\n')
  
t = 1
for _ in range(t):
    solve()
