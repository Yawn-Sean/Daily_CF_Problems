import sys
input=sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(str,input().split())
n=II()
res0=0
res1023=1023
for _ in range(n):
    op,val=MII()
    val=int(val)
    if op=='&':
        res0&=val
        res1023&=val
    elif op=='|':
        res0|=val
        res1023|=val
    elif op=='^':
        res0^=val
        res1023^=val
or_mask=res0&res1023
and_mask=res0|res1023
xor_mask=res0&(~res1023)&1023
ans=[]
if or_mask:ans.append(f"| {or_mask}")
if and_mask!=1023:ans.append(f"& {and_mask}")
if xor_mask:ans.append(f"^ {xor_mask}")
print(len(ans))
if ans:print('\n'.join(ans))
