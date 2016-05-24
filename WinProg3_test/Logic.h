#pragma once
#include "afxwin.h"
#include "LogicInfo.h"

class Logic :
	public CWnd
{
public:
	Logic();
	~Logic();
	bool Not_Operator(Gate Gates);
	bool Nor_Operator(Gate Gates);
	bool Xor_Operator(Gate Gates);
	bool And_Operator(Gate Gates);
	bool Nand_Operator(Gate Gates);
	bool Or_Operator(Gate Gates);
};

