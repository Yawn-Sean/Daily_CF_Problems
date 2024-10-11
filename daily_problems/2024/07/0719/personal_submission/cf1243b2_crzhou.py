def solve():
    global n
    n = int(input().strip())
    s = list(input().strip())
    t = list(input().strip())
    op = []
    
    for i in range(len(s)):
        if s[i] != t[i]:
            flag = False
            # 查找 t[i] 在 t 中的下一个出现位置
            for j in range(i + 1, len(t)):
                if t[j] == t[i]:
                    flag = True
                    op.append((i + 1, j + 1))
                    s[i], t[j] = t[j], s[i]
                    break
            if not flag:
                # 查找 s 中是否有与 t[i] 相等的字符
                for j in range(i + 1, len(s)):
                    if s[j] == t[i]:
                        flag = True
                        op.append((j + 1, len(t)))
                        s[j], t[len(t) - 1] = t[len(t) - 1], s[j]
                        op.append((i + 1, len(t)))
                        s[i], t[len(t) - 1] = t[len(t) - 1], s[i]
                        break
            if not flag:
                print("NO")
                return
    
    print("YES")
    print(len(op))
    for operation in op:
        print(operation[0], operation[1])
