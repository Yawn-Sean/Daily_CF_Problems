def main():
    data = input().split()
    idx = 0
    
    while idx < len(data):
        a = int(data[idx])
        b = int(data[idx + 1])
        idx += 2
        
        s = [0] * (b + 1)
        st = [[] for _ in range(a + 1)]
        
        for i in range(1, b + 1):
            s[i] = int(data[idx])
            idx += 1
        
        ans = 0
        for i in range(1, b + 1):
            if i != 1:
                ans += abs(s[i] - s[i - 1])
            if i != 1 and s[i] != s[i - 1]:
                st[s[i]].append(s[i - 1])
            if i != b and s[i] != s[i + 1]:
                st[s[i]].append(s[i + 1])
        
        sum_val = ans
        
        for i in range(1, a + 1):
            if st[i]:
                st[i].sort()
                p = st[i][len(st[i]) // 2]
                s1 = s2 = 0
                for j in range(len(st[i])):
                    s1 += abs(i - st[i][j])
                    s2 += abs(st[i][j] - p)
                sum_val = min(sum_val, ans - s1 + s2)
        
        print(sum_val)
