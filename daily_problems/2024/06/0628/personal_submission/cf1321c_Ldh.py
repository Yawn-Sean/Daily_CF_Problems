
# @TIME
def solve(testcase):
    n = II()
    s = I()
    
    for i in range(25, 0, -1):

        c, p = chr(97 + i), chr(96 + i)
        # print('s', i, s, c, p)
        while True:
            for j in range(len(s)):
                if s[j] == c:
                    if j > 0 and s[j - 1] == p:
                        s = s[:j] + s[j + 1:]
                        break
                    if j + 1 < len(s) and s[j + 1] == p:
                        s = s[:j] + s[j + 1:]
                        break
            else:
                break
    
    print(n - len(s))
        

for testcase in range(1):
    solve(testcase)
