n=II()
s=Counter()
ans =0
for i in LII():
    s[i]+=1

for i in sorted( s.keys()):
    cur = i
    while  s[cur ]>=2:
        s[cur +1]+=s[cur ]//2
        s[cur ]%=2
        if not s[cur]:
            s.pop(cur)
        cur+=1
print(max(s.keys())-len(s )+1)
