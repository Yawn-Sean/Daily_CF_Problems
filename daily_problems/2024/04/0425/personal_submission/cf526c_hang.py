'''
    性价比：糖果1克可以贡献多少快乐值
    选择性价比高的糖果替换性价比低的糖果
    https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/04/0425/solution/cf526c.md
'''
def main():
    c,h_r,h_b,w_r,w_b = map(int,input().split())
    ans = 0
    for i in range(100000):
        if w_r * i > c:
            break
        ans = max(ans, i * h_r + (c - w_r * i) // w_b * h_b)
    for i in range(100000):
        if w_b * i > c:
            break
        ans = max(ans, i * h_b + (c - w_b * i) // w_r * h_r)
    print(ans)
        
main()