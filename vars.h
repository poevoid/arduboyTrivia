#pragma once

bool P1correct = false;
bool P2correct = false;

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

char question1[] = "Dennis is Asshole. \n Why Charlie hate?";
char q1ansUP[] = "Because Dennis is a Bastard Man"; //true answer
char q1ansLEFT[] = "The 'Incident'";
char q1ansDOWN[] = "Dennis not good vote for Philadelphia, so didnt";
char q1ansRIGHT[] = "No resp3ct 4 bird law, salmonella";
 

char question2[] = "What is the solution to the bathroom problem?";
char q2ansUP[] = "Genderfluid";
char q2ansLEFT[] = "Gender Neutral";
char q2ansDOWN[] = "Dick pics & roast beef sandwhiches";
char q2ansRIGHT[] = "Animal Shithouse"; //true answer
