s = input()
maxCount = 0
for i in range(len(s)):
    count = 1
    temp = s[i:][0]
    for k in range(1, len(s[i:])):
        if s[i:][k] >= temp[-1]:
            temp += s[i:][k]
            count += 1
        else:
            break
    if count > maxCount:
        maxCount = count
        res = temp

print(res)