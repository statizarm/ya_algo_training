import sys

string = input()
i = 0
j = len(string) - 1
cost = 0

while i < j:
  if string[i] != string[j]:
    cost += 1

  i += 1
  j -= 1

print(cost)

