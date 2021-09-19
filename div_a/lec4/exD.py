#!/bin/python
import sys

def count_digits(number):
    count = dict()
    for d in number:
        if d not in count:
            count[d] = 0
        count[d] += 1

    return count

def intersect(left, right):
    res = dict()
    for k in left:
        if k in right:
            res[k] = min(left[k], right[k])

    return res

kate_number = sys.stdin.readline().split()[0]
alex_number = sys.stdin.readline().split()[0]

kate_digit_count = count_digits(kate_number)
alex_digit_count = count_digits(alex_number)

d = intersect(kate_digit_count, alex_digit_count)

keys = sorted(d.keys())[::-1]

if len(keys) == 0:
    sys.stdout.write(f'{-1}')
elif keys[0] == '0':
    sys.stdout.write('0')
else:
    for k in keys:
        for i in range(d[k]):
            sys.stdout.write(k)

sys.stdout.write('\n')
