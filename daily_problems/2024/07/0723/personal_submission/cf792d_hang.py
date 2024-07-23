def main():
    n,q = map(int,input().split())
    def f(src,s):
        st = []
        x = n
        # a: 还要加多少偏移量
        # b: 当前子树一共多少个节点
        # c: 当前子树的根节点的相对位置
        a,b,c = 0,n,(x + 1)//2
        while True:
            if a + c == src:
                st.append((a,b,c))
                break
            elif a + c > src:
                st.append((a,b,c))
                b = b // 2
                c = (b + 1) // 2
            else:
                st.append((a,b,c))
                b = b // 2
                a += b + 1
                c = (b + 1) // 2
 
        for c in s:
            if c == 'U':
                if len(st) > 1:
                    st.pop()
            elif c == 'L':
                a,b,c = st[-1]
                b = b // 2
                c = (b + 1) // 2
                if b == 0: continue
                st.append((a,b,c))
            elif c == 'R':
                a,b,c = st[-1]
                b = b // 2
                a += b + 1
                c = (b + 1) // 2
                if b == 0: continue
                st.append((a,b,c))
        a,b,c = st[-1]
        return a + c

    ans = []
    for _ in range(q):
        src = int(input())
        s = input()
        ans.append(f(src,s))
    print(*ans,sep='\n')

main()