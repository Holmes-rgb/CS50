from cs50 import get_string
import string
import math

text = get_string("text:")

numchar = 0

for i in range(len(text)):
    if text[i].isalpha():
        numchar += 1
print(numchar)

numword = 1
for j in range(len(text)):
    if (text[j] == ' '):
        numword += 1

print(numword)

num_sent = 0
for k in range(len(text)):
    if ((text[k] == '.') or (text[k] == '?') or (text[k] == '!')):
        num_sent += 1
print(num_sent)

grade = 0.0588 * (100 * float(numchar) / float(numword)) - 0.296 * (100 * float(num_sent) / float(numword)) - 15.8
# L = average number of letters per 100 words
# S is the average number of sentences per 100 words in the text

grade_level = round(grade)


if (grade_level >= 16):
    print("Grade 16+")

elif (grade_level < 1):
    print("Before Grade 1")

else:
    print("Grade " + str(grade_level))