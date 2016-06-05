#pragma once
#include "afxwin.h"

enum BagicGateType {
	ANDSHAPE, ORSHAPE, NOTSHAPE,NANDSHAPE,NORSHAPE,XORSHAPE, INPUTTRUE, INPUTFALSE, OUTPUTTRUE, OUTPUTFALSE, OUTPUTCLOCK,SEVENSEGMENT ,LINESHAPE, NONE, BRANCH
, DFLIPFLOP, JKFLIPFLOP};

enum ClockType {
	HZTIMES_1 = 0,HZTIMES_10,HZTIMES_100
};

class Logic :
	public CWnd
{
public:
	Logic();
	~Logic();
	bool Not_Operator(bool A);
	bool Nor_Operator(bool A1, bool A2);
	bool Xor_Operator(bool A1, bool A2);
	bool And_Operator(bool A1, bool A2);
	bool Nand_Operator(bool A1, bool A2);
	bool Or_Operator(bool A1, bool A2);
	bool DFlipFlop_Operator(bool A1, bool A2);
	bool JKFlipFlop_Opertor(bool A1, bool A2, bool A3);
	bool TFlipFlop_Opertor(bool A1, bool A3);

};

