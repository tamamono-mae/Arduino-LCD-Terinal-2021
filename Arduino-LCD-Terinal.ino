#define PhyPortbit7 11
#define PhyPortbit6 10
#define PhyPortbit5 9
#define PhyPortbit4 8
#define PhyPortbit3 7
#define PhyPortbit2 6
#define PhyPortbit1 5
#define PhyPortbit0 4
#define D_I 2
#define EN_pin 3
#define ChipSlectL 12
#define ChipSlectR 13
#define CommitDelay 0.5

uint8_t cursorX = 4, cursorY = 0, DispSL = 0, VirtualPort = 0; // X max = 59, Y max = 7
bool CurrentChip = 0, IsBottomLine = 0, IsTopLine = 1, IsFirstChar = 1, IsLastestChar = 0;

uint8_t BitmapFont[] = {
	//ASCII table - 32
	0x00, 0x00, 0x00, 0x00, 0x00, 	//Space
	0x00, 0x00, 0x5F, 0x00, 0x00, 	//!
	0x00, 0x07, 0x00, 0x07, 0x00, 	//"
	0x14, 0x7F, 0x14, 0x7F, 0x14,	//#
	0x24, 0x2A, 0x7F, 0x2A, 0x12,	//$
	0x23, 0x13, 0x08, 0x64, 0x62,	//%
	0x36, 0x49, 0x55, 0x22, 0x50,	//&
	0x00, 0x00, 0x07, 0x00, 0x00, 	//'
	0x00, 0x1C, 0x22, 0x41, 0x00,	//(
	0x00, 0x41, 0x22, 0x1C, 0x00,	//)
	0x14, 0x08, 0x3E, 0x08, 0x14,	//*
	0x08, 0x08, 0x3E, 0x08, 0x08,	//+
	0x00, 0x50, 0x30, 0x00, 0x00,	//,
	0x08, 0x08, 0x08, 0x08, 0x08,	//-
	0x00, 0x60, 0x60, 0x00, 0x00,	//.
	0x20, 0x10, 0x08, 0x04,	0x02,	///
	0x3E, 0x51, 0x49, 0x45, 0x3E,	//0
	0x00, 0x42, 0x7F, 0x40, 0x00,	//1
	0x42, 0x61, 0x51, 0x49, 0x46,	//2
	0x22, 0x41, 0x49, 0x49, 0x36,	//3
	0x18, 0x14, 0x12, 0x7F, 0x10,	//4
	0x27, 0x45, 0x45, 0x45, 0x39,	//5
	0x3C, 0x4A, 0x49, 0x49, 0x30,	//6
	0x01, 0x01, 0x79, 0x05, 0x03,	//7
	0x36, 0x49, 0x49, 0x49, 0x36,	//8
	0x06, 0x49, 0x49, 0x29, 0x1E,	//9
	0x00, 0x36, 0x36, 0x00, 0x00,	//:
	0x00, 0x56, 0x36, 0x00, 0x00,	//;
	0x00, 0x08, 0x14, 0x22, 0x41,	//<
	0x14, 0x14, 0x14, 0x14, 0x14,	//=
	0x41, 0x22, 0x14, 0x08, 0x00,	//>
	0x02, 0x01, 0x51, 0x09, 0x06,	//?
	0x32, 0x49, 0x71, 0x41, 0x3E,	//@
	0x7E, 0x09, 0x09, 0x09, 0x7E,	//A
	0x7F, 0x49, 0x49, 0x49, 0x36,	//B
	0x3E, 0x41, 0x41, 0x41, 0x22,	//C
	0x7F, 0x41, 0x41, 0x22, 0x1C,	//D
	0x7F, 0x49, 0x49, 0x49, 0x41,	//E
	0x7F, 0x09, 0x09, 0x09, 0x01,	//F
	0x3E, 0x41, 0x49, 0x49, 0x7A,	//G
	0x7F, 0x08, 0x08, 0x08, 0x7F,	//H
	0x00, 0x41, 0x7F, 0x41, 0x00,	//I
	0x20, 0x40, 0x41, 0x3F, 0x01,	//J
	0x7F, 0x08, 0x14, 0x22, 0x41,	//K
	0x7F, 0x40, 0x40, 0x40, 0x40,	//L
	0x7F, 0x02, 0x0C, 0x02, 0x7F,	//M
	0x7F, 0x04, 0x08, 0x10, 0x7F,	//N
	0x3E, 0x41, 0x41, 0x41, 0x3E,	//O
	0x7F, 0x09, 0x09, 0x09, 0x06,	//P
	0x3E, 0x41, 0x51, 0x21, 0x5E,	//Q
	0x7F, 0x09, 0x19, 0x29, 0x46,	//R
	0x26, 0x49, 0x49, 0x49, 0x32,	//S
	0x01, 0x01, 0x7F, 0x01, 0x01,	//T
	0x3F, 0x40, 0x40, 0x40, 0x3F,	//U
	0x1F, 0x20, 0x40, 0x20, 0x1F,	//V
	0x7F, 0x20, 0x18, 0x20, 0x7F,	//W
	0x63, 0x14, 0x08, 0x14, 0x63,	//X
	0x03, 0x04, 0x78, 0x04, 0x03,	//Y
	0x61, 0x51, 0x49, 0x45, 0x43,	//Z
	0x00, 0x7F, 0x41, 0x41, 0x00,	//[
	0x02, 0x04, 0x08, 0x10, 0x20,	//"\"
	0x00, 0x41, 0x41, 0x7F, 0x00,	//]
	0x00, 0x02, 0x01, 0x02, 0x00,	//^
	0x40, 0x40, 0x40, 0x40, 0x40,	//_
	0x00, 0x01, 0x02, 0x00, 0x00,	//`
	0x20, 0x54, 0x54, 0x54, 0x78,	//a
	0x3F, 0x48, 0x44, 0x44, 0x38,	//b
	0x38, 0x44, 0x44, 0x44, 0x20,	//c
	0x38, 0x44, 0x44, 0x48, 0x3F,	//d
	0x38, 0x54, 0x54, 0x54, 0x18,	//e
	0x00, 0x08, 0x7E, 0x09, 0x02,	//f
	0x08, 0x54, 0x54, 0x54, 0x3C,	//g
	0x7F, 0x08, 0x04, 0x04, 0x78,	//h
	0x00, 0x44, 0x7D, 0x40, 0x00,	//i
	0x20, 0x40, 0x40, 0x3D, 0x00,	//j
	0x00, 0x7F, 0x10, 0x28, 0x44,	//k
	0x00, 0x41, 0x7F, 0x40, 0x00,	//l
	0x7C, 0x04, 0x78, 0x04, 0x78,	//m
	0x7C, 0x08, 0x04, 0x04, 0x78,	//n
	0x38, 0x44, 0x44, 0x44, 0x38,	//o
	0x7C, 0x14, 0x14, 0x14, 0x08,	//p
	0x08, 0x14, 0x14, 0x14, 0x7C,	//q
	0x00, 0x7C, 0x08, 0x04, 0x04,	//r
	0x48, 0x54, 0x54, 0x54, 0x24,	//s
	0x00, 0x04, 0x3E, 0x44, 0x20,	//t
	0x3C, 0x40, 0x40, 0x20, 0x7C,	//u
	0x1C, 0x20, 0x40, 0x20, 0x1C,	//v
	0x3C, 0x40, 0x30, 0x40, 0x3C,	//w
	0x44, 0x24, 0x38, 0x48, 0x44,	//x
	0x44, 0x48, 0x30, 0x10, 0x0C,	//y
	0x44, 0x64, 0x54, 0x4C, 0x44,	//z
	0x00, 0x08, 0x36, 0x41, 0x41,	//{
	0x00, 0x00, 0x7F, 0x00, 0x00,	//|
	0x41, 0x41, 0x36, 0x08, 0x00,	//}
	0x08, 0x04, 0x08, 0x10, 0x08	//~
};

void commitLCD(){

	digitalWrite(PhyPortbit0, VirtualPort & 0x01);
	digitalWrite(PhyPortbit1, (VirtualPort & 0x02) >> 1);
	digitalWrite(PhyPortbit2, (VirtualPort & 0x04) >> 2);
	digitalWrite(PhyPortbit3, (VirtualPort & 0x08) >> 3);
	digitalWrite(PhyPortbit4, (VirtualPort & 0x10) >> 4);
	digitalWrite(PhyPortbit5, (VirtualPort & 0x20) >> 5);
	digitalWrite(PhyPortbit6, (VirtualPort & 0x40) >> 6);
	digitalWrite(PhyPortbit7, (VirtualPort & 0x80) >> 7);

	digitalWrite(EN_pin, 0);
	delay(CommitDelay);
	digitalWrite(EN_pin, 1);
	delay(CommitDelay);
}

void DisplayToggle(bool state){
	digitalWrite(D_I, 0);
	VirtualPort = 0x3E | state;
	commitLCD();
}

void DisplayStartLine(uint8_t Dsl){
	digitalWrite(D_I, 0);
	VirtualPort = 0xC0 | Dsl;
	commitLCD();
}

void PageAddressSet(uint8_t page){
	digitalWrite(D_I, 0);
	VirtualPort = 0xB8 | page;
	commitLCD();
}

void SetAddress(uint8_t addr){
	digitalWrite(D_I, 0);
	VirtualPort = 0x40 | addr;
	commitLCD();
}

void WriteDisplayData(uint8_t data){
	digitalWrite(D_I, 1);
	VirtualPort = data;
	//VirtualPort = ~data;	//Dark Mode
	commitLCD();
}

void DispInit(void){
	//Display Initalization
	digitalWrite(D_I, 0);
	digitalWrite(EN_pin, 1);
	digitalWrite(ChipSlectL, 1);
	digitalWrite(ChipSlectR, 1);
	DisplayToggle(0);
	DisplayStartLine(0);
	SetAddress(0);
	PageAddressSet(0);
	//Clear Screen
	DisplayToggle(1);
	digitalWrite(ChipSlectR, 0);
	unsigned int i,j;
	digitalWrite(ChipSlectL, 1);
	digitalWrite(ChipSlectR, 1);
	for(i=0; i<8; i++){
		for(j=0; j<64; j++){
			PageAddressSet(i);
			SetAddress(j);
			WriteDisplayData(0x00);
		}
	}
	//Reset parameter
	cursorX = 4; cursorY = 0; CurrentChip = 0; DispSL = 0;
	IsBottomLine = 0; IsTopLine = 1; IsFirstChar = 1; IsLastestChar = 0;

}

uint8_t printChar(uint8_t addr, uint8_t X, uint8_t Y, bool C){
	uint8_t i;
	unsigned int RealAddr = addr *5;
	digitalWrite(ChipSlectL, !C);
	digitalWrite(ChipSlectR, C);
	PageAddressSet(Y);
	for(i=0; i<5; i++){
		SetAddress(X);
		WriteDisplayData(BitmapFont[RealAddr+i]);
		X++;
	}
	WriteDisplayData(0x00);
	X++;
	return X;
}

uint8_t delChar(uint8_t X, uint8_t Y, bool C){
	uint8_t i;
	digitalWrite(ChipSlectL, !C);
	digitalWrite(ChipSlectR, C);
	PageAddressSet(Y);
	for(i=0; i<6; i++){
		SetAddress(X);
		WriteDisplayData(0x00);
		X++;
	}
	return X += -6;
}

void eraseLine(uint8_t Y){
	uint8_t i;
	digitalWrite(ChipSlectL, 1);
	digitalWrite(ChipSlectR, 1);
	PageAddressSet(Y);
	for(i=0; i<64; i++){
		SetAddress(i);
		WriteDisplayData(0x00);
	}
}

void CursorProcess(void){

	DispSL += (IsBottomLine & IsLastestChar);
	if(DispSL > 7) DispSL = 0;
	digitalWrite(ChipSlectL, 1);	digitalWrite(ChipSlectR, 1);
	DisplayStartLine(DispSL << 3);

	cursorY += IsLastestChar;
	if(cursorY > 7) cursorY = 0;
	if (IsLastestChar) eraseLine(cursorY);

	if(cursorX >= 59){
		cursorX = CurrentChip << 2;
		CurrentChip = !CurrentChip;
		//cursorX = 4*(!CurrentChip);
	}
}

void CursorBackProcess(void){

	//If !IsTopLine and IsFirstChar and cursorY > 0, Do
	//Else if !IsTopLine and IsFirstChar, cursorY = 7;
	if(cursorY > 0) cursorY += -((!IsTopLine) && IsFirstChar);
	else cursorY = 7*((!IsTopLine) && IsFirstChar);

	if(cursorX < 5){
		cursorX = 60 + 4*(CurrentChip);
		CurrentChip = !CurrentChip;
		//cursorX = 4*(!CurrentChip);
	}
	cursorX += -6;
}

void StatusUpdate(void){

	IsFirstChar = ((cursorX < 10) && (!CurrentChip));
	IsLastestChar = (cursorX >= 59) && (CurrentChip);
	IsTopLine = (DispSL == cursorY);
	IsBottomLine = (cursorY - DispSL == 7) || (DispSL - cursorY == 1);

}

/*
void SerialDebug(void){
	Serial.print("cursorX = "); Serial.println(cursorX);
	Serial.print("cursorY = "); Serial.println(cursorY);
	Serial.print("CurrentChip = "); Serial.println(CurrentChip);
	Serial.print("DispSL = "); Serial.println(DispSL);
	Serial.print("IsFirstChar = "); Serial.println(IsFirstChar);
	Serial.print("IsLastestChar = "); Serial.println(IsLastestChar);
	Serial.print("IsTopLine = "); Serial.println(IsTopLine);
	Serial.print("IsBottomLine = "); Serial.println(IsBottomLine);

}
*/

void SerialProcess(void){
	if (Serial.available() > 0) {
		uint8_t SerialData = Serial.read();
		StatusUpdate();
		if (SerialData >= 32) cursorX = printChar((SerialData-32), cursorX, cursorY, CurrentChip);

		else{
			switch (SerialData){
				case 8:	//Backspace
					if(!(IsFirstChar && IsTopLine)){
						CursorBackProcess();
						delChar(cursorX, cursorY, CurrentChip);
					}
					break;
				/*
				case 9:	//Tab
					DispInit();
					break;
				*/
				case 12:	//Ctrl + L
					DispInit();
					break;
				case 13:	//Enter
					cursorX = 4; CurrentChip = 0;
					if (DispSL < 7) DispSL += IsBottomLine;
					else if (IsBottomLine) DispSL = 0;
					if (cursorY < 7) cursorY ++;
					else cursorY = 0;
					eraseLine(cursorY);
					break;
				case 27:	//Esc
					int8_t CommandData[3];
					uint8_t i = 0;
					//Serial.println("Case Esc");
					//if (Serial.available() > 0) CommandData = Serial.read();
					do{
						if (Serial.available() > 0){
							CommandData[i] = Serial.read();
							i++;
							//Serial.println(i);
						}
					}while(i<2);

					//Serial.println(CommandData[1]);

					switch (CommandData[1]){
						case 50:	//2
							do{
								if (Serial.available() > 0){
								CommandData[i] = Serial.read();
								i++;
								//Serial.println(i);
								}
							}while(i<3);
							//if (Serial.available() > 0)
							//if(Serial.read() == 74) DispInit();
							if (CommandData[2] == 74) DispInit();
							break;
						case 65:	//Up
							if (cursorY > 0) cursorY += -(!IsTopLine);
							else cursorY = 7*(!IsTopLine);
							break;
						case 66:	//Down
							if (cursorY < 7) cursorY += !IsBottomLine;
							else if (!IsBottomLine) cursorY = 0;
							break;
						case 67:	//Right
							if (cursorX < 57) cursorX += 6*(!IsLastestChar);
							else if (!(IsLastestChar || CurrentChip)){
								cursorX = 0;
								CurrentChip = 1;
							}
							break;
						case 68:	//Left
							if (cursorX > 5) cursorX += -6*(!IsFirstChar);
							else if (!(IsFirstChar || (!CurrentChip))){
								cursorX = 58;
								CurrentChip = 0;
							}
							break;
						case 69:	//E
							DispInit();
							break;
						default:
							delay(1);
					}
					break;
				default:
					delay(1);
			}
		}
		StatusUpdate();
		CursorProcess();
		//SerialDebug();
	}
}


void setup(){
	// set the data rate for the SoftwareSerial port
	Serial.begin(115200);
	pinMode(D_I, OUTPUT);
	pinMode(EN_pin, OUTPUT);
	pinMode(ChipSlectL, OUTPUT);
	pinMode(ChipSlectR, OUTPUT);
	pinMode(PhyPortbit7, OUTPUT);
	pinMode(PhyPortbit6, OUTPUT);
	pinMode(PhyPortbit5, OUTPUT);
	pinMode(PhyPortbit4, OUTPUT);
	pinMode(PhyPortbit3, OUTPUT);
	pinMode(PhyPortbit2, OUTPUT);
	pinMode(PhyPortbit1, OUTPUT);
	pinMode(PhyPortbit0, OUTPUT);
	DispInit();
	//Serial.println("Hello, world?");
}

void loop() // run over and over
{
	//Serial.available();
	//Serial.read();
	//Serial.write("aaaa");
	//CLRDisplay();
	SerialProcess();

}
