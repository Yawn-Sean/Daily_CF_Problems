# Submission link: https://codeforces.com/contest/670/submission/337276288
def main():
    n, m, p = MII()
    s1 = [1 if c == '(' else -1 for c in I()]
    s2 = []
    
    while len(s1) > p:
        s2.append(s1.pop())
    
    for c in I():
        if c == 'R':
            s1.append(s2.pop())
        elif c == 'L':
            s2.append(s1.pop())
        else:
            c = s1.pop()
            if c == 1:
                while c:
                    c += s2.pop()
            else:
                while c:
                    c += s1.pop()
            if s2:
                s1.append(s2.pop())
    
    while s2:
        s1.append(s2.pop())
    
    print(''.join('(' if c == 1 else ')' for c in s1))