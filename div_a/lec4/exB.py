#!/bin/python
import sys

n, m = map(int, sys.stdin.readline().split())
letters = dict()
for i in range(n):
    for sym in sys.stdin.readline()[:-1]:
        if sym not in letters:
            letters[sym] = 0

        letters[sym] += 1

for i in range(m):
    for sym in sys.stdin.readline()[:-1]:
        letters[sym] -= 1

for letter, count in letters.items():
    for i in range(count):
        sys.stdout.write(letter)

sys.stdout.write('\n')
