"""
Assume s is a string of lower case characters.

Write a program that prints the longest substring
 of s in which the letters occur in alphabetical order.
  For example, if s = 'azcbobobegghakl', then your program should print

Longest substring in alphabetical order is: beggh

In the case of ties, print the first substring. 
For example, if s = 'abcbcd', then your program should print

Longest substring in alphabetical order is: abc
"""
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

print("Longest substring in alphabetical order is: " + res)