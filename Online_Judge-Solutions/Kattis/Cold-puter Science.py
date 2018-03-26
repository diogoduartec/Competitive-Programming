n = int(input())

count = 0
input_ = input()
degrees = input_.split(' ')
for i in range(n):
    degree = int(degrees[i])
    if(degree<0):
        count+=1

print(count)
