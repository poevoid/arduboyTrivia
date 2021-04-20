
///Arduboy 2 player trivia
//poevoid
  /*
   * Alright, so here's the run-down: Player 1 holds their finger over the LEFT button,
   * Player 2 over the B button. A timer will count down from 3 and show a question, a
   * 10 second timer is represented by a ever-shortening bar at the top and bottom of the screen.
   * Whichever player presses their button first gets to answer the question. if neither player 
   * presses the button in time, both players lose a point, countdown is restarted and next question 
   * asked. Once the button is pressed, 
   * "Player One" or "Player Two" will appear on-screen, indicating who pressed the button first
   * and as such, who gets to answer. there will be a short delay and then the question will appear 
   * again along with the timer bar, this time 15 seconds to answer. Under the question  
   * will be 4 possible answer choices, represented by cardinal arrows corresponding to the 
   * D-pad. If the player guesses wrong, they gain no points. if they run out of time, they lose
   * 1 point. The outcome is displayed for 3 seconds, informing the players of the new scores,
  `   * and the countdown for the next question begins. 15 questions, plus one separate "emergency" question
   * in the case of a tie, so there is always a winner. after the 15th (or 16th) question, show player one and player two on left and right side of the screen,respectively, 
   * add something analogous to a drumroll from te buzzer, and a searchlight effect going between the names (maybe just invert colors)
   * land on winner stop drumroll, add confetti-like effect across the winner's side, maybe play a victory tune.
   * Press any button to restart the game.
    */
    
#include <Arduboy2.h>
#include <Tinyfont.h>
Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
#include "func.h"
#include "vars.h"

void setup() {
  arduboy.begin();
  arduboy.clear();
}

void loop() {
  if (!arduboy.nextFrame()) return;
  arduboy.clear();
  gameloop();
  arduboy.display();
}
