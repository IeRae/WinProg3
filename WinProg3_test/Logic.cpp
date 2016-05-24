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
