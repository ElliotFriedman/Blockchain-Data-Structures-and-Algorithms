import hashlib

#run this with python2, otherwise you will get an encoding error

#do the initial hashing
def hashlist(a):
	
	ret = []
	i = 0
	while i < len(a):
            tmp = hashlib.sha256(a[i]).hexdigest()

            ret.append(tmp)
            i += 1

	print(ret)
	return ret

#build the merkle tree
def merkletree(a):

        print("len merkle tree ", len(a))

        if len(a) == 1:
            return a
        
        ret = []
	i = 0
	len1 = len(a)
	while i < len1:
		if len(a) > 1:
		    tmp = a[0] + a[1]
		    a.pop(0)
		    a.pop(0)
		else:
		    tmp = a[0]
		    a.pop(0)

		tmp = hashlib.sha256(tmp).hexdigest()
                ret.append(tmp)
		i += 2
	return merkletree(ret)


a = ["a", "b", "c", "d"]
a = hashlist(a)
i = 0

a = merkletree(a)
print("Final result")
print(a)

