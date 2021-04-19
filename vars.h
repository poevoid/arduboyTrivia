#pragma once


bool P1correct = false;
bool P2correct = false;

enum QA: uint8_t {
  Question1,//0
  q1UP,
  q1LEFT,
  q1DOWN,
  q1RIGHT,
  Question2, //5
  q2UP,
  q2LEFT,
  q2DOWN,
  q2RIGHT,
};

enum class GameState : uint8_t {
  Title, //0
  Countdown,
  QuestionBoth,
  PlayerOneReady, 
  PlayerOneQA, //4, Question/Answer
  PlayerOneTimeOut,
  PlayerOneOutcome,
  PlayerTwoReady,
  PlayerTwoQA, //8
  PlayerTwoTimeOut,
  PlayerTwoOutcome,
  WinScreen,
}; 

int P1score=0;
int P2score=0;
int timerbar = 10000;
int questioncounter = 1;
