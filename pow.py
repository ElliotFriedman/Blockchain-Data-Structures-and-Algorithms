import hashlib
import json
import datetime

#calculatepow takes in block and current difficulty
#then adds nonce, and checks if there is enough leading 0's

def calculatepow(block, diff):

	i = 0
	while not hashlib.sha256(block + str(i)).hexdigest().startswith('0' * diff):
		i += 1
		print(hashlib.sha256(block + str(i)).hexdigest())
	return i



block = json.dumps("hi")
#add the date and time to the block data
block += str(datetime.datetime.now())
#the difficulty will be 5, there will need to be 6 leading 0's
#in order to find a valid proof of work
#print(calculatepow(block, 5))
print(calculatepow(block, 4))
