checker = "e"

def check_e(string):
	if checker.lower() in string.lower():
		return True
	else:
		return False



def check_letter(letter, string):
	if letter.lower() in string.lower():
		return True
	elif letter.upper() in string.upper():
		return True
	else:
		return False



def check_letter_message(letter, string):
	if letter.lower() in string.lower():
		return "The letter " + letter + " is included in " + string
	elif letter.upper() in string.upper():
		return "The letter " + letter + " is included in " + string
	else:
		return "The letter " + letter + " is not included in " + string


def check_letter_count(letter, string):
	count = 0
	for i in string.split():
		if letter.lower() in string.lower():
			count = string.lower().count(letter.lower())
			return "The letter " + letter + " is included in " + string + " " + str(count) + " times"
		
		elif letter.upper() in string.upper():
			count = string.upper().count(letter.upper())
			return "The letter " + letter + " is included in " + string + " " + str(count) + " times"
		
		else:
			return "The letter " + letter + " is not included in " + string


