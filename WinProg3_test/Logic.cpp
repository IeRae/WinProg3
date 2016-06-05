#include "stdafx.h"
#include "Logic.h"

Logic::Logic()
{
}


Logic::~Logic()
{
}


bool Logic::And_Operator(bool A1, bool A2) { return (A1 & A2); }

bool Logic::Or_Operator(bool A1, bool A2) { return (A1 | A2); }

bool Logic::Nand_Operator(bool A1, bool A2) { return !(A1 & A2); }

bool Logic::Not_Operator(bool A1) { return !A1; }

bool Logic::Nor_Operator(bool A1, bool A2) { return !(A1 | A2); }

bool Logic::Xor_Operator(bool A1, bool A2) { return A1^A2; }

/*
bool Logic::DFlipFlop_Operator(bool A1, bool A2) { 
	if(Gates[Clocks[i].gateIndex].edge == true){
			return A1;
		}
}

/
bool Logic::JKFlipFlop_Opertor(bool A1, bool A2, bool A3)
{
	if (((Clocks[i].clocktime)++) % Clocks[i].clocktype == 0) {
		if (Gates[Clocks[i].gateIndex].GateId == INPUTFALSE) {
			if (A1 == 0 && A2 == 0)
			{
				return Gates[Clocks[i].gateIndex].GateId;	//현재상태
			}
			else if (A1 == 0 && A2 == 1)
			{
				return 0;
			}
			else if (A1 == 1 && A2 == 0)
			{
				return 1;
			}
			else if (A1 == 1 && A2 == 1)
			{
				return; 	//반전
			}
		}
	}

}*/

bool Logic::TFlipFlop_Opertor(bool A1, bool A3) {
	if (A1) { return A3; }
	else { return !A3; }
}