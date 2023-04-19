def add_numbers(list_input):
	total = 0
	for x in list_input:
		total += x
	return total


def add_vectors(u, v):
	list_bracket = []
	for x in range(0, len(u)):
		if len(u) == len(v):
			list_bracket.append(u[x] + v[x])
		else:
			return None

	return list_bracket


def word_selector(sentence):
	length = 0
	longest = []
	sentence = sentence.split()
	for x in sentence:
		if len(x) > length:
			longest = [x]
			length = len(x)
		elif len(x) == length:
			longest.append(x)


	return longest