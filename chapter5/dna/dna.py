# Luke Holmes

# Sources:
# https://stackoverflow.com/questions/14674275/skip-first-linefield-in-loop-using-csv-file
# https://www.w3schools.com/python/python_file_open.asp
# https://www.w3schools.com/python/ref_func_range.asp
# https://www.w3schools.com/python/ref_func_max.asp
# https://www.geeksforgeeks.org/maximum-consecutive-repeating-character-string/
# https://stackoverflow.com/questions/8369219/how-to-read-a-text-file-into-a-string-variable-and-strip-newlines
# https://www.geeksforgeeks.org/python-ways-to-print-list-without-quotes/
# https://stackoverflow.com/questions/17837316/how-do-i-skip-a-few-iterations-in-a-for-loop/17837528#17837528

import sys
import csv


def maxRepeating(s, sequence):

    seql = len(sequence)
    l = len(s)
    skip_until = 0
    rep = 0
    orep = 0

    # Find the maximum repeating
    # character starting from str[i]
    for i in range(l - seql):
        icount = 0
        if i < skip_until:
            continue

        for j in range(seql):
            if sequence[j] == s[i + j]:
                icount += 1
        if icount == seql:
            rep += 1
            skip_until = i + seql
            # I think that my error is with this line
        elif icount != seql:
            rep = 0

        if rep > orep:
            orep = rep
    return orep


if len(sys.argv) != 3:
    print("Error")
    exit(1)


with open(sys.argv[2], "r") as txtfile:
    s = txtfile.read().replace('\n', '')


list_of_rep = []

csvf = sys.argv[1]
with open(csvf, "r") as csvfile:
    reader = csv.reader(csvfile)
    sequences = next(reader)
    for i in range(1, len(sequences)):
        # print(sequences[i])
        rep = maxRepeating(s, sequences[i])
        list_of_rep.append(rep)

    for row in reader:
        rowt = ('[%s]' % ', '.join(map(str, row[1:])))
        if rowt == str(list_of_rep):
            print(row[0])
            exit(2)

print('No match')
# if no mach print no match