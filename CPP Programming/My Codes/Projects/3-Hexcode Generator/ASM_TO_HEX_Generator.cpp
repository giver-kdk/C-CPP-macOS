/* Program to convert 8085 Micrproccessor's Assembly Language into Hexadecimal Value.
Author: Giver Khadka
Date: 2022-March-27 */
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <time.h>
#include <unistd.h>
#include <bitset>
#include <sstream>

#define SIZE1 202			// No. of 1 byte instructions
#define SIZE2 18			// No. of 2 byte instructions
#define SIZE3 26			// No. of 3 byte instructions
#define LABEL_NUM 18		// No. of 3 byte instructions with label
#define MAX_LABEL 50		// No. of maximum label strings to store
#define START_ADDRESS 49152 // 49152(Decimal) = C000(Hexadecimal)
#ifdef __linux__
#define DEVICE "linux"
#endif
#ifdef __WIN32
#define DEVICE "windows"
#endif
#ifdef __WIN64
#define DEVICE "windows"
#endif
#ifdef __APPLE__
#define DEVICE "apple"
#endif

using namespace std;

char fName[20];
int oneByteHex[250], twoByteHex[50], threeByteHex[50];		 // Store all hex values
string oneByteCode[250], twoByteCode[50], threeByteCode[50]; // Store all instructions
int labelAddress[MAX_LABEL], labelIndex = 0;
string labelName[MAX_LABEL];	 // Store detected labels
int hexCode[1000], hexIndex = 0; // Store final hex values

void initialize_instruction_set();
char *get_name_of(string str);
void asm_to_hex(string instruct, string label, string mnemonic, string operand1, string operand2);
void set_instruction_byte(string mnemonic, int &byte);
void set_address_data(string operand, int byte, int &data, int &addressHigh, int &addressLow);
void set_high_low_address(string operand, int &addressHigh, int &addressLow);
void display_instruct_address();
void print_hexadecimal();
void clean_string(string &str);
void strupr(string &str);

int main()
{
	initialize_instruction_set();
	char data = 's';
	enum programCounter
	{
		labelCode,
		opCode,
		firstOperand,
		secondOperand
	};
	int x = 0, i = 0, j = 0, k = 0, index = 0, PC = opCode; // PC = Program Counter
	string instruction, file_name, label, mnemonic, operand1, operand2;
	// Resize to reserve space
	instruction.resize(50);
	mnemonic.resize(20);
	operand1.resize(20);
	operand2.resize(20);
	FILE *fp1 = fopen(get_name_of(file_name), "r"); // User inputs filename
	if (fp1 == NULL)
	{
		cout << "Error Opening file..." << endl;
		exit(0);
	}
	// Copy orginal file content to temporary file and work on it
	FILE *fp2 = fopen("Temporary_File0001.txt", "a");
	while((data = getc(fp1)) != EOF)
	{
		putc(data, fp2);
	}
	// Append New Line character to elimiate EOF just after HLT 
	fprintf(fp2, "\n");
	fclose(fp1);
	fclose(fp2);

	// Read and process the temporary file
	fp2 = fopen("Temporary_File0001.txt", "r"); 
	if (fp2 == NULL)
	{
		cout << "Error Opening file..." << endl;
		exit(0);
	}
	//  Read all file data character-wise
	while ((data = getc(fp2)) != EOF)
	{
		if (data == '\n')
		{
			instruction[index] = ' ';
			instruction.push_back('\0'); // Stringify
			string program = instruction;
			instruction = "\0";
			// Uppercasing instruction for flexibility
			strupr(program);
			if (program.find(':') != -1) // Search for 'label:'
			{
				PC = labelCode;
			}
			else
			{
				PC = opCode;
			}
			label = "\0";
			mnemonic = "\0";
			operand1 = "\0";
			operand2 = "\0";
			x = 0;
			i = 0;
			j = 0;
			k = 0;
			index = 0;
			// String size decreases due to above initialization
			instruction.resize(20);
			label.resize(10);
			mnemonic.resize(10);
			operand1.resize(10);
			operand2.resize(10);
			clean_string(program); // Remove junk null characters from string

			for (int l = 0; l < program.length(); l++)
			{
				if ((program[l] == ' ') || (program[l] == ':') || (program[l] == ',') || (program[l] == '\t'))
				{
					// Check Alphabet or Numerical Character one step back
					if ((program[l - 1] != ',') && (program[l] != ':') && (program[l - 1] != ' ') && (program[l - 1] != '\t'))
					{
						if (PC == labelCode)
						{
							label[x] = '\0';
							// cout << "label: " << "*" << label << "*" << endl;
							PC++;
						}
						else if (PC == opCode)
						{
							mnemonic[i] = '\0';
							// cout << "mnemonic: " << "*" << mnemonic << "*" << endl;
							PC++;
						}
						else if (PC == firstOperand)
						{
							operand1[j] = '\0';
							// cout << "operand1: " << "*" << operand1 << "*"<< endl;
							PC++;
						}
						else if (PC == secondOperand)
						{
							operand2[k] = '\0';
							// cout << "operand2: " << "*" << operand2 << "*" << endl;
							PC = opCode;
						}
					}
				}
				else
				{
					if (PC == labelCode)
					{
						label[x] = program[l];
						x++;
					}
					else if (PC == opCode)
					{
						mnemonic[i] = program[l];
						i++;
					}
					else if (PC == firstOperand)
					{
						operand1[j] = program[l];
						j++;
					}
					else if (PC == secondOperand)
					{
						operand2[k] = program[l];
						k++;
					}
				}
			}
			if (mnemonic[0] == '\0')
			{ // Do nothing, if no instruction detected
				continue;
			}
			else
			{
				asm_to_hex(program, label, mnemonic, operand1, operand2);
			}
		}
		else
		{
			// cout << "Data: " << data << endl;
			instruction[index] = data;
			index++;
		}
	}
	cout << "\n\n**********8085 Microprocessor Hex Code of Assembly Language**********\n" << endl;
	print_hexadecimal();
	fclose(fp2);
	remove("Temporary_File0001.txt");			// Delete temporary file
	return 0;
}
void set_address_data(string operand, int byte, int &data, int &addressHigh, int &addressLow)
{
	int digitArray[10] = {0};
	int number = 0, flag = 1, i = 0;
	string finalOperand;
	clean_string(operand);
	// Remove all unneccessary zeros
	while (flag == 1)
	{
		if ((operand[0] == '0') && (operand.length() > 1))
		{
			// erase(position, No. of characters)
			operand.erase(0, 1);
		}
		else
		{
			flag = 0;
		}
	}
	// If operand is in hexa decimal, convert into integer and store
	if ((operand.back() == 'h') || (operand.back() == 'H'))
	{
		operand.pop_back();
		// // Convert string into exact number
		istringstream intValue(operand);
		intValue >> hex >> number;
		finalOperand = operand;
	}
	// If operand is in decimal, directly store
	else
	{
		for (int i = 0; i < operand.length(); i++)
		{ // Character to Number
			digitArray[i] = operand[i] - 48;
		}
		for (int i = 0; i < operand.length(); i++)
		{
			number = number * 10 + digitArray[i];
		}
		// Convert Number to String
		stringstream str_stream;
		str_stream << hex << number;
		string stringNumber;
		str_stream >> stringNumber;
		finalOperand = stringNumber;
	}
	if (byte == 3)
	{
		set_high_low_address(finalOperand, addressHigh, addressLow);
	}
	if (byte == 2)
	{
		data = number;
	}
}
void set_high_low_address(string operand, int &addressHigh, int &addressLow)
{
	int i = 0, j = 0, k = 0;
	clean_string(operand);
	string subCode1, subCode2;
	subCode1.resize(5);
	subCode2.resize(5);
	// Separate 16-bit address into two 8-bit addresses
	for (i = 0; i < operand.length(); i++)
	{
		// Store address except last two characters
		if (i < (operand.length() - 2))
		{
			subCode1[j] = operand[i];
			j++;
		}
		else
		{ // Store last two characters
			subCode2[k] = operand[i];
			k++;
		}
	}
	subCode1[j] = '\0';
	subCode2[k] = '\0';
	clean_string(subCode1);
	clean_string(subCode2);
	// Convert separated string into hex value
	istringstream higherValue(subCode1);
	higherValue >> hex >> addressHigh;

	istringstream lowerValue(subCode2);
	lowerValue >> hex >> addressLow;
}
void set_instruction_byte(string mnemonic, int &byte)
{
	int i, j;
	string tester;
	// Scan Two Byte Code Array
	for (i = 0; i < SIZE2; i++)
	{
		tester.resize(10);
		for (j = 0; ((twoByteCode[i][j] != ' ') && (twoByteCode[i][j] != '\0')); j++)
		{ // Store mnemonic part in 'tester'
			tester[j] = twoByteCode[i][j];
		}
		tester[j] = '\0';
		clean_string(tester);
		if (mnemonic == tester)
		{
			byte = 2;
		}
	}
	// Scan Three Byte Code Array
	for (i = 0; i < SIZE3; i++)
	{
		tester.resize(10);
		for (j = 0; ((threeByteCode[i][j] != ' ') && (threeByteCode[i][j] != '\0')); j++)
		{
			tester[j] = threeByteCode[i][j];
		}
		tester[j] = '\0';
		clean_string(tester);
		if (mnemonic == tester)
		{
			byte = 3;
		}
	}
}
void asm_to_hex(string instruct, string label, string mnemonic, string operand1, string operand2)
{
	// Data and Addresses initialized higher than 256(8-bit)
	int data = 0x111, addressHigh = 0x111, addressLow = 0x111;
	int i, byte = 1; // Assume 1 byte instruction
	bool labelFound = false, labelFlag = false, labelWasStored = false;
	// Remove last whitespace
	instruct.pop_back();
	string required_instruction;
	clean_string(instruct);
	clean_string(label);
	clean_string(mnemonic);
	clean_string(operand1);
	clean_string(operand2);
	if (!label.empty()) // If 'label' has data
	{
		for (i = 0; i < MAX_LABEL; i++)
		{
			if (labelName[i] == label)
			{
				// Code for storing given index's address on hexCode Array
				labelWasStored = true;
				stringstream str_stream;
				str_stream << hex << (START_ADDRESS + hexIndex);
				string stringAddress;
				str_stream >> stringAddress;

				set_high_low_address(stringAddress, addressHigh, addressLow);
				hexCode[labelAddress[i]] = addressLow;
				hexCode[labelAddress[i] + 1] = addressHigh;
			}
		}
		if (!labelWasStored)
		{
			labelName[labelIndex] = label;
			labelAddress[labelIndex] = START_ADDRESS + hexIndex; // Store current label's instruction address
			labelIndex++;
		}
	}
	// Detect instruction byte
	if (((operand1[0] == '\0') || operand1[0] == '\n') && (operand2[0] == '\0')) // Zero Operand Instruction
	{
		required_instruction = mnemonic;
	}
	else if ((!operand1.empty()) && (operand2.empty())) // One Operand Instruction
	{
		string testerCode = mnemonic;
		// Check if mnemonic is an instruction with label
		for (i = 0; i < LABEL_NUM; i++)
		{
			if (testerCode == threeByteCode[i])
			{
				labelFlag = true;
			}
		}
		if (labelFlag)
		{
			byte = 3;
			required_instruction = mnemonic;
			// Search label operand in label string array
			for (i = 0; i < MAX_LABEL; i++)
			{
				if (labelName[i] == operand1)
				{
					labelFound = true;
					// Set addresses to store it in Hexcode array's index speciied by labelAddress array
					stringstream str_stream;
					str_stream << hex << labelAddress[i];
					string stringAddress;
					str_stream >> stringAddress;
					set_high_low_address(stringAddress, addressHigh, addressLow);
				}
			}
			if (!labelFound)
			{ // Store label and hexcode array's index
				labelName[labelIndex] = operand1;
				labelAddress[labelIndex] = hexIndex + 1;
				labelIndex++;
			}
		}
		else if (mnemonic == "RST")
		{ // Unique RST has numerical operand but its 1 byte instruction
			required_instruction = mnemonic + " " + operand1;
		}
		else if ((operand1[0] >= '0') && (operand1[0] <= '9')) // If operand is numerical
		{
			set_instruction_byte(mnemonic, byte);
			set_address_data(operand1, byte, data, addressHigh, addressLow);
			required_instruction = mnemonic;
		}
		else
		{
			required_instruction = mnemonic + " " + operand1;
		}
		// cout << "Value in operand1" << endl;
	}
	else if ((!operand1.empty()) && (!operand2.empty())) // Two Operand Instruction
	{
		if ((operand2[0] >= '0') && (operand2[0] <= '9')) // For Numerical Operand
		{
			set_instruction_byte(mnemonic, byte);
			set_address_data(operand2, byte, data, addressHigh, addressLow);
			required_instruction = mnemonic + " " + operand1;
		}
		else
		{
			required_instruction = mnemonic + " " + operand1 + ", " + operand2;
		}
		// cout << "Value in operand1 and operand2" << endl;
	}
	// cout << "Required instruction: " << required_instruction << endl;
	clean_string(required_instruction);
	// Use corresponding opcode for detected byte of instruction
	if (byte == 1)
	{
		// cout << "No value in operand1 and operand2" << endl;
		for (i = 0; i < SIZE1; i++)
		{
			if (required_instruction == oneByteCode[i])
			{
				hexCode[hexIndex] = oneByteHex[i]; // Assign corresponging op-code
				hexIndex++;
			}
		}
	}
	else if (byte == 2)
	{
		for (i = 0; i < SIZE2; i++)
		{
			if (required_instruction == twoByteCode[i])
			{
				hexCode[hexIndex] = twoByteHex[i]; // Assign corresponging op-code
				hexIndex++;
				hexCode[hexIndex] = data; // Assign corresponging op-code
				hexIndex++;
			}
		}
	}
	else if (byte == 3)
	{
		// Storing logic if label detected
		if (labelFlag)
		{ // Directly store found label in hexcode array
			if (labelFound)
			{
				for (i = 0; i < SIZE3; i++)
				{
					if (required_instruction == threeByteCode[i])
					{
						hexCode[hexIndex] = threeByteHex[i]; // Assign corresponging op-code
						hexIndex++;
						hexCode[hexIndex] = addressLow; // Assign lower nibble address
						hexIndex++;
						hexCode[hexIndex] = addressHigh; // Assign higher nibble address
						hexIndex++;
					}
				}
			}
			else
			{
				// Leave space for undetected label
				for (i = 0; i < SIZE3; i++)
				{
					if (required_instruction == threeByteCode[i])
					{
						hexCode[hexIndex] = threeByteHex[i]; // Assign corresponging op-code
						hexIndex++;
						// Skip label address assignment
						hexIndex++;
						hexIndex++;
					}
				}
			}
		}
		// Storeing logic for non-label instructions
		else
		{
			for (i = 0; i < SIZE3; i++)
			{
				if (required_instruction == threeByteCode[i])
				{
					hexCode[hexIndex] = threeByteHex[i]; // Assign corresponging op-code
					hexIndex++;
					hexCode[hexIndex] = addressLow; // Assign lower nibble address
					hexIndex++;
					hexCode[hexIndex] = addressHigh; // Assign higher nibble address
					hexIndex++;
				}
			}
		}
	}
}
void display_instruct_address()
{
	static int instructAddress = START_ADDRESS, list_num = 1, i;
	// 'hex' and 'uppercase' converts number into capital hexadecimal
	cout << dec << setw(4) << setfill(' ') << list_num << ") ";
	cout << hex << uppercase << instructAddress << "H: ";
	instructAddress++;
	list_num++;
}
void print_hexadecimal()
{
	for (int i = 0; i < hexIndex; i++)
	{
		display_instruct_address();
		// cout << setw(2) << setfill('0') << bitset<8>(hexCode[i]) << endl;
		cout << setw(2) << setfill('0') << hex << uppercase << hexCode[i] << endl;
	}
}

char array_return(char &ch)
{
	return ch = ::toupper(ch);
}
void strupr(string &str)
{	// Convert string into uppercase character-wise
	for_each(str.begin(), str.end(), array_return);
}

char *get_name_of(string str)
{
	string os = "windows";
	int i;
	if (DEVICE != os)
	{
		system("clear");
	}
	else
	{
		system("cls");
	}
	cout << "\n\n**********Program to convert Assembmly Language into Hex Code**********\n\n" << endl;
	// usleep(milliseconds * 1000);
	cout << "How to use this software?\n" << endl;
	usleep(1000 * 1000);
	cout << "1) Create a (.txt)text file in same location" << endl;
	usleep(500 * 1000);
	cout << "2) Copy your assembly code into the text file" << endl;
	usleep(500 * 1000);
	cout << "3) Provide text file name and get your hex code\n" << endl;
	usleep(500 * 1000);
	cout << "Enter your assembly code text file name(with Extension): ";
	getline(cin, str);
	for (i = 0; i < str.length(); i++)
	{ // 'string' string's character value stored in 'char *' string's index
		fName[i] = str[i];
	}
	fName[i] = '\0';
	return fName;
}

void clean_string(string &str)
{
	// '\0' is embedded in the string during concatinaton. Remove extra '\0' using 'erase' and 'remove'
	str.erase(remove(str.begin(), str.end(), '\0'), str.end());
}
void initialize_instruction_set()
{
	// Initialize 1 byte mnemonics in an array
	oneByteCode[0] = "ADC A";
	oneByteCode[1] = "ADC B";
	oneByteCode[2] = "ADC C";
	oneByteCode[3] = "ADC D";
	oneByteCode[4] = "ADC E";
	oneByteCode[5] = "ADC H";
	oneByteCode[6] = "ADC L";
	oneByteCode[7] = "ADC M";
	oneByteCode[8] = "ADD A";
	oneByteCode[9] = "ADD B";
	oneByteCode[10] = "ADD C";
	oneByteCode[11] = "ADD D";
	oneByteCode[12] = "ADD E";
	oneByteCode[13] = "ADD H";
	oneByteCode[14] = "ADD L";
	oneByteCode[15] = "ADD M";
	oneByteCode[16] = "ANA A";
	oneByteCode[17] = "ANA B";
	oneByteCode[18] = "ANA C";
	oneByteCode[19] = "ANA D";
	oneByteCode[20] = "ANA E";
	oneByteCode[21] = "ANA H";
	oneByteCode[22] = "ANA L";
	oneByteCode[23] = "ANA M";
	oneByteCode[24] = "CMA";
	oneByteCode[25] = "CMC";
	oneByteCode[26] = "CMP A";
	oneByteCode[27] = "CMP B";
	oneByteCode[28] = "CMP C";
	oneByteCode[29] = "CMP D";
	oneByteCode[30] = "CMP E";
	oneByteCode[31] = "CMP H";
	oneByteCode[32] = "CMP L";
	oneByteCode[33] = "CMP M";
	oneByteCode[34] = "DAA";
	oneByteCode[35] = "DAD B";
	oneByteCode[36] = "DAD D";
	oneByteCode[37] = "DAD H";
	oneByteCode[38] = "DAD SP";
	oneByteCode[39] = "DCR A";
	oneByteCode[40] = "DCR B";
	oneByteCode[41] = "DCR C";
	oneByteCode[42] = "DCR D";
	oneByteCode[43] = "DCR E";
	oneByteCode[44] = "DCR H";
	oneByteCode[45] = "DCR L";
	oneByteCode[46] = "DCR M";
	oneByteCode[47] = "DCX B";
	oneByteCode[48] = "DCX D";
	oneByteCode[49] = "DCX H";
	oneByteCode[50] = "DCX SP";
	oneByteCode[51] = "DI";
	oneByteCode[52] = "EI";
	oneByteCode[53] = "HLT";
	oneByteCode[54] = "INR A";
	oneByteCode[55] = "INR B";
	oneByteCode[56] = "INR C";
	oneByteCode[57] = "INR D";
	oneByteCode[58] = "INR E";
	oneByteCode[59] = "INR H";
	oneByteCode[60] = "INR L";
	oneByteCode[61] = "INR M";
	oneByteCode[62] = "INX B";
	oneByteCode[63] = "INX D";
	oneByteCode[64] = "INX H";
	oneByteCode[65] = "INX SP";
	oneByteCode[66] = "LDAX B";
	oneByteCode[67] = "LDAX D";
	oneByteCode[68] = "MOV A, A";
	oneByteCode[69] = "MOV A, B";
	oneByteCode[70] = "MOV A, C";
	oneByteCode[71] = "MOV A, D";
	oneByteCode[72] = "MOV A, E";
	oneByteCode[73] = "MOV A, H";
	oneByteCode[74] = "MOV A, L";
	oneByteCode[75] = "MOV A, M";
	oneByteCode[76] = "MOV B, A";
	oneByteCode[77] = "MOV B, B";
	oneByteCode[78] = "MOV B, C";
	oneByteCode[79] = "MOV B, D";
	oneByteCode[80] = "MOV B, E";
	oneByteCode[81] = "MOV B, H";
	oneByteCode[82] = "MOV B, L";
	oneByteCode[83] = "MOV B, M";
	oneByteCode[84] = "MOV C, A";
	oneByteCode[85] = "MOV C, B";
	oneByteCode[86] = "MOV C, C";
	oneByteCode[87] = "MOV C, D";
	oneByteCode[88] = "MOV C, E";
	oneByteCode[89] = "MOV C, H";
	oneByteCode[90] = "MOV C, L";
	oneByteCode[91] = "MOV C, M";
	oneByteCode[92] = "MOV D, A";
	oneByteCode[93] = "MOV D, B";
	oneByteCode[94] = "MOV D, C";
	oneByteCode[95] = "MOV D, D";
	oneByteCode[96] = "MOV D, E";
	oneByteCode[97] = "MOV D, H";
	oneByteCode[98] = "MOV D, L";
	oneByteCode[99] = "MOV D, M";
	oneByteCode[100] = "MOV E, A";
	oneByteCode[101] = "MOV E, B";
	oneByteCode[102] = "MOV E, C";
	oneByteCode[103] = "MOV E, D";
	oneByteCode[104] = "MOV E, E";
	oneByteCode[105] = "MOV E, H";
	oneByteCode[106] = "MOV E, L";
	oneByteCode[107] = "MOV E, M";
	oneByteCode[108] = "MOV H, A";
	oneByteCode[109] = "MOV H, B";
	oneByteCode[110] = "MOV H, C";
	oneByteCode[111] = "MOV H, D";
	oneByteCode[112] = "MOV H, E";
	oneByteCode[113] = "MOV H, H";
	oneByteCode[114] = "MOV H, L";
	oneByteCode[115] = "MOV H, M";
	oneByteCode[116] = "MOV L, A";
	oneByteCode[117] = "MOV L, B";
	oneByteCode[118] = "MOV L, C";
	oneByteCode[119] = "MOV L, D";
	oneByteCode[120] = "MOV L, E";
	oneByteCode[121] = "MOV L, H";
	oneByteCode[122] = "MOV L, L";
	oneByteCode[123] = "MOV L, M";
	oneByteCode[124] = "MOV M, A";
	oneByteCode[125] = "MOV M, B";
	oneByteCode[126] = "MOV M, C";
	oneByteCode[127] = "MOV M, D";
	oneByteCode[128] = "MOV M, E";
	oneByteCode[129] = "MOV M, H";
	oneByteCode[130] = "MOV M, L";
	oneByteCode[131] = "NOP";
	oneByteCode[132] = "ORA A";
	oneByteCode[133] = "ORA B";
	oneByteCode[134] = "ORA C";
	oneByteCode[135] = "ORA D";
	oneByteCode[136] = "ORA E";
	oneByteCode[137] = "ORA H";
	oneByteCode[138] = "ORA L";
	oneByteCode[139] = "ORA M";
	oneByteCode[140] = "PCHL";
	oneByteCode[141] = "POP B";
	oneByteCode[142] = "POP D";
	oneByteCode[143] = "POP H";
	oneByteCode[144] = "POP PSW";
	oneByteCode[145] = "PUSH B";
	oneByteCode[146] = "PUSH D";
	oneByteCode[147] = "PUSH H";
	oneByteCode[148] = "PUSH PSW";
	oneByteCode[149] = "RAL";
	oneByteCode[150] = "RAR";
	oneByteCode[151] = "RC";
	oneByteCode[152] = "RET";
	oneByteCode[153] = "RIM";
	oneByteCode[154] = "RLC";
	oneByteCode[155] = "RM";
	oneByteCode[156] = "RNC";
	oneByteCode[157] = "RNZ";
	oneByteCode[158] = "RP";
	oneByteCode[159] = "RPE";
	oneByteCode[160] = "RPO";
	oneByteCode[161] = "RRC";
	oneByteCode[162] = "RST 0";
	oneByteCode[163] = "RST 1";
	oneByteCode[164] = "RST 2";
	oneByteCode[165] = "RST 3";
	oneByteCode[166] = "RST 4";
	oneByteCode[167] = "RST 5";
	oneByteCode[168] = "RST 6";
	oneByteCode[169] = "RST 7";
	oneByteCode[170] = "RZ";
	oneByteCode[171] = "SBB A";
	oneByteCode[172] = "SBB B";
	oneByteCode[173] = "SBB C";
	oneByteCode[174] = "SBB D";
	oneByteCode[175] = "SBB E";
	oneByteCode[176] = "SBB H";
	oneByteCode[177] = "SBB L";
	oneByteCode[178] = "SBB M";
	oneByteCode[179] = "SIM";
	oneByteCode[180] = "SPHL";
	oneByteCode[181] = "STAX B";
	oneByteCode[182] = "STAX D";
	oneByteCode[183] = "STC";
	oneByteCode[184] = "SUB A";
	oneByteCode[185] = "SUB B";
	oneByteCode[186] = "SUB C";
	oneByteCode[187] = "SUB D";
	oneByteCode[188] = "SUB E";
	oneByteCode[189] = "SUB H";
	oneByteCode[190] = "SUB L";
	oneByteCode[191] = "SUB M";
	oneByteCode[192] = "XCHG";
	oneByteCode[193] = "XRA A";
	oneByteCode[194] = "XRA B";
	oneByteCode[195] = "XRA C";
	oneByteCode[196] = "XRA D";
	oneByteCode[197] = "XRA E";
	oneByteCode[198] = "XRA H";
	oneByteCode[199] = "XRA L";
	oneByteCode[200] = "XRA M";
	oneByteCode[201] = "XTHL";

	// Initialize corresponging hex code in an array

	oneByteHex[0] = 0x8F;
	oneByteHex[1] = 0x88;
	oneByteHex[2] = 0x89;
	oneByteHex[3] = 0x8A;
	oneByteHex[4] = 0x8B;
	oneByteHex[5] = 0x8C;
	oneByteHex[6] = 0x8D;
	oneByteHex[7] = 0x8E;
	oneByteHex[8] = 0x87;
	oneByteHex[9] = 0x80;
	oneByteHex[10] = 0x81;
	oneByteHex[11] = 0x82;
	oneByteHex[12] = 0x83;
	oneByteHex[13] = 0x84;
	oneByteHex[14] = 0x85;
	oneByteHex[15] = 0x86;
	oneByteHex[16] = 0xA7;
	oneByteHex[17] = 0xA0;
	oneByteHex[18] = 0xA1;
	oneByteHex[19] = 0xA2;
	oneByteHex[20] = 0xA3;
	oneByteHex[21] = 0xA4;
	oneByteHex[22] = 0xA5;
	oneByteHex[23] = 0xA6;
	oneByteHex[24] = 0x2F;
	oneByteHex[25] = 0x3F;
	oneByteHex[26] = 0xBF;
	oneByteHex[27] = 0xB8;
	oneByteHex[28] = 0xB9;
	oneByteHex[29] = 0xBA;
	oneByteHex[30] = 0xBB;
	oneByteHex[31] = 0xBC;
	oneByteHex[32] = 0xBD;
	oneByteHex[33] = 0xBE;
	oneByteHex[34] = 0x27;
	oneByteHex[35] = 0x09;
	oneByteHex[36] = 0x19;
	oneByteHex[37] = 0x29;
	oneByteHex[38] = 0x39;
	oneByteHex[39] = 0x3D;
	oneByteHex[40] = 0x05;
	oneByteHex[41] = 0x0D;
	oneByteHex[42] = 0x15;
	oneByteHex[43] = 0x1D;
	oneByteHex[44] = 0x25;
	oneByteHex[45] = 0x2D;
	oneByteHex[46] = 0x35;
	oneByteHex[47] = 0x0B;
	oneByteHex[48] = 0x1B;
	oneByteHex[49] = 0x2B;
	oneByteHex[50] = 0x3B;
	oneByteHex[51] = 0xF3;
	oneByteHex[52] = 0xFB;
	oneByteHex[53] = 0x76;
	oneByteHex[54] = 0x3C;
	oneByteHex[55] = 0x04;
	oneByteHex[56] = 0x0C;
	oneByteHex[57] = 0x14;
	oneByteHex[58] = 0x1C;
	oneByteHex[59] = 0x24;
	oneByteHex[60] = 0x2C;
	oneByteHex[61] = 0x34;
	oneByteHex[62] = 0x03;
	oneByteHex[63] = 0x13;
	oneByteHex[64] = 0x23;
	oneByteHex[65] = 0x33;
	oneByteHex[66] = 0x0A;
	oneByteHex[67] = 0x1A;
	oneByteHex[68] = 0x7F;
	oneByteHex[69] = 0x78;
	oneByteHex[70] = 0x79;
	oneByteHex[71] = 0x7A;
	oneByteHex[72] = 0x7B;
	oneByteHex[73] = 0x7C;
	oneByteHex[74] = 0x7D;
	oneByteHex[75] = 0x7E;
	oneByteHex[76] = 0x47;
	oneByteHex[77] = 0x40;
	oneByteHex[78] = 0x41;
	oneByteHex[79] = 0x42;
	oneByteHex[80] = 0x43;
	oneByteHex[81] = 0x44;
	oneByteHex[82] = 0x45;
	oneByteHex[83] = 0x46;
	oneByteHex[84] = 0x4F;
	oneByteHex[85] = 0x48;
	oneByteHex[86] = 0x49;
	oneByteHex[87] = 0x4A;
	oneByteHex[88] = 0x4B;
	oneByteHex[89] = 0x4C;
	oneByteHex[90] = 0x4D;
	oneByteHex[91] = 0x4E;
	oneByteHex[92] = 0x57;
	oneByteHex[93] = 0x50;
	oneByteHex[94] = 0x51;
	oneByteHex[95] = 0x52;
	oneByteHex[96] = 0x53;
	oneByteHex[97] = 0x54;
	oneByteHex[98] = 0x55;
	oneByteHex[99] = 0x56;
	oneByteHex[100] = 0x5F;
	oneByteHex[101] = 0x58;
	oneByteHex[102] = 0x59;
	oneByteHex[103] = 0x5A;
	oneByteHex[104] = 0x5B;
	oneByteHex[105] = 0x5C;
	oneByteHex[106] = 0x5D;
	oneByteHex[107] = 0x5E;
	oneByteHex[108] = 0x67;
	oneByteHex[109] = 0x60;
	oneByteHex[110] = 0x61;
	oneByteHex[111] = 0x62;
	oneByteHex[112] = 0x63;
	oneByteHex[113] = 0x64;
	oneByteHex[114] = 0x65;
	oneByteHex[115] = 0x66;
	oneByteHex[116] = 0x6F;
	oneByteHex[117] = 0x68;
	oneByteHex[118] = 0x69;
	oneByteHex[119] = 0x6A;
	oneByteHex[120] = 0x6B;
	oneByteHex[121] = 0x6C;
	oneByteHex[122] = 0x6D;
	oneByteHex[123] = 0x6E;
	oneByteHex[124] = 0x77;
	oneByteHex[125] = 0x70;
	oneByteHex[126] = 0x71;
	oneByteHex[127] = 0x72;
	oneByteHex[128] = 0x73;
	oneByteHex[129] = 0x74;
	oneByteHex[130] = 0x75;
	oneByteHex[131] = 0x00;
	oneByteHex[132] = 0xB7;
	oneByteHex[133] = 0xB0;
	oneByteHex[134] = 0xB1;
	oneByteHex[135] = 0xB2;
	oneByteHex[136] = 0xB3;
	oneByteHex[137] = 0xB4;
	oneByteHex[138] = 0xB5;
	oneByteHex[139] = 0xB6;
	oneByteHex[140] = 0xE9;
	oneByteHex[141] = 0xC1;
	oneByteHex[142] = 0xD1;
	oneByteHex[143] = 0xE1;
	oneByteHex[144] = 0xF1;
	oneByteHex[145] = 0xC5;
	oneByteHex[146] = 0xD5;
	oneByteHex[147] = 0xE5;
	oneByteHex[148] = 0xF5;
	oneByteHex[149] = 0x17;
	oneByteHex[150] = 0x1F;
	oneByteHex[151] = 0xD8;
	oneByteHex[152] = 0xC9;
	oneByteHex[153] = 0x20;
	oneByteHex[154] = 0x07;
	oneByteHex[155] = 0xF8;
	oneByteHex[156] = 0xD0;
	oneByteHex[157] = 0xC0;
	oneByteHex[158] = 0xF0;
	oneByteHex[159] = 0xE8;
	oneByteHex[160] = 0xE0;
	oneByteHex[161] = 0x0F;
	oneByteHex[162] = 0xC7;
	oneByteHex[163] = 0xCF;
	oneByteHex[164] = 0xD7;
	oneByteHex[165] = 0xDF;
	oneByteHex[166] = 0xE7;
	oneByteHex[167] = 0xEF;
	oneByteHex[168] = 0xF7;
	oneByteHex[169] = 0xFF;
	oneByteHex[170] = 0xC8;
	oneByteHex[171] = 0x9F;
	oneByteHex[172] = 0x98;
	oneByteHex[173] = 0x99;
	oneByteHex[174] = 0x9A;
	oneByteHex[175] = 0x9B;
	oneByteHex[176] = 0x9C;
	oneByteHex[177] = 0x9D;
	oneByteHex[178] = 0x9E;
	oneByteHex[179] = 0x30;
	oneByteHex[180] = 0xF9;
	oneByteHex[181] = 0x02;
	oneByteHex[182] = 0x12;
	oneByteHex[183] = 0x37;
	oneByteHex[184] = 0x97;
	oneByteHex[185] = 0x90;
	oneByteHex[186] = 0x91;
	oneByteHex[187] = 0x92;
	oneByteHex[188] = 0x93;
	oneByteHex[189] = 0x94;
	oneByteHex[190] = 0x95;
	oneByteHex[191] = 0x96;
	oneByteHex[192] = 0xEB;
	oneByteHex[193] = 0xAF;
	oneByteHex[194] = 0xA8;
	oneByteHex[195] = 0xA9;
	oneByteHex[196] = 0xAA;
	oneByteHex[197] = 0xAB;
	oneByteHex[198] = 0xAC;
	oneByteHex[199] = 0xAD;
	oneByteHex[200] = 0xAE;
	oneByteHex[201] = 0xE3;

	// Initialize 2 byte Mnemonics Array

	twoByteCode[0] = "ACI";
	twoByteCode[1] = "ADI";
	twoByteCode[2] = "ANI";
	twoByteCode[3] = "CPI";
	twoByteCode[4] = "IN";
	twoByteCode[5] = "MVI A";
	twoByteCode[6] = "MVI B";
	twoByteCode[7] = "MVI C";
	twoByteCode[8] = "MVI D";
	twoByteCode[9] = "MVI E";
	twoByteCode[10] = "MVI H";
	twoByteCode[11] = "MVI L";
	twoByteCode[12] = "MVI M";
	twoByteCode[13] = "ORI";
	twoByteCode[14] = "OUT";
	twoByteCode[15] = "SBI";
	twoByteCode[16] = "SUI";
	twoByteCode[17] = "XRI";

	// Initialize corresponging hex code in an array

	twoByteHex[0] = 0xCE;
	twoByteHex[1] = 0xC6;
	twoByteHex[2] = 0xE6;
	twoByteHex[3] = 0xFE;
	twoByteHex[4] = 0xDB;
	twoByteHex[5] = 0x3E;
	twoByteHex[6] = 0x06;
	twoByteHex[7] = 0x0E;
	twoByteHex[8] = 0x16;
	twoByteHex[9] = 0x1E;
	twoByteHex[10] = 0x26;
	twoByteHex[11] = 0x2E;
	twoByteHex[12] = 0x36;
	twoByteHex[13] = 0xF6;
	twoByteHex[14] = 0xD3;
	twoByteHex[15] = 0xDE;
	twoByteHex[16] = 0xD6;
	twoByteHex[17] = 0xEE;

	// Initialize 3 byte Mnemonics Array

	threeByteCode[0] = "CALL";
	threeByteCode[1] = "CC";
	threeByteCode[2] = "CM";
	threeByteCode[3] = "CNC";
	threeByteCode[4] = "CNZ";
	threeByteCode[5] = "CP";
	threeByteCode[6] = "CPE";
	threeByteCode[7] = "CPO";
	threeByteCode[8] = "CZ";
	threeByteCode[9] = "JC";
	threeByteCode[10] = "JM";
	threeByteCode[11] = "JMP";
	threeByteCode[12] = "JNC";
	threeByteCode[13] = "JNZ";
	threeByteCode[14] = "JP";
	threeByteCode[15] = "JPE";
	threeByteCode[16] = "JPO";
	threeByteCode[17] = "JZ";
	threeByteCode[18] = "LDA";
	threeByteCode[19] = "LHLD";
	threeByteCode[20] = "LXI B";
	threeByteCode[21] = "LXI D";
	threeByteCode[22] = "LXI H";
	threeByteCode[23] = "LXI SP";
	threeByteCode[24] = "SHLD";
	threeByteCode[25] = "STA";

	// Initialize corresponging hex code in an array

	threeByteHex[0] = 0xCD;
	threeByteHex[1] = 0xDC;
	threeByteHex[2] = 0xFC;
	threeByteHex[3] = 0xD4;
	threeByteHex[4] = 0xC4;
	threeByteHex[5] = 0xF4;
	threeByteHex[6] = 0xEC;
	threeByteHex[7] = 0xE4;
	threeByteHex[8] = 0xCC;
	threeByteHex[9] = 0xDA;
	threeByteHex[10] = 0xFA;
	threeByteHex[11] = 0xC3;
	threeByteHex[12] = 0xD2;
	threeByteHex[13] = 0xC2;
	threeByteHex[14] = 0xF2;
	threeByteHex[15] = 0xEA;
	threeByteHex[16] = 0xE2;
	threeByteHex[17] = 0xCA;
	threeByteHex[18] = 0x3A;
	threeByteHex[19] = 0x2A;
	threeByteHex[20] = 0x01;
	threeByteHex[21] = 0x11;
	threeByteHex[22] = 0x21;
	threeByteHex[23] = 0x31;
	threeByteHex[24] = 0x22;
	threeByteHex[25] = 0x32;
}