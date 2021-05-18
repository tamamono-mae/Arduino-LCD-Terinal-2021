#define D_I 2
#define EN_pin 3
#define PhyPortbit0 4
#define PhyPortbit1 5
#define PhyPortbit2 6
#define PhyPortbit3 7

#define PhyPortbit4 8
#define PhyPortbit5 9
#define PhyPortbit6 10
#define PhyPortbit7 11
#define ChipSlectL 12
#define ChipSlectR 13

#define CommitDelay 0.5
#define vHighTime 0.5
#define vLowTime 0.5
#define writeTime 0.5

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

class cursor{ //cursor on memory
	public:
		uint8_t x = 0; //[0..19]
		uint8_t y = 0; //[0..7]

		void reset(void){
			x = 0;
			y = 0;
		};
		void printChar(void){
			x++;
			cursorHandle();
		}
		void crlf(void){ //return
			x = 0;
			y++;
			cursorHandle();
		}
		void del(void){
			if(x > 0){
				x+= -1;
				return;
			}
			x = 19;
			y = (y == 0) ? 7 : (y - 1);
		}
		void next(void){
			if(x < 19){
				x++;
				cursorHandle();
			}
		}
		void previous(void){
			if(x > 0){
				x+= -1;
				cursorHandle();
			}
		}
		void up(void){
			if (y > 0) {
				y+= -1;
				cursorHandle();
				return;
			};
			y = 7;
		}
		void down(void){
			y++;
			cursorHandle();
		}
	private:
		void cursorHandle(void){
			if (x > 19) {
				x = 0; y++;
			}
			if (y > 7) {
				y = 0;
			}
		};

};

class display{
	public:
		void oNoFF(bool d){
			PORTD = ((0x0E | d) << 4) | 0x08 | (PORTD & 0x03);
			PORTB = (PORTB & 0xC0) | 0x33; // ChipSlectL = ChipSlectR = true
			PORTD = PORTD ^ 0x08; //toggle EN_pin
			delay(vLowTime);
			PORTD = PORTD ^ 0x08;
			delay(vHighTime);
		}
		void displayStartLine(uint8_t *dSL){
			//digitalWrite(D_I, 0);
			uint8_t data = 0xC0 | *dSL;
			//writeData(&data);
			PORTD = ((data & 0x0F) << 4) | 0x08 | (PORTD & 0x03);
			PORTB = (PORTB & 0xF0) | ((data & 0xF0) >> 4);
			//0x08 => 00001000 D_I = 0; EN = 1;
			PORTD = PORTD ^ 0x08; //toggle EN_pin
			delay(vLowTime);
			PORTD = PORTD ^ 0x08;
			delay(vHighTime);
		}

		void pageAddressSet(uint8_t *page){
			//digitalWrite(D_I, 0);
			uint8_t data = 0xB8 | *page;
			//writeData(&data);
			PORTD = ((data & 0x0F) << 4) | 0x08 | (PORTD & 0x03);
			PORTB = (PORTB & 0xF0) | ((data & 0xF0) >> 4);
			//0x08 => 00001000 D_I = 0; EN = 1;
			PORTD = PORTD ^ 0x08; //toggle EN_pin
			delay(vLowTime);
			PORTD = PORTD ^ 0x08;
			delay(vHighTime);
		}

		void columnAddressSet(uint8_t *addr){
			//digitalWrite(D_I, 0);
			uint8_t data = 0x40 | *addr;
			//writeData(&data);
			PORTD = ((data & 0x0F) << 4) | 0x08 | (PORTD & 0x03);
			PORTB = (PORTB & 0xF0) | ((data & 0xF0) >> 4);
			//0x08 => 00001000 D_I = 0; EN = 1;
			PORTD = PORTD ^ 0x08; //toggle EN_pin
			delay(vLowTime);
			PORTD = PORTD ^ 0x08;
			delay(vHighTime);
		}

		void writeDisplayData(uint8_t *data){
			PORTD = ((*data & 0x0F) << 4) | 0x0C | (PORTD & 0x03);
			PORTB = (PORTB & 0xF0) | ((*data & 0xF0) >> 4);
			//0x0C => 00001100 D_I = 1; EN = 1;
			PORTD = PORTD ^ 0x08; //toggle EN_pin
			delay(vLowTime);
			PORTD = PORTD ^ 0x08;
			delay(writeTime);
		}

		void chipSelect(bool l, bool r){
			PORTB = (PORTB & 0xCF) | (l << 4) | (r << 5);
		}

		void chipSelectHold(void){
			selectHold = (PORTB & 0x30) >> 4;
		}

		void chipSelectRelease(void){
			PORTB = (PORTB & 0xCF) | (selectHold << 4);
		}

	private:
		char selectHold;
};

class displayHandler{
	public:
		uint8_t charDSL = 0; //Display Start Line [0..7]
		uint8_t dSL = 0;
		/*
		001 11111
		chipSlect columnAddress
		*/
		bool isFirstChar = true;
		bool isLastestChar = false;
		bool isTopLine = false;
		bool isBottomLine = false;
		bool chipSlect = false;

		void init(cursor *cursor, display *display){
			display->oNoFF(false);
			display->chipSelect(true, true);
			uint8_t j;
			for(uint8_t i=0;i<8;i++){
				display->pageAddressSet(&i);
				display->columnAddressSet(&value_zero);
				for(j=0; j<64; j++){
					display->writeDisplayData(&value_zero);
				}
			}
			display->oNoFF(true);
			display->columnAddressSet(&value_zero);
			display->pageAddressSet(&value_zero);
			display->displayStartLine(&value_zero);
			display->chipSelect(true, false);
			display->columnAddressSet(&value_four);
			cursor->reset();
			dSL = 0;
			charDSL = 0;
			isFirstChar = true;
			isLastestChar = false;
			isTopLine = false;
			isBottomLine = false;
			chipSlect = false;
		}

		void positionUpdate(cursor *cursor){
			if(charDSL > 7) charDSL = 0;
			isFirstChar = cursor->x == 0 || cursor->x == 10;
			isLastestChar = cursor->x == 9 || cursor->x == 19;
			isTopLine = (cursor->y == charDSL);
			isBottomLine = (cursor->y - charDSL == 7) || (charDSL - cursor->y == 1);
		}

		void crlf(cursor *cursor, display *display){
			charDSL+= isBottomLine; //因時常發生isBottomLine故不做整合
			cursor->crlf();
			positionUpdate(cursor);
			display->chipSelect(true, true); //二個螢幕有不同的col, page, dSL值，需同步操作
			display->columnAddressSet(&value_zero);
			display->pageAddressSet(&(cursor->y));
			dSL = charDSL << 3; //charDSL*8
			display->displayStartLine(&dSL);
			for(uint8_t i=0; i<64; i++){
				display->writeDisplayData(&value_zero);
			}
			display->columnAddressSet(&value_zero);
			display->chipSelect(true, false);
			display->columnAddressSet(&value_four);
		}

		void printChar(cursor *cursor, display *display, uint8_t *data){
			for(uint8_t i=0;i<5;i++){
				display->writeDisplayData(data);
				data++;
			}
			display->writeDisplayData(&value_zero);
			if(cursor->x == 19){
				crlf(cursor, display);
				positionUpdate(cursor);
				return;
			}
			if(isLastestChar)
				display->chipSelect(false, true);
			cursor->printChar();
			positionUpdate(cursor);
		}

		void del(cursor *cursor, display *display){
			if((cursor->x == 0) && isTopLine) return;
			if(cursor->x == 0){	// 換行特例
				display->chipSelect(true, true);
				cursor->del();
				display->pageAddressSet(&(cursor->y));
				display->chipSelect(false, true);
				display->columnAddressSet(&value54);
				for(uint8_t i=0;i<6;i++)
					display->writeDisplayData(&value_zero);
				display->columnAddressSet(&value54);
				positionUpdate(cursor);
				return;
			}
			if(cursor->x == 10)
				display->chipSelect(true, false);
			cursor->del();
			uint8_t columnAddress = ((cursor->x)%10)*6 + ((cursor->x < 10) << 2);
			display->columnAddressSet(&columnAddress);
			for(uint8_t i=0;i<6;i++)
				display->writeDisplayData(&value_zero);
			display->columnAddressSet(&columnAddress);
			positionUpdate(cursor);
		}

		void up(cursor *cursor, display *display){
			if (isTopLine) return;
			cursor->up();
			positionUpdate(cursor);
			display->chipSelectHold();
			display->chipSelect(true, true);
			display->pageAddressSet(&(cursor->y));
			display->chipSelectRelease();
		}

		void down(cursor *cursor, display *display){
			if (isBottomLine) return;
			cursor->down();
			positionUpdate(cursor);
			display->chipSelectHold();
			display->chipSelect(true, true);
			display->pageAddressSet(&(cursor->y));
			display->chipSelectRelease();
		}

		void left(cursor *cursor, display *display){
			if (cursor->x == 0) return;
			if (isFirstChar){
				display->chipSelect(true, false);
				cursor->previous();
				positionUpdate(cursor);
				display->columnAddressSet(&value58);
				return;
			}
			cursor->previous();
			positionUpdate(cursor);
			uint8_t columnAddress = ((cursor->x)%10)*6 + ((cursor->x < 10) << 2);
			display->columnAddressSet(&columnAddress);
		}

		void right(cursor *cursor, display *display){
			if (cursor->x == 19) return;
			if (isLastestChar){
				display->chipSelect(false, true);
				cursor->next();
				positionUpdate(cursor);
				display->columnAddressSet(&value54);
				return;
			}
			cursor->next();
			positionUpdate(cursor);
			uint8_t columnAddress = ((cursor->x)%10)*6 + ((cursor->x < 10) << 2);
			display->columnAddressSet(&columnAddress);
		}

	private:
		uint8_t value_zero = 0;
		uint8_t value_four = 4;
		uint8_t value54 = 54;
		uint8_t value58 = 58;
		/*
		void cursorMapping(cursor *cursor){
			columnAddress = (cursor->x)*5;
			pageAddress = ((cursor->y) + charDSL) % 8;
		}
		*/
};

cursor cursor;
display display;
displayHandler dH;

/*                      ______________
											 |              |
ANSI character     =>  |  Translator  | =>  display commands
command character  =>  |______________|

action =>	charCursor(offset) => displayCursor(offset) => displayCommands

*/

void SerialHandler(void){
	if (Serial.available() > 0) {
		uint8_t SerialData = Serial.read();
		if (SerialData == 127){
			dH.del(&cursor, &display);
			return;
		}
		if (SerialData >= 32){
			dH.printChar(&cursor, &display, &BitmapFont[(SerialData-32)*5]);
			return;
		}

		//Serial.println(SerialData);
		switch (SerialData){
			case 8:	//Backspace
				dH.del(&cursor, &display);
				break;
			case 12:	//Ctrl + L
				dH.init(&cursor, &display);
				break;
			case 13:	//Return
				dH.crlf(&cursor, &display);
				break;
			case 27:	//Esc
				uint8_t dataBuffer[3];
				uint8_t i = 0;
				//Serial.println("Case Esc");
				//if (Serial.available() > 0) CommandData = Serial.read();
				do{
					if (Serial.available() > 0){
						dataBuffer[i] = Serial.read();
						i++;
						//Serial.println(i);
					}
				}while(i<2);

				//Serial.println(CommandData[1]);

				switch (dataBuffer[1]){
					case 50:	//2
						do{
							if (Serial.available() > 0){
							dataBuffer[i] = Serial.read();
							i++;
							//Serial.println(i);
							}
						}while(i<3);
						//if (Serial.available() > 0)
						//if(Serial.read() == 74) DispInit();
						if (dataBuffer[2] == 74)
							dH.init(&cursor, &display);
						break;
					case 65:	//Up
						dH.up(&cursor, &display);
						break;
					case 66:	//Down
						dH.down(&cursor, &display);
						break;
					case 67:	//Right
						dH.right(&cursor, &display);
						break;
					case 68:	//Left
						dH.left(&cursor, &display);
						break;
					case 69:	//E
						dH.init(&cursor, &display);
						break;
				}
				break;
		}
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
	dH.init(&cursor, &display);
	//Serial.println("Hello, world?");

}

void loop() // run over and over
{
	SerialHandler();
}
