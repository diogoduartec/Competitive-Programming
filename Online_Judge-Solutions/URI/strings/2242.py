inp = input()
out = ''
for c in inp:
	if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u'):
		out += c
outr = ''.join(reversed(out))

if(out == outr):
	print('S')
else:
	print('N')