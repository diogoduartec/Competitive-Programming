import re

def isValidCpf(cpf):
    ac = 0
    for i in range(1,10):
        ac += i*(int(cpf[i-1]))
    if ac%11==10:
        b1 = 0
    else:
        b1 = ac%11
    if(b1!=int(cpf[9])):
        return False
    ac = 0
    mult = 9
    for i in range(10):
        ac += int(cpf[i]) * mult
        mult-=1
    if ac%11 == 10:
        b2 = 0
    else:
        b2 = ac%11
    if b2!=int(cpf[10]):
        return False
    return True


while True:
    try:
        cpf = input()
        if(re.search(r'^\d{3}(\.\d{3}){2}-\d{2}$',cpf)):
            cpf = cpf.replace('.','')
            cpf = cpf.replace('-','')
            if isValidCpf(cpf):
                print('CPF valido')
            else:
                print('CPF invalido')
        else:
            print('CPF invalido')
    except EOFError:
        break
