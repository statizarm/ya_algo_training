#!/bin/python
import sys

n = int(sys.stdin.readline())

sym_count = dict()

for i in range(n):
    c = sys.stdin.read(1)
    if c not in sym_count:
        sym_count[c] = 0
    sym_count[c] += 1

res = []
odd = ''
for sym in sorted(sym_count.keys()):
    if sym_count[sym] % 2 == 1 and odd == '':
        odd = sym
    res += [sym] * (sym_count[sym] // 2)

sys.stdout.write(''.join(res + [odd] + res[::-1]))
sys.stdout.write('\n')
