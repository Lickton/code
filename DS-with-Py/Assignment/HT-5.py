# m = int(input("请输入m:"))
# n = int(input("请输入n:"))
# res = [[i * j for j in range(n)] for i in range(m)]
# print(res)

# CPU times: user 3 µs, sys: 1 µs, total: 4 µs
# Wall time: 7.15 µs
# def JudegeWanShu(n):
#     judge = [i for i in range(1, n) if n % i == 0]
#     count = 0
#     for i in judge:
#         count += i
#     if count == n:
#         return True
#     return False

# res = [i for i in range(1, 100) if JudegeWanShu(i)]
# print(res)

# import re
# password_Origin = input()
# password = password_Origin.split(",")
# res = []
# for i in password:
#     if 6 <= len(i) <= 12 and re.search("[a-z]", i) and re.search("[A-Z]", i) and re.search("[0-9]", i) and re.search("[$#@]", i):
#         res.append(i)
# print(res)

def Divisible_By_Nine(n):
    for i in range(n):
        if i % 9 == 0:
            yield i

n = 99
for i in Divisible_By_Nine(n):
    print(i, end=' ')