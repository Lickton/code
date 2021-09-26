from collections import Counter


score = []

for i in range(10):
    j = int(input("Please enter 10 scores, " + str(10-i) + " left:"))
    score.append(j)

print("The third one is: " + str(score[2]))

print("From the first to the sixth:" + str(score[:6]))

score.insert(2, 59)
print("After add 59 in front of the third one:\n" + str(score))

num = 76
print(score.count(num))
print("How many times does the num appear? " + str(score.count(num)))

print("Is the num in score? " + str(num in score))

print("Who is the guy win the 100 points: " + str(score.index(100)))

for i in range(len(score)):
    if score[i] == 59:
        score[i] += 1
print("Help the 59s: " + str(score))

del(score[0])
print("After deletign the first one:\n" + str(score))

print("The length of the score is: "+ str(len(score)))

score.sort()
message1 = "The highest score of the exam is: "
message2 = "The lowest score of the exam is: "
print(message1 + str(score[-1]))
print(message2 + str(score[0]))

score.reverse()
print("After reverse the list is:\n" + str(score))

_remove_ = score.pop()
print("The one that's be poped is " + str(_remove_))

score.append(88)
print("After been appended the scores are changed into:\n" + str(score))

score1 = [80, 61]
score2 = [71, 95, 82]
score1.extend(score2)
print("After extened:\n" + str(score1))

score1 = [80, 61]
score2 = score1 * 5
print("Score2 is 5 times than score1:\n"+ str(score2))



