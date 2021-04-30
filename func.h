#pragma once
#include "vars.h"
#include "arrays.h"

GameState gamestate = GameState::Title;

QA stringbuff = QA::Question1;


void wincheck() {
  if (questioncounter == 15 && P1score == P2score) {
    tiebreaker = true;
  }
  if (questioncounter < 15) {
    timerbar = 100;
    tiebreaker = false;
    gamestate = GameState::Countdown;
  }
  if ((questioncounter == 15 && P1score > P2score) || (questioncounter == 15 && P1score < P2score || questioncounter>15)) {
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
  if (questioncounter == 2) {
    stringbuff = QA::Question2;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 3) {
    stringbuff = QA::Question3;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 4) {
    stringbuff = QA::Question4;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 5) {
    stringbuff = QA::Question5;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 6) {
    stringbuff = QA::Question6;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 7) {
    stringbuff = QA::Question7;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 8) {
    stringbuff = QA::Question8;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 9) {
    stringbuff = QA::Question9;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 10) {
    stringbuff = QA::Question10;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 11) {
    stringbuff = QA::Question11;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 12) {
    stringbuff = QA::Question12;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 13) {
    stringbuff = QA::Question13;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 14) {
    stringbuff = QA::Question14;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 15) {
    stringbuff = QA::Question15;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  if (questioncounter == 16 && tiebreaker == true) {
    stringbuff = QA::Question16;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);
  }
  else if (questioncounter == 16 && tiebreaker == false) {
    wincheck();
  }


  if (arduboy.pressed(LEFT_BUTTON)) {
    timerbar = 200;
    gamestate = GameState::PlayerOneReady;
  }
  if (arduboy.pressed(B_BUTTON)) {
    timerbar = 200;
    gamestate = GameState::PlayerTwoReady;
  }
  arduboy.setCursor(0, 55);
  arduboy.print(timerbar / 10);

  if (timerbar == 0) {
    P1score -= 1;
    P2score -= 1;
    questioncounter += 1;
    arduboy.clear();
    arduboy.print(F("Out of time!"));
    arduboy.display();
    delay(3000);
    timerbar = 100;
    gamestate = GameState::Countdown;
  }
}

void questionPlayerOne() {
  tinyfont.setCursor(116, 0);
  tinyfont.print(timerbar / 10);
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
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q1RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
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
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q2LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q2DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q2RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 3) {


    stringbuff = QA::Question3;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q3UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q3LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q3DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q3RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P1correct = true;
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
  if (questioncounter == 4) {


    stringbuff = QA::Question4;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q4UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q4LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q4DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q4RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 5) {


    stringbuff = QA::Question5;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q5UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q5LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q5DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q5RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P1correct = true;
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
  if (questioncounter == 6) {


    stringbuff = QA::Question6;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q6UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q6LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q6DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q6RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P1correct = true;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
  }
  if (questioncounter == 7) {


    stringbuff = QA::Question7;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q7UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q7LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q7DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q7RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 8) {


    stringbuff = QA::Question8;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q8UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q8LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q8DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q8RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P1correct = true;
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
  if (questioncounter == 9) {


    stringbuff = QA::Question9;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q9UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q9LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q9DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q9RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
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
  if (questioncounter == 10) {


    stringbuff = QA::Question10;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q10UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q10LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q10DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q10RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P1correct = true;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
  }
  if (questioncounter == 11) {
    stringbuff = QA::Question11;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q11UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q11LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q11DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q11RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 12) {
    stringbuff = QA::Question12;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q12UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q12LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q12DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q12RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P1correct = true;
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
  if (questioncounter == 13) {
    stringbuff = QA::Question13;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q13UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q13LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q13DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q13RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
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
  if (questioncounter == 14) {
    stringbuff = QA::Question14;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q14UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q14LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q14DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q14RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 15) {
    stringbuff = QA::Question15;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q15UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q15LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q15DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q15RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P1correct = true;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P1correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
  }
  if (questioncounter == 16) {
    stringbuff = QA::Question16;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q16UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q16LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q16DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q16RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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

  if (timerbar > 0) {
    timerbar--;
  }
  if (timerbar == 0) {
    timerbar = 100;
    gamestate = GameState::PlayerOneTimeOut;
  }
}

void questionPlayerTwo() {
  tinyfont.setCursor(116, 0);
  tinyfont.print(timerbar / 10);
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
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 2) {

    stringbuff = QA::Question2;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q2UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q2LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q2DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q2RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 3) {


    stringbuff = QA::Question3;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q3UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q3LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);


    stringbuff = QA::q3DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);


    stringbuff = QA::q3RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = true;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerOneOutcome;
    }
  }
  if (questioncounter == 4) {

    stringbuff = QA::Question4;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q4UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q4LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q4DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q4RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 5) {

    stringbuff = QA::Question5;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q5UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q5LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q5DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q5RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = true;
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
  if (questioncounter == 6) {

    stringbuff = QA::Question6;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q6UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q6LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q6DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q6RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P2correct = true;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
  }
  if (questioncounter == 7) {

    stringbuff = QA::Question7;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q7UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q7LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q7DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q7RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 8) {

    stringbuff = QA::Question8;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q8UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q8LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q8DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q8RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = true;
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
  if (questioncounter == 9) {

    stringbuff = QA::Question9;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q9UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q9LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q9DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q9RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 10) {

    stringbuff = QA::Question10;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q10UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q10LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q10DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q10RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P2correct = true;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
  }
  if (questioncounter == 11) {

    stringbuff = QA::Question11;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q11UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q11LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q11DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q11RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 12) {

    stringbuff = QA::Question12;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q12UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q12LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q12DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q12RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = true;
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
  if (questioncounter == 13) {

    stringbuff = QA::Question13;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q13UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q13LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q13DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q13RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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
  if (questioncounter == 14) {

    stringbuff = QA::Question14;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q14UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q14LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q14DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q14RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P2correct = true;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
  }
  if (questioncounter == 15) {

    stringbuff = QA::Question15;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q15UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q15LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q15DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q15RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
    if (arduboy.pressed(UP_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      P2correct = true;
      gamestate = GameState::PlayerTwoOutcome;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      P2correct = false;
      gamestate = GameState::PlayerTwoOutcome;
    }
  }
  if (questioncounter == 16) {

    stringbuff = QA::Question16;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.print(buffer);


    stringbuff = QA::q16UP;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 16);
    tinyfont.print(buffer);


    stringbuff = QA::q16LEFT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 32);
    tinyfont.print(buffer);

    stringbuff = QA::q16DOWN;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 45);
    tinyfont.print(buffer);

    stringbuff = QA::q16RIGHT;
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[stringbuff])));
    tinyfont.setCursor(10, 55);
    tinyfont.print(buffer);

    Sprites::drawOverwrite(0, 16, UP, 0);
    Sprites::drawOverwrite(0, 32, LEFT, 0);
    Sprites::drawOverwrite(0, 45, DOWN, 0);
    Sprites::drawOverwrite(0, 55, RIGHT, 0);
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

  //qa p2

  if (timerbar > 0) {
    timerbar--;
  }
  if (timerbar == 0) {
    timerbar = 100;
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
  else if (P2correct == false && questioncounter < 16) {
    tinyfont.setCursor(WIDTH / 3, HEIGHT / 2);
    tinyfont.print(F("Wrong! \nBetter luck \n next time."));
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
  else if (P1correct == false && questioncounter < 16) {
    tinyfont.setCursor(WIDTH / 4, HEIGHT / 2);
    tinyfont.print(F("Wrong! \n Better luck\n next time."));
    questioncounter += 1;
    arduboy.display();
    delay(5000);
    wincheck();
  }
}

void reset() {

}
void animatetitle() {
  if (arduboy.everyXFrames(30)) {
    if (currentframe < 1) {
      ++currentframe;
    }
    else {
      currentframe = firstframe;
    }
  }
}


void gameloop() {
  switch (gamestate) {

    case GameState::Title:
      //title screen
      arduboy.setCursor(3, 0);
      arduboy.print(F("FrankenMacCharDeeDen"));
      arduboy.pollButtons();
      arduboy.setCursor(WIDTH/2-11, HEIGHT/2-11);
      arduboy.print(F("MIND"));
      arduboy.drawCircle(WIDTH/2, HEIGHT-17, 16);
      tinyfont.setCursor(WIDTH/2-11, HEIGHT-24);
      tinyfont.print(F("LEVEL"));
      arduboy.setCursor(WIDTH/2-2, HEIGHT-17);
      arduboy.print(F("1"));
      tinyfont.setCursor(0, 32);
      tinyfont.print(F("Player1 \n Press:"));
      tinyfont.setCursor(WIDTH-(WIDTH/3), 32);
      tinyfont.print(F("Player2 \n Press:"));
      Sprites::drawOverwrite(14, 45, LEFTTITLE, currentframe);
      Sprites::drawOverwrite(WIDTH-28, 45, BTITLE, currentframe);
      animatetitle();



      
      if (arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(B_BUTTON)) {
        timerbar = 100;
        gamestate = GameState::Countdown;
      }
      break;

    case GameState::Countdown:
      //countdown
      if (timerbar > 0) {
        timerbar--;
      }
      arduboy.setCursor(WIDTH / 2 - 4, HEIGHT / 2 - 4);
      if (timerbar > 66) {
        arduboy.print(F("3"));
      }
      if (timerbar > 33 && timerbar < 66) {
        arduboy.print(F("2"));
      }
      if (timerbar > 0 && timerbar < 33) {
        arduboy.print(F("1"));
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
      arduboy.setCursor(0, 0);
      arduboy.print(F("Out of time! P1 -1 pt"));
      //arduboy.setCursor(60, 5);
      // arduboy.print(timerbar); //dev
      P1score -= 1;
      if (timerbar > 0) {
        timerbar--;
      }
      if (timerbar == 0) {
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
      if (timerbar > 0) {
        timerbar--;
      }
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
      arduboy.setCursor(0, 0);
      arduboy.print(F("Out of time! P2 -1 pt\n"));
      //tinyfont.print(timerbar); //dev purposes
      P2score -= 1;
      if (timerbar > 0) {
        timerbar--;
      }
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
      if (P1score > P2score) {
        arduboy.print(F("Player One \nwins the game!"));
      }
      else {
        arduboy.print(F("Player Two \nwins the game!"));
      }
      break;
  }
}
