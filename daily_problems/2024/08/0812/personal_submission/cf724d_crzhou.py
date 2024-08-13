from collections import Counter

def main():
    m = int(input())
    s = input()
    n = len(s)

    s = [ord(c) - ord('a') for c in s]
    
    cn = Counter(s)
    
    ans = [0] * 26
    for a in range(26):
        c = a
        p, t, n_selected = -1, -1, 0
        ok = True
        
        for i in range(n):
            if s[i] < c:
                p = i
            elif s[i] == c:
                t = i
            
            if i - p >= m:
                if t >= 0 and i - m < t:
                    p = t
                    t = -1
                    n_selected += 1
                else:
                    ok = False
                    ans[c] = cn[c]
                    break
        
        if ok:
            ans[c] = n_selected
            break
    
    result = []
    for i in range(26):
        if ans[i] > 0:
            result.extend([chr(i + ord('a'))] * ans[i])
    
    print(''.join(result))

if __name__ == "__main__":
    main()
