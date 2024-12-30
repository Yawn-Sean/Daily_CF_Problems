def main():
    s = I()
    ans = []

    tmp0 = [] 
    tmp1 = [] 

    for i in range(len(s)):
        if s[i] == '0':
            if tmp1:
                tmp0.append(tmp1.pop())
                ans[tmp0[-1]].append(i + 1)
            else:
                tmp0.append(len(ans))
                ans.append([i + 1])
        else:
            if tmp0:
                tmp1.append(tmp0.pop())
                ans[tmp1[-1]].append(i + 1)
            else:
                print(-1)
                exit()
        # print(tmp0, tmp1, ans)
    if len(tmp1): print(-1)
    else:
        print(len(ans))
        outs = []
        for x in ans:
            outs.append(f'{len(x)} {" ".join(map(str, x))}')
        print('\n'.join(outs))
    return
