#pragma once
#include "vars.h"
#include "arrays.h"


void tiebreaker(){
  
}

void wincheck(){
  if (questioncounter == 15 && P1score == P2score){
    tiebreaker();
  }
  if (questioncounter < 15){
    gamestate = 1;
  }
  if ((questioncounter == 15 && P1score > P2score) || (questioncounter == 15 && P1score < P2score)){
    gamestate == 11;
  }
}

void GS2(){
  if (timerbar > 0) {timerbar-=1;}
  arduboy.setCursor(0, 0);
  if (questioncounter ==1) {
   arduboy.print(question1); 
  }
  else if (questioncounter == 2) {
    arduboy.print(question2);
  }
  if (arduboy.pressed(LEFT_BUTTON)){
    gamestate++;
  }
  if (arduboy.pressed(B_BUTTON)){
    gamestate = 7;
  }
  
  arduboy.drawRect(0, 60, timerbar, 4);
  if (timerbar == 0){
    P1score -=1;
    P2score -=1;
    questioncounter+=1;
    arduboy.clear();
    gamestate = 1;
  }
}

void GS4(){
  arduboy.setCursor(0,0);
  if (questioncounter == 1){
    arduboy.print(question1);
    arduboy.setCursor(10, 8);
    arduboy.print(q1ansUP);
    arduboy.setCursor(10, 16);
    arduboy.print(q1ansLEFT);
    arduboy.setCursor(10, 24);
    arduboy.print(q1ansDOWN);
    arduboy.setCursor(10, 32);
    arduboy.print(q1ansRIGHT);
    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.justPressed(UP_BUTTON)){
      P1correct = true;
      gamestate = 6;
    }
    if (arduboy.justPressed(LEFT_BUTTON)){
      P1correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(DOWN_BUTTON)){
      P1correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(RIGHT_BUTTON)){
      P1correct = false;
      gamestate = 6;
    }
  }
  
  if (questioncounter == 2){
    arduboy.print(question2);
    arduboy.setCursor(10, 8);
    arduboy.print(q2ansUP);
    arduboy.setCursor(10, 16);
    arduboy.print(q2ansLEFT);
    arduboy.setCursor(10, 24);
    arduboy.print(q2ansDOWN);
    arduboy.setCursor(10, 32);
    arduboy.print(q2ansRIGHT);
    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.justPressed(UP_BUTTON)){
      P1correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(LEFT_BUTTON)){
      P1correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(DOWN_BUTTON)){
      P1correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(RIGHT_BUTTON)){
      P1correct = true;
      gamestate = 6;
    }
  }

  timerbar--;
  if (timerbar == 0){
    gamestate = 5;
  }
}

void GS8(){
  arduboy.setCursor(0,0);
  if (questioncounter == 1){
    arduboy.print(question1);
    arduboy.setCursor(10, 8);
    arduboy.print(q1ansUP);
    arduboy.setCursor(10, 16);
    arduboy.print(q1ansLEFT);
    arduboy.setCursor(10, 24);
    arduboy.print(q1ansDOWN);
    arduboy.setCursor(10, 32);
    arduboy.print(q1ansRIGHT);
    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.justPressed(UP_BUTTON)){
      P2correct = true;
      gamestate = 6;
    }
    if (arduboy.justPressed(LEFT_BUTTON)){
      P2correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(DOWN_BUTTON)){
      P2correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(RIGHT_BUTTON)){
      P2correct = false;
      gamestate = 6;
    }
  }
  
  if (questioncounter == 2){
    arduboy.print(question2);
    arduboy.setCursor(10, 8);
    arduboy.print(q2ansUP);
    arduboy.setCursor(10, 16);
    arduboy.print(q2ansLEFT);
    arduboy.setCursor(10, 24);
    arduboy.print(q2ansDOWN);
    arduboy.setCursor(10, 32);
    arduboy.print(q2ansRIGHT);
    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.justPressed(UP_BUTTON)){
      P2correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(LEFT_BUTTON)){
      P2correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(DOWN_BUTTON)){
      P2correct = false;
      gamestate = 6;
    }
    if (arduboy.justPressed(RIGHT_BUTTON)){
      P2correct = true;
      gamestate = 6;
    }
  }

  timerbar--;
  if (timerbar == 0){
    gamestate = 9;
  }
}
void GS10(){
  if (P2correct == true){
    arduboy.setCursor(WIDTH/3, HEIGHT/2);
    arduboy.print("Correct! +1 pt");
    P2score +=1;
    questioncounter+=1;
    delay(3000);
    wincheck();
  }
  else {
    arduboy.setCursor(WIDTH/3, HEIGHT/2);
    arduboy.print("Wrong! Better luck next time.");
    questioncounter+=1;
    delay(3000);
    wincheck();
  }
}
void GS6(){
  if (P1correct == true){
    arduboy.setCursor(WIDTH/3, HEIGHT/2);
    arduboy.print("Correct! +1 pt");
    P1score +=1;
    questioncounter+=1;
    delay(3000);
    wincheck();
  }
  else {
    arduboy.setCursor(WIDTH/3, HEIGHT/2);
    arduboy.print("Wrong! Better luck next time.");
    questioncounter+=1;
    delay(3000);
    wincheck();
  }
}

void reset(){
  
}



void gameloop(){
  switch (gamestate) {

      case 0:
      //title screen
      arduboy.setCursor(0,0);
      arduboy.print("Trivia");
      if (arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(B_BUTTON)) {
        gamestate++;
      }
      break;

      case 1:
      //countdown
      timerbar = 10000;
      delay(3000);
      gamestate++;
      break;


      case 2:
      //question screen both players
      GS2();
      break;

      case 3:
      //player 1
      //informative screen, just print & delay
      arduboy.setCursor(0, 0);
      arduboy.print("Player ONE get ready!");
      timerbar = 15000;
      delay(3000);
      gamestate = 4;
      break;

      case 4:
      //P1 Question/answer screen
      GS4();
      break;

      case 5:
      //player 1 time out screen, -1 pts
      arduboy.setCursor(0,0);
      arduboy.print("Out of time! -1 pt");
      P1score -=1;
      delay(3000);
      questioncounter+=1;
      wincheck();
      break;

      case 6:
      //p1 outcome screen
      GS6();
      break;

      case 7:
      //player 2
      //informative screen, just print & delay
      arduboy.setCursor(0, 0);
      arduboy.print("Player TWO get ready!");
      timerbar = 15000;
      delay(3000);
      gamestate = 8;
      break;

      case 8:
      //player 2 question/answer screen
      GS8();
      break;

      case 9:
      //player 2 timeout screen -1pt
      arduboy.setCursor(0,0);
      arduboy.print("Out of time! -1 pt");
      P2score -=1;
      delay(3000);
      questioncounter+=1;
      wincheck();
      break;

      case 10:
      //player 2 outcome screen
      GS10();
      break;
      
      case 11: 
      
      //win screen
      break;
  }
}
