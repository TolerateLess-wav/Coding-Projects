//Damon Milford
//11/18/22
//A TigerGame program
//~45 minutes

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
//Optional Library that I used for sleep/timer function to have a better pacing for TigerGame
#include <unistd.h>
using namespace std;

int main() {

  //NOTE WHILE PLAYING:
  //PrintHand function works, but cards do not match overlay after 1 loop; i.e. 
  //hand == purple:1, purple:2, purple:3
  //[1] purple:1 [2] purple:2  [3] purple:3
  //Choosing purple:1 will yeild purple:1, but after one loop, it will print hand as:
  //[1] purple:1 [2] purple:2
  //hand == purple:2, purple:3
  //with purple:1 being purple:2 and purple:2 being purple:3
  //Everything else works, this is the only caveate, keep in mind

  int n, dealtCard, userCard, games{0}, totalRounds{0}, playerWon{0}, pTotalWon{0}, computerWon{0}, cTotalWon{0};
  bool quit = true;
  char userChoice;
  while(quit) {

  int rounds = 1;

  //Extra Credit #1; Let user choose how many cards per player before starting
  cout << "Welcome to Tiger Game!" << endl;
  sleep(1);
  cout << "Before we start, how many cards would you like? (Can't be >20 cards)" << endl;

  cin >> userCard;

  while (userCard > 20) {
    cout << "Hey, stop trying to run me out of cards! Please pick less than 20 cards!" << endl;
    cin >> userCard;
  }

  n = userCard;

  // 1. Create a deck of cards and shuffle it.
  Deck deckOfCards;
  deckOfCards.shuffle();

  // 2. Create two players, each one with 5 cards in their hand.
  Player human(deckOfCards, userCard);
  Player computer(deckOfCards, userCard);

  // 3. Play five rounds. In each round:
  do {

    Card comCard;
    Card humCard;

    //Generates a random number between 1 and n total cards for the computer to pick a card
    srand(time(NULL));
    int ranNum = rand() % ((n - 1) + 1) + 1;

    //    - Have computer deal a card from their hands
    comCard = computer.hand.dealCard(ranNum);
    cout << "The computer plays: " << comCard.printCard() << endl;

    //    - Show human their hand of cards so that they can make a selection.
    cout << "Your hand:" << human.hand.printHand() << endl;

    //    - Have human deal their card. 
    cout << "Which card do you want to play?" << endl;
    cin >> dealtCard;

    //Check; Can't choose an option that doesn't exist anymore
    while (dealtCard > human.hand.getHandSize()) {
      cout << "You don't have that many cards in your deck, pick a valid option!" << endl;
      cin >> dealtCard;
    }

    humCard = human.hand.dealCard(dealtCard);
    cout << "You played: " << humCard.printCard() << endl;

    //    - Determine who won the round and update points accordingly.
    if(humCard.getValue() > comCard.getValue()) {
      human.score += humCard.getValue() + comCard.getValue();
      cout << "You win this round!" << endl;
      playerWon++;
    }
    else if (humCard.getValue() < comCard.getValue()) {
      computer.score += humCard.getValue() + comCard.getValue();
      cout << "The computer wins this round!" << endl;
      computerWon++;
    }
    else {
      human.score = human.score;
      computer.score = computer.score;
      cout << "Aww, it's a tie!" << endl;
    }

    //    - Print results for current rounds
    cout << "CURRENT ROUND #" << rounds << " SCORE" << endl;
    cout << "Player: " << human.score << endl;
    cout << "Computer: " << computer.score << endl;

    rounds++;
    n--;
    sleep(3);
    cout << endl;

    //do while ends here
  }while(rounds <= userCard);

  // 4. Print final game results.
  cout << "Good job!";
  sleep(1);
  cout << " You played " << rounds - 1 << " rounds!";
  sleep(1);
  cout << " And the final scores are..." << endl;
  sleep(1);
  cout << ". ";
  sleep(2);
  cout << ". ";
  sleep(2);
  cout << ". ";
  sleep(2);
  cout << "FINAL SCORES" << endl;
  cout << "Player: " << human.score << endl;
  cout << "Computer: " << computer.score << endl;

  if (human.score > computer.score) {
    cout << "Congratulations! You won this TigerGame!" << endl;
  }
  else if (computer.score > human.score) {
    cout << "Wow, you lost against a predictable AI, that's kind of sad." << endl;
    sleep(1);
    cout << "But better luck next time!" << endl;
  }
  else {
    cout << "Wow, it's a Tie! That's unexpected." << endl;
  }
  cout << "\n";

  cout << "Would you like to play again? (Y/N)" << endl;

  //Extra Credit #2, asks the user if they want to play again
  //with total scores and rounds/games added on
  cin >> userChoice;
  userChoice = toupper(userChoice);
  if (userChoice == 'N') {
    quit = false;
  }
  cout << "\n";

  games++;
  totalRounds += rounds;
  pTotalWon += playerWon;
  cTotalWon += computerWon;
  }
  cout << "In total..." << endl;
  cout << "\n";
  cout << "You played for " << games << " games, " << endl;
  cout << "With a total of " << totalRounds - 1 << " rounds!" << endl;
  cout << "With you winning " << playerWon << " of them and the computer winning " << computerWon << " of them" << endl;
  sleep(1);
  cout << "Thanks for Playing!" << endl;
  
  return 0;
}
