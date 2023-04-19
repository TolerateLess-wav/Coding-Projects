import time
import random



def start_adventure():
	print("Welcome to your adventure!")
	time.sleep(1.5)
	print("The rules are simple; Each option is presented in parantheses. Sometimes the options aren't shown, so use ya brain to reliably pick.")
	time.sleep(2.5)
	print("Another tidbit is you don't have to type the exact option. For example, if prompted to answer with 'r', you can type 'r', 'R', or the word 'right' in any format.")
	time.sleep(2.5)
	print("\nLet's try this. Pick the option 'r'. (l or r)")
	answer = input(">_").lower()

	if "r" in answer:
		print("Nice, now you know how this will work!")
		time.sleep(1.5)
		print("Have fun playing!")
		time.sleep(1.5)
		stuffy_room()
	elif "l" in answer:
		print("Ehh, wrong answer, but you get the gist of it, right?")
		time.sleep(1.5)
		print("Enjoy!")
		time.sleep(1.5)
		stuffy_room()
	else:
		game_over("bruh")


def stuffy_room():
	print("\n---You wake up in a wet and damp room, water dripping from an unknown source above you.")
	time.sleep(1.5)
	print("A slightly opened door is infront of you, with no other entrances or exits.")
	time.sleep(1.5)
	print("\nDo you enter the door?")

	answer = input(">_").lower()

	if "yes" in answer:
		eerie_hallway()
	else:
		game_over("By staying in the room, a sudden dark corner lunges at you and your fate is sealed. (Maybe ya should've typed yes lmao)")


def eerie_hallway():
	print("\nLeaving the room, you hear a distant noise upon leaving. You instinctively shut the door, as whatever is behind it rams it on the opposite side repeatedly.")
	time.sleep(1.5)
	print("The door won't hold for long. Type (block) repeatedly to survive!")
	answer = input(">_").lower()

	#starts a counter to count the amount of times (randomly) block is typed
	occurence = 0
	attempts = random.randint(3,4)
	while occurence < attempts:
		if "block" == answer:
			print("You continue to apply pressure as the creature persists.")
			answer = input(">_").lower()
			occurence = occurence + 1

		#if anything else other than 'block' is typed, leaves a game over		
		else:
			game_over("You slip up holding the door close as the creature breaks through and tears you to shreds.")

	if occurence == attempts:
		eerie_hallway2()

	
def eerie_hallway2():
	print("\nThe banging and growling subsided, as you look ahead the hallway and notice a bloodied door on your right, a green painted door on your left, and a rusted-looking door infront of you.")
	time.sleep(1.5)
	print("Which door do you choose? (R or L or A)")
	answer = input(">_").lower()

	if "r" in answer:
		blood_door()
		
	elif "l" in answer:
		green_door()

	elif "a" in answer:
		rusted_door()



def blood_door():
	print("\nMaking your way to the bloodied door, you opened it and see nothing but a distant light shining on a pedestal in the middle of the room.")
	time.sleep(1.5)
	print("Upon closer inspection, you notice a bronze key on the pedestal.")
	time.sleep(1.5)
	print("Do you approach the pedestal? (Y or N)")
	answer = input(">_").lower()

	if "y" in answer:
		monster_encounter()

	elif "n" in answer:
		print("\nYour instincts told you this isn't a swell idea, so you decide to exit the room.")
		time.sleep(1.5)
		eerie_hallway()


def green_door():
	game_over("You approach the green door, but as you open it, a spike jams into your cranium, rendering you limpless.")



def rusted_door():
	print("\nAs you approach the rusted-looking door, you noticed there's only a single lock, with no doorknob or handle in sight.")
	time.sleep(1.5) 
	print("You grumbled as you turned around and choose between the other two doors. (L or R)")
	answer = input(">_").lower()

	if "r" in answer:
		green_door()

	elif "l" in answer:
		blood_door()



def monster_encounter():
	print("\nWalking towards the pedestal, you grab the key. Before long, you realise that you're not alone, as a bipedal creature awakens to your arrival, and slowly opproches you.")
	time.sleep(1.5)
	print("You know you don't have time to think of a plan. Act quickly. What will you do?")
	answer = input(">_").lower()

	if "run" in answer:
		game_over("The moment you turned around, you see your vision glance at the ceiling, then at the ground towards your headless body.")

	elif "dodge" in answer:
		print("\nYour years of getting beat up in highschool payed off, as you effortlessly dodged the creature's swing.")
		time.sleep(1.5)
		print("You narrowly escaped, closing the door in a panic.")
		time.sleep(2)
		rusted_door2()

	elif "fight" in answer:
		fight_state()
		


def rusted_door2():
	print("\nYou remembered glancing at the rusted-looking door, and instinctively walked towards it. With your key in hand, you decide to see what's behind door #3.")
	time.sleep(2.5)
	print("Do you unlock the door? (Y or N)")
	answer = input(">_").lower()

	if "y" in answer:
		ending()

	if "n" in answer:
		alternate_ending()



def fight_state():
	print("\nYou mustered up the courage to go toe to toe with this unknown threat.")
	time.sleep(2.5)
	print("\nYou have 10 seconds to decide what ingenius action to do. Maybe you will be the hero to defeat this accursed beast.")
	time.sleep(10)
	print("What shall you do?")
	answer = input(">_").lower()

	game_over("Before you even thought of what to do, the creature slaps you into a wall, rendering you body to go limp. Guess that wasn't the right plan, huh?")



	
def ending():
	print("\nYou open the door, as a light from it shines brightly. As you step into the blaring lightsource, you open your eyes and your outside of your home.")
	time.sleep(3)
	print("Was that all a dream? Or were there bits of reality in this expidition? You wouldn't know, and your neighbors giving you the crazy eye don't seem to know either.")
	time.sleep(3)
	print("You sighed as you sluggishly walk back into your house and watch Netflix for the rest of the day, ya bum.")
	time.sleep(4)
	you_win()


def alternate_ending():
	print("\nFor some odd reason, you decide against it, like every braincell died at the same time.")
	time.sleep(1)
	print("So you decided to vibe with the creature in the original room, but upon entering it, you see your normal bedroom and a dog sitting by the door, wagging its tail upon seeing you.")
	time.sleep(1)
	print("Was it all a dream...? You shrug it off and yeet to Youtube to watch cringe compilations for 4 hours.")
	time.sleep(3)
	you_win()


def you_win():
	print("\nThank you very much for playing this pretty short little game of mine.")
	time.sleep(1.5)
	print("\nHope the schmuck that played this abomination enjoyed it lmao.")
	time.sleep(3)
	exit()


def game_over(string):
	print("\n" + string)
	time.sleep(3.5)
	print("Ya win some and ya lose some!")
	retry()


def retry():
	time.sleep(1.5)
	print("\nWould you like to try again? (Yes or No)")
	answer = input(">_").lower()

	if "yes" in answer:
		stuffy_room()
	else:
		exit()





start_adventure()