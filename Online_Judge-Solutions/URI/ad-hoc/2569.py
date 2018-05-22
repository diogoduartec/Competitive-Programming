str_n = input()
str_n = str_n.replace('7', '0')
exp = str_n.split(' ')
a = int(exp[0])
b = int(exp[2])
if(exp[1] == '+'):
    result = a + b
else:
    result = a * b
str_n = str(result)
str_n = str_n.replace('7', '0')
n = int(str_n)
print(n)
