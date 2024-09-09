def main():
    a = input()
    b = input()
    c = input()
    c_a = [0] * 26
    c_b = [0] * 26
    c_c = [0] * 26
    for x in a:
        c_a[ord(x) - ord('a')] += 1
    
    for x in b:
        c_b[ord(x) - ord('a')] += 1

    for x in c:
        c_c[ord(x) - ord('a')] += 1
    t_b,t_c = 0,0

    for i in range(len(a) // len(b) + 1):
        cnt = len(a)
        f = True
        for j in range(26):
            if c_a[j] < c_b[j] * i:
                f = False
            if c_c[j]:
                cnt = min(cnt, (c_a[j] - c_b[j] * i) // c_c[j])
        if not f:
            break
        if i + cnt > t_b + t_c:
            t_b = i
            t_c = cnt
    ans = []
    ans.append(b * t_b)
    ans.append(c * t_c)
    for i in range(26):
        ans.append((c_a[i] - c_b[i] * t_b - c_c[i] * t_c) * chr(ord('a') + i))
    print("".join(ans))

    

main()