# Submission link: https://codeforces.com/gym/106682/submission/389157277
def main():
    s = [int(c) for c in I()]
    s.reverse()

    n = len(s)
    carry = 0

    for i in range(n):
        s[i] = s[i] * 9 + carry
        carry = s[i] // 10
        s[i] %= 10

    if carry: s.append(carry)
    s.append(0)

    n = len(s)
    ans = 0

    for i in range(n - 1, -1, -1):
        while s[i]:
            ans += 1
            s[0] += 1
            
            for j in range(n):
                if s[j] >= 10:
                    s[j + 1] += s[j] // 10
                    s[j] %= 10
                else:
                    break
            
            if s[i + 1] == 1: s[i + 1] -= 1
            else: s[i] -= 1

    print(ans)