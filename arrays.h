
const uint8_t UP[] PROGMEM = {
  8, 8,
0x18,0x1C,0xFE,0xFF,0xFF,0xFE,0x1C,0x18,
 };

const uint8_t RIGHT[] PROGMEM = {
  8, 8,
0x3C,0x3C,0x3C,0xFF,0xFF,0x7E,0x3C,0x18,
 };

const uint8_t DOWN[] PROGMEM = {
  8, 8,
0x18,0x38,0x7F,0xFF,0xFF,0x7F,0x38,0x18,
 };

const uint8_t LEFT[] PROGMEM = {
  8, 8,
0x18,0x3C,0x7E,0xFF,0xFF,0x3C,0x3C,0x3C,
 };



const static char question1[] PROGMEM = {"Dennis is Asshole. \n Why Charlie hate?"};
const static char q1ansUP[] PROGMEM = {"Because Dennis is a\n Bastard Man"}; //true answer
const static char q1ansLEFT[] PROGMEM = {"The 'Incident'"};
const static char q1ansDOWN[] PROGMEM = {"Dennis not good vote \nfor Philadelphia, so didnt"};
const static char q1ansRIGHT[] PROGMEM = {"No resp3ct 4 bird law \ncuz salmonella"};
 

char buffer[70];

const static char question2[] PROGMEM = {"What is the solution\n to the bathroom problem?"}; //5
const static char q2ansUP[] PROGMEM = {"Genderfluid"};
const static char q2ansLEFT[] PROGMEM = {"Gender Neutral"};
const static char q2ansDOWN[] PROGMEM = {"Dick pics & roast beef sandwhiches"};
const static char q2ansRIGHT[] PROGMEM = {"Animal Shithouse"}; //true answer //9

const static char question3[] PROGMEM = {"What should you do if \n you find wet catfood in \n the apartment?"};
const static char q3ansUP[] PROGMEM = {"Nothing. I don't touch YOUR shit. \n You don't touch MY shit."};
const static char q3ansLEFT[] PROGMEM = {"Depends if hungry. Or sleepy.\n"}; //true
const static char q3ansDOWN[] PROGMEM = {"Ask to feed the cat."};
const static char q3ansRIGHT[] PROGMEM ={"Put in mixed drink."};

const static char question4[] PROGMEM ={"#1 Rule of being an \nAss-Kicker:"};
const static char q4ansUP[] PROGMEM = {"An Asskicker must be \npresent everyday."};
const static char q4ansLEFT[] PROGMEM = {"No Women"};
const static char q4ansDOWN[] PROGMEM = {"No Gays"};
const static char q4ansRIGHT[] PROGMEM = {"No Thin Mints"}; //true


const static char question5[] PROGMEM ={"Who killed Maureen Ponderosa?"};
const static char q5ansUP[] PROGMEM = {"Dennis"};
const static char q5ansLEFT[] PROGMEM = {"Bastet"};//true
const static char q5ansDOWN[] PROGMEM = {"Charlie"};
const static char q5ansRIGHT[] PROGMEM = {"Maureen"};


const static char question6[] PROGMEM ={"What was charlie high on \n when he caught a leprechaun?"};
const static char q6ansUP[] PROGMEM = {"Cat Tranquilizers"};
const static char q6ansLEFT[] PROGMEM = {"Gasoline"};
const static char q6ansDOWN[] PROGMEM = {"Paint"};//true
const static char q6ansRIGHT[] PROGMEM = {"LSD"};


const static char question7[] PROGMEM ={"What's the best way \n to deal with things?"};
const static char q7ansUP[] PROGMEM = {"Talk it through."};
const static char q7ansLEFT[] PROGMEM = {"Yell about it."};
const static char q7ansDOWN[] PROGMEM = {"Bring it up casually"};
const static char q7ansRIGHT[] PROGMEM = {"Stuff it down with brown"}; // true


const static char question8[] PROGMEM ={"What was the name of \n Dennis and Dee's unborn triplet?"};
const static char q8ansUP[] PROGMEM = {"Ronnie"};
const static char q8ansLEFT[] PROGMEM = {"Donnie"};//true
const static char q8ansDOWN[] PROGMEM = {"Bonnie"};
const static char q8ansRIGHT[] PROGMEM = {"Lonnie"};


const static char question9[] PROGMEM ={"Which horrible thing did psycho Pete actually do?"};
const static char q9ansUP[] PROGMEM = {"Scream in babies' faces"};//true 
const static char q9ansLEFT[] PROGMEM = {"Kill & eat his family at christmas"};
const static char q9ansDOWN[] PROGMEM = {"Threaten school with arson"};
const static char q9ansRIGHT[] PROGMEM = {"Steal a tour boat"};

const static char question10[] PROGMEM ={"Where's the best place to stash your drugs?"};
const static char q10ansUP[] PROGMEM = {"Paint Can"};
const static char q10ansLEFT[] PROGMEM = {"Sock Drawer"};
const static char q10ansDOWN[] PROGMEM = {"Casaba Melon"};//true
const static char q10ansRIGHT[] PROGMEM = {"Empty Cat Food Tin"};


const static char question11[] PROGMEM ={"What is charlie's 'Bad Place'?"};
const static char q11ansUP[] PROGMEM = {"Basement full of rats"};
const static char q11ansLEFT[] PROGMEM = {"Anywhere with Uncle Jack"};
const static char q11ansDOWN[] PROGMEM = {"A depressive state of mind"};
const static char q11ansRIGHT[] PROGMEM = {"Room to break bottles in"};//true


const static char question12[] PROGMEM ={"According to Frank, what is 'Bird Watching'?"};
const static char q12ansUP[] PROGMEM = {"Waiting for Dee to do something stupid"};
const static char q12ansLEFT[] PROGMEM = {"Looking up women's skirts"};//true
const static char q12ansDOWN[] PROGMEM = {"Waiting for Dee to do something pathetic"};
const static char q12ansRIGHT[] PROGMEM = {"Staring at women's breasts"};


const static char question13[] PROGMEM ={"Who pooped the bed?"};
const static char q13ansUP[] PROGMEM = {"Frank"};//true
const static char q13ansLEFT[] PROGMEM = {"Charlie"};
const static char q13ansDOWN[] PROGMEM = {"Mac"};
const static char q13ansRIGHT[] PROGMEM = {"Dennis"};


const static char question14[] PROGMEM = {"How do you get away from Gail the Snail?"};
const static char q14ansUP[] PROGMEM = {"Smoke bomb"};
const static char q14ansLEFT[] PROGMEM = {"Be more annoying"};
const static char q14ansDOWN[] PROGMEM = {"Salt her"};//true 
const static char q14ansRIGHT[] PROGMEM = {"Pocket sand"};


const static char question15[] PROGMEM ={"Why does Dennnis hate Valentine's day?"};
const static char q15ansUP[] PROGMEM = {"He has no feelings"};
const static char q15ansLEFT[] PROGMEM = {"Too many colors"};
const static char q15ansDOWN[] PROGMEM = {"No one ever gets him anything"};//true
const static char q15ansRIGHT[] PROGMEM = {"Reminds him of failed romances"};

const static char question16[] PROGMEM ={"What are charlie's color rituals/ for sports games?"};
const static char q16ansUP[] PROGMEM = {"Drink brown, eat green, wear yellow"};
const static char q16ansLEFT[] PROGMEM = {"Drink brown, eat yellow, wear green"};
const static char q16ansDOWN[] PROGMEM = {"Drink yellow, eat green, wear brown"};
const static char q16ansRIGHT[] PROGMEM = {"Drink yellow, eat brown, wear green"}; //true


const char *const string_table[] PROGMEM = {
  question1, q1ansUP, q1ansLEFT, q1ansDOWN, q1ansRIGHT,
  question2, q2ansUP, q2ansLEFT, q2ansDOWN, q2ansRIGHT,
  question3, q3ansUP, q3ansLEFT, q3ansDOWN, q3ansRIGHT,
  question4, q4ansUP, q4ansLEFT, q4ansDOWN, q4ansRIGHT,
  question5, q5ansUP, q5ansLEFT, q5ansDOWN, q5ansRIGHT,
  question6, q6ansUP, q6ansLEFT, q6ansDOWN, q6ansRIGHT,
  question7, q7ansUP, q7ansLEFT, q7ansDOWN, q7ansRIGHT,
  question8, q8ansUP, q8ansLEFT, q8ansDOWN, q8ansRIGHT,
  question9, q9ansUP, q9ansLEFT, q9ansDOWN, q9ansRIGHT,
  question10, q10ansUP, q10ansLEFT, q10ansDOWN, q10ansRIGHT,
  question11, q11ansUP, q11ansLEFT, q11ansDOWN, q11ansRIGHT,
  question12, q12ansUP, q12ansLEFT, q12ansDOWN, q12ansRIGHT,
  question13, q13ansUP, q13ansLEFT, q13ansDOWN, q13ansRIGHT,
  question14, q14ansUP, q14ansLEFT, q14ansDOWN, q14ansRIGHT,
  question15, q15ansUP, q15ansLEFT, q15ansDOWN, q15ansRIGHT,
  question16, q16ansUP, q16ansLEFT, q16ansDOWN, q16ansRIGHT 
};
