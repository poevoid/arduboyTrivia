#pragma once


bool P1correct = false;
bool P2correct = false;
bool tiebreaker = false;

enum QA : uint8_t {
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
  Question3,//10
  q3UP,
  q3LEFT,
  q3DOWN,
  q3RIGHT,
  Question4, //15
  q4UP,
  q4LEFT,
  q4DOWN,
  q4RIGHT,
  Question5,//20
  q5UP,
  q5LEFT,
  q5DOWN,
  q5RIGHT,
  Question6,//25
  q6UP,
  q6LEFT,
  q6DOWN,
  q6RIGHT,
  Question7,//30
  q7UP,
  q7LEFT,
  q7DOWN,
  q7RIGHT,
  Question8,//35
  q8UP,
  q8LEFT,
  q8DOWN,
  q8RIGHT,
  Question9,//40
  q9UP,
  q9LEFT,
  q9DOWN,
  q9RIGHT,
  Question10,//45
  q10UP,
  q10LEFT,
  q10DOWN,
  q10RIGHT,
  Question11,//50
  q11UP,
  q11LEFT,
  q11DOWN,
  q11RIGHT,
  Question12,//55
  q12UP,
  q12LEFT,
  q12DOWN,
  q12RIGHT,
  Question13,//60
  q13UP,
  q13LEFT,
  q13DOWN,
  q13RIGHT,
  Question14,//65
  q14UP,
  q14LEFT,
  q14DOWN,
  q14RIGHT,
  Question15,//70
  q15UP,
  q15LEFT,
  q15DOWN,
  q15RIGHT,
  Question16,//75
  q16UP,
  q16LEFT,
  q16DOWN,
  q16RIGHT,//79
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
