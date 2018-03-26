x = int(input())
n = int(input())
ac = 0
for i in range(n):
    spent = int(input())
    ac+=x-spent
    if ac < 0:
        ac = 0
print(ac+x)
