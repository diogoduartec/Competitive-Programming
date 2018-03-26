s = input()
flag = False
for i in range(len(s)-1):
    if(s[i]==s[i+1]=='s'):
        flag = True
        break

if flag:
    print('hiss')
else:
    print('no hiss')
