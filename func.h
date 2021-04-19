#pragma once
#include "vars.h"
#include "arrays.h"

GameState gamestate = GameState::Title;

QA stringbuff = QA::Question1;

void tiebreaker(){
  
}

void wincheck(){
  if (questioncounter == 15 && P1score == P2score){
    tiebreaker();
  }
  if (questioncounter < 15){
    gamestate = GameState::Countdown;
  }
  if ((questioncounter == 15 && P1score > P2score) || (questioncounter == 15 && P1score < P2score)){
    gamestate = GameState::WinScreen;
  }
}

void questionBothPlayers(){
  if (timerbar > 0) {timerbar-=1;}
  arduboy.setCursor(0, 0);
  if (questioncounter ==1) {
    stringbuff = QA::Question1;
   strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
   arduboy.print(buffer); 
  }
  else if (questioncounter == 2) {
    stringbuff=QA::Question2;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.print(buffer);
  }
  if (arduboy.pressed(LEFT_BUTTON)){
    gamestate = GameState::PlayerOneReady;
  }
  if (arduboy.pressed(B_BUTTON)){
    gamestate = GameState::PlayerTwoReady;
  }
  
  arduboy.drawRect(0, 60, timerbar, 4);
  if (timerbar == 0){
    P1score -=1;
    P2score -=1;
    questioncounter+=1;
    arduboy.clear();
    gamestate = GameState::Countdown;
  }
}

void questionPlayerOne(){
  arduboy.setCursor(0,0);
  if (questioncounter == 1){
    
    stringbuff=QA::Question1;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.print(buffer);

    
    stringbuff=QA::q1UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 8);
    arduboy.print(buffer);

    
    stringbuff=QA::q1LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 16);
    arduboy.print(buffer);

    stringbuff=QA::q1DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 24);
    arduboy.print(buffer);

    stringbuff=QA::q1RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 32);
    arduboy.print(buffer);
    
    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.justPressed(UP_BUTTON)){
      P1correct = true;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.justPressed(LEFT_BUTTON)){
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.justPressed(DOWN_BUTTON)){
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.justPressed(RIGHT_BUTTON)){
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
  }
  
  if (questioncounter == 2){

    
    stringbuff=QA::Question2;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.print(buffer);

    
    stringbuff=QA::q2UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 8);
    arduboy.print(buffer);

    
    stringbuff=QA::q2LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 16);
    arduboy.print(buffer);
    
    
    stringbuff=QA::q2DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 24);
    arduboy.print(buffer);

    
    stringbuff=QA::q2RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 32);
    arduboy.print(buffer);
    
    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.justPressed(UP_BUTTON)){
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.justPressed(LEFT_BUTTON)){
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.justPressed(DOWN_BUTTON)){
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.justPressed(RIGHT_BUTTON)){
      P1correct = true;
      gamestate = GameState::PlayerOneOutcome;
    }
  }

  timerbar--;
  if (timerbar == 0){
    gamestate = GameState::PlayerOneTimeOut;
  }
}

void questionPlayerTwo(){
  arduboy.setCursor(0,0);
  if (questioncounter == 1){
    
    stringbuff=QA::Question1;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.print(buffer);

    
    stringbuff=QA::q1UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 8);
    arduboy.print(buffer);

    
    stringbuff=QA::q1LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 16);
    arduboy.print(buffer);

    stringbuff=QA::q1DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 24);
    arduboy.print(buffer);

    stringbuff=QA::q1RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 32);
    arduboy.print(buffer);
    
    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.justPressed(UP_BUTTON)){
      P2correct = true;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.justPressed(LEFT_BUTTON)){
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.justPressed(DOWN_BUTTON)){
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.justPressed(RIGHT_BUTTON)){
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
  }
  else if (questioncounter == 2){
    
    stringbuff=QA::Question2;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.print(buffer);

    
    stringbuff=QA::q2UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 8);
    arduboy.print(buffer);

    
    stringbuff=QA::q2LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 16);
    arduboy.print(buffer);

    stringbuff=QA::q2DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 24);
    arduboy.print(buffer);

    stringbuff=QA::q2RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    arduboy.setCursor(10, 32);
    arduboy.print(buffer);
    
    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.justPressed(UP_BUTTON)){
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.justPressed(LEFT_BUTTON)){
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.justPressed(DOWN_BUTTON)){
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.justPressed(RIGHT_BUTTON)){
      P2correct = true;
      gamestate = GameState::PlayerTwoOutcome;
    }
  }

  timerbar--;
  if (timerbar == 0){
    gamestate = GameState::PlayerTwoTimeOut;
  }
}
void playerTwoOutcome(){
  if (P2correct == true){
    arduboy.setCursor(WIDTH/3, HEIGHT/2);
    arduboy.print(F("Correct! +1 pt"));
    P2score +=1;
    questioncounter+=1;
    delay(3000);
    wincheck();
  }
  else {
    arduboy.setCursor(WIDTH/3, HEIGHT/2);
    arduboy.print(F("Wrong! Better luck next time."));
    questioncounter+=1;
    delay(3000);
    wincheck();
  }
}

void playerOneOutcome(){
  if (P1correct == true){
    arduboy.setCursor(WIDTH/3, HEIGHT/2);
    arduboy.print(F("Correct! +1 pt"));
    P1score +=1;
    questioncounter+=1;
    delay(3000);
    wincheck();
  }
  else {
    arduboy.setCursor(WIDTH/3, HEIGHT/2);
    arduboy.print(F("Wrong! Better luck next time."));
    questioncounter+=1;
    delay(3000);
    wincheck();
  }
}

void reset(){
  
}



void gameloop(){
  switch (gamestate) {

      case GameState::Title:
      //title screen
      arduboy.setCursor(0,0);
      arduboy.print(F("Trivia"));
      if (arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(B_BUTTON)) {
        gamestate = GameState::Countdown;
      }
      break;

      case GameState::Countdown:
      //countdown
      timerbar = 10000;
      delay(3000);
      gamestate = GameState::QuestionBoth;
      break;


      case GameState::QuestionBoth:
      //question screen both players
      questionBothPlayers();
      break;

      case GameState::PlayerOneReady:
      //player 1
      //informative screen, just print & delay
      arduboy.setCursor(0, 0);
      arduboy.print(F("Player ONE get ready!"));
      timerbar = 15000;
      delay(3000);
      gamestate = GameState::PlayerOneQA;
      break;

      case GameState::PlayerOneQA:
      //P1 Question/answer screen
      questionPlayerOne();
      break;

      case GameState::PlayerOneTimeOut:
      //player 1 time out screen, -1 pts
      arduboy.setCursor(0,0);
      arduboy.print(F("Out of time! -1 pt"));
      P1score -=1;
      delay(3000);
      questioncounter+=1;
      wincheck();
      break;

      case GameState::PlayerOneOutcome:
      //p1 outcome screen
      playerOneOutcome();
      break;

      case GameState::PlayerTwoReady:
      //player 2
      //informative screen, just print & delay
      arduboy.setCursor(0, 0);
      arduboy.print(F("Player TWO get ready!"));
      timerbar = 15000;
      delay(3000);
      gamestate = GameState::PlayerTwoQA;
      break;

      case GameState::PlayerTwoQA:
      //player 2 question/answer screen
      questionPlayerTwo();
      break;

      case GameState::PlayerTwoTimeOut:
      //player 2 timeout screen -1pt
      arduboy.setCursor(0,0);
      arduboy.print(F("Out of time! -1 pt"));
      P2score -=1;
      delay(3000);
      questioncounter+=1;
      wincheck();
      break;

      case GameState::PlayerTwoOutcome:
      //player 2 outcome screen
      playerTwoOutcome();
      break;
      
      case GameState::WinScreen: 
      //win screen
      break;
  }
}
