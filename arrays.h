
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
const static char q1ansUP[] PROGMEM = {"Because Dennis is a Bastard Man"}; //true answer
const static char q1ansLEFT[] PROGMEM = {"The 'Incident'"};
const static char q1ansDOWN[] PROGMEM = {"Dennis not good vote for Philadelphia, so didnt"};
const static char q1ansRIGHT[] PROGMEM = {"No resp3ct 4 bird law, salmonella"};
 

char buffer[55];

const static char question2[] PROGMEM = {"What is the solution to the bathroom problem?"}; //5
const static char q2ansUP[] PROGMEM = {"Genderfluid"};
const static char q2ansLEFT[] PROGMEM = {"Gender Neutral"};
const static char q2ansDOWN[] PROGMEM = {"Dick pics & roast beef sandwhiches"};
const static char q2ansRIGHT[] PROGMEM = {"Animal Shithouse"}; //true answer //9

const char *const string_table[] PROGMEM = {question1, q1ansUP, q1ansLEFT, q1ansDOWN, q1ansRIGHT, question2, q2ansUP, q2ansLEFT, q2ansDOWN, q2ansRIGHT};
