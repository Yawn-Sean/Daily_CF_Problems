s = input()
ans = int(s[0]) + 10 * len(s) - 10
for ch in s[1:]:
    x = int(ch)
    if x > int(s[0]):
        break
    if x < int(s[0]):
        ans -= 1
        break

print(ans)
