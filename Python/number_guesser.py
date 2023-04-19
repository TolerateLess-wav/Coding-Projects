import random

#Taking inputs
number = random.randint(1, 10)

count = 0

print("What Number am I thinking that's between 1 and 10, player?")

while count > -1:
	guess = int(input())

	count = count + 1

	if guess == number:
		print("Congratulations, that's the right number!")
		print("And your total amount of guesses were", count, "!")
		break

	elif guess < number:
		print("No, sorry, but go higher!")

	elif guess > number:
		print("No, sorry, but go lower!")

