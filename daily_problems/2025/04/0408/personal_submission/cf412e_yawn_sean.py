# Submission link: https://codeforces.com/contest/412/submission/314432274
def main():
    def check1(c):
        return 'a' <= c <= 'z' or '0' <= c <= '9' or c == '_'

    def check2(c):
        return 'a' <= c <= 'z' or '0' <= c <= '9'

    def check3(c):
        return 'a' <= c <= 'z'

    s = I()
    ans = 0

    n = len(s)

    for i in range(n):
        if s[i] == '@':
            l = i
            cl = 0

            while l > 0 and check1(s[l - 1]):
                l -= 1
                if check3(s[l]):
                    cl += 1
            
            r = i
            while r + 1 < n and check2(s[r + 1]):
                r += 1
            
            if r > i and r + 1 < n and s[r + 1] == '.':
                r += 1
                cr = 0
                nr = r
                while nr + 1 < n and check3(s[nr + 1]):
                    nr += 1
                    cr += 1
                ans += cl * cr

    print(ans)