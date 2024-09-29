extern char HEX_VALUES[];
extern float A0;
extern float A1; 
extern float A2; 
extern float A3; 
extern float A4; 
extern float A5; 
extern float A6; 
extern float A7;

extern float r; 
extern char msg_encoded[101];
extern char msg_decoded[51];

int hex_to_int(char hex_char);
int hex_to_ascii(char high, char low);
int validation(int x, int b);
void decode_message(char* msg_encoded, int b);