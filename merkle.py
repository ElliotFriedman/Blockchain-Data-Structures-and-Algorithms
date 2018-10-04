import hashlib

def popfront(a):
	del a[0]
	return a

#we already have append which adds an items to the end of the list
#we also have pop which deletes an item from a specific index

def hashlist(a):
	ret = []

	i = 0
	while i < len(a):
		ret.append(hashlib.sha256(a[i]).hexdigest())
		i += 1
	return ret

def merkletree(a):
	
	while len(a) > 1:
		a.append(hashlib.sha256(a[0] + a[1]).hexdigest())
		a.pop(0)
		if len(a) > 1:
			a.pop(0)
		print
		i = 0
		if len(a) > 1:
			while i < len(a):
				print i,
				print (a[i])
				i += 1

	return a

a = ['a', 'b', 'c', 'd']
a = hashlist(a)
i = 0

while i < len(a):
	print i,
	print (a[i])
	i += 1

merkle = merkletree(a)
print(merkle)
