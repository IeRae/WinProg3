#pragma once
#include "afxwin.h"
class Logic :
	public CWnd
{
public:
	Logic();
	~Logic();
	bool Not_Operator(bool A);
	bool Nor_Operator(bool A1, bool A2);
	bool Xor_Operator(bool A1, bool A2);
};

