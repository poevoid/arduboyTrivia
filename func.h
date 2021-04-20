#pragma once
#include "vars.h"
#include "arrays.h"

GameState gamestate = GameState::Title;

QA stringbuff = QA::Question1;

void tiebreaker() {

}

void wincheck() {
  if (questioncounter == 15 && P1score == P2score) {
    tiebreaker();
  }
  if (questioncounter < 15) {
    timerbar = 100;
    gamestate = GameState::Countdown;
  }
  if ((questioncounter == 15 && P1score > P2score) || (questioncounter == 15 && P1score < P2score)) {
    gamestate = GameState::WinScreen;
  }
}

void questionBothPlayers() {
  if (timerbar > 0) {
    timerbar--;
  }
  tinyfont.setCursor(0, 0);
  if (questioncounter == 1) {
    stringbuff = QA::Question1;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  else if (questioncounter == 2) {
    stringbuff = QA::Question2;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (arduboy.pressed(LEFT_BUTTON)) {
    timerbar = 200;
    gamestate = GameState::PlayerOneReady;
  }
  if (arduboy.pressed(B_BUTTON)) {
    timerbar = 200;
    gamestate = GameState::PlayerTwoReady;
  }

  arduboy.drawRect(0, 60, timerbar, 4);
  if (timerbar == 0) {
    P1score -= 1;
    P2score -= 1;
    questioncounter += 1;
    arduboy.clear();
    gamestate = GameState::Countdown;
  }
}

void questionPlayerOne() {
  tinyfont.setCursor(116, 0);
  tinyfont.print(timerbar/10);
  tinyfont.setCursor(0, 0);
  
  if (questioncounter == 1) {
    stringbuff = QA::Question1;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q1UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q1LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q1DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 40);
    tinyfont.print(buffer);

    stringbuff = QA::q1RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 40, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P1correct = true;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
  }

  if (questioncounter == 2) {


    stringbuff = QA::Question2;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q2UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 8);
    tinyfont.print(buffer);


    stringbuff = QA::q2LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q2DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 24);
    tinyfont.print(buffer);


    stringbuff = QA::q2RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P1correct = true;
      gamestate = GameState::PlayerOneOutcome;
    }
  }

  timerbar--;
  if (timerbar == 0) {
    timerbar = 300;
    gamestate = GameState::PlayerOneTimeOut;
  }
}

void questionPlayerTwo() {
  tinyfont.setCursor(0, 0);
  arduboy.drawRect(0, 60, timerbar, 4);
  if (questioncounter == 1) {

    stringbuff = QA::Question1;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q1UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 8);
    tinyfont.print(buffer);


    stringbuff = QA::q1LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);

    stringbuff = QA::q1DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 24);
    tinyfont.print(buffer);

    stringbuff = QA::q1RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = true;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
  }
  else if (questioncounter == 2) {

    stringbuff = QA::Question2;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q2UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 8);
    tinyfont.print(buffer);


    stringbuff = QA::q2LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);

    stringbuff = QA::q2DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 24);
    tinyfont.print(buffer);

    stringbuff = QA::q2RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 8, UP, 0);
    Sprites::drawOverwrite(0, 16, LEFT, 0);
    Sprites::drawOverwrite(0, 24, DOWN, 0);
    Sprites::drawOverwrite(0, 32, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P2correct = true;
      gamestate = GameState::PlayerTwoOutcome;
    }
  }

  timerbar--;
  if (timerbar == 0) {
    timerbar = 300;
    gamestate = GameState::PlayerTwoTimeOut;
  }
}
void playerTwoOutcome() {
  if (P2correct == true) {
    tinyfont.setCursor(WIDTH / 3, HEIGHT / 2);
    tinyfont.print(F("Correct! \n +1 pt"));
    P2score += 1;
    questioncounter += 1;
    arduboy.display();
    delay(3000);
    wincheck();
  }
  else {
    tinyfont.setCursor(WIDTH / 3, HEIGHT / 2);
    tinyfont.print(F("Wrong! \nBetter luck next time."));
    questioncounter += 1;
    arduboy.display();
    delay(3000);
    wincheck();
  }
}

void playerOneOutcome() {
  if (P1correct == true) {
    tinyfont.setCursor(WIDTH / 3, HEIGHT / 2);
    tinyfont.print(F("Correct! \n+1 pt"));
    P1score += 1;
    questioncounter += 1;
    arduboy.display();
    delay(5000);
    wincheck();
  }
  else {
    tinyfont.setCursor(WIDTH / 3, HEIGHT / 2);
    tinyfont.print(F("Wrong! \n Better luck next time."));
    questioncounter += 1;
    arduboy.display();
    delay(5000);
    wincheck();
  }
}

void reset() {

}



void gameloop() {
  switch (gamestate) {

    case GameState::Title:
      //title screen
      tinyfont.setCursor(0, 0);
      tinyfont.print("Trivia");
      arduboy.pollButtons();
      if (arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(B_BUTTON)) {
        timerbar = 100;
        gamestate = GameState::Countdown;
      }
      break;

    case GameState::Countdown:
      //countdown
      timerbar--;
      tinyfont.setCursor(0,0);
      if (timerbar > 66) {
        tinyfont.print(F("3"));
      }
      if (timerbar > 33 && timerbar < 66) {
        tinyfont.print(F("2"));
      }
      if (timerbar > 0 && timerbar < 33) {
        tinyfont.print(F("1"));
      }
      if (timerbar == 0) {
        timerbar = 300;
        gamestate = GameState::QuestionBoth;
      }
      break;


    case GameState::QuestionBoth:
      //question screen both players
      questionBothPlayers();
      break;

    case GameState::PlayerOneReady:
      //player 1
      //informative screen, just print & delay
      timerbar--;
      tinyfont.setCursor(0, 0);
      tinyfont.print(F("Player ONE get ready!"));

      if (timerbar == 0) {
        timerbar = 1000;
        gamestate = GameState::PlayerOneQA;
      };
      break;

    case GameState::PlayerOneQA:
      //P1 Question/answer screen
      questionPlayerOne();
      break;

    case GameState::PlayerOneTimeOut:
      //player 1 time out screen, -1 pts
      tinyfont.setCursor(0, 0);
      tinyfont.print(F("Out of time! -1 pt"));
      P1score -= 1;
      timerbar--;
      if (timerbar = 0) {
        questioncounter += 1;
        wincheck();
      }

      break;

    case GameState::PlayerOneOutcome:
      //p1 outcome screen
      playerOneOutcome();
      break;

    case GameState::PlayerTwoReady:
      //player 2
      //informative screen, just print & delay
      tinyfont.setCursor(0, 0);
      tinyfont.print(F("Player TWO get ready!"));
      timerbar--;
      if (timerbar == 0) {
        timerbar = 1000;
        gamestate = GameState::PlayerTwoQA;
      }
      break;

    case GameState::PlayerTwoQA:
      //player 2 question/answer screen
      questionPlayerTwo();
      break;

    case GameState::PlayerTwoTimeOut:
      //player 2 timeout screen -1pt
      tinyfont.setCursor(0, 0);
      tinyfont.print(F("Out of time! -1 pt"));
      P2score -= 1;
      timerbar--;
      if (timerbar == 0) {
        questioncounter += 1;
        wincheck();
      }
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
