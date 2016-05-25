#pragma once
#include "afxwin.h"

enum BagicGateType {
	ANDSHAPE, ORSHAPE, NOTSHAPE,NANDSHAPE,NORSHAPE,XORSHAPE, INPUTTRUE, INPUTFALSE, OUTPUTTRUE, OUTPUTFALSE, OUTPUTCLOCK
};

enum IOGateType {
	
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
};

