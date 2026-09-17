# Submission link: https://codeforces.com/gym/106712/submission/390981557
def main():
    s = [int(c) for c in I()]
    n = len(s)
    s.reverse()
    
    for i in range(2 * n):
        s.append(0)
    
    for i in range(1, 3 * n):
        s[i] += s[i - 1]
    
    carry = 0
    for i in range(3 * n):
        s[i] += carry
        carry = s[i] // 10
        s[i] %= 10
    
    print(s[-1])