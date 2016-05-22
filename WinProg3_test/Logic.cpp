#include "stdafx.h"
#include "Logic.h"


Logic::Logic()
{
}


Logic::~Logic()
{
}

bool Logic::Not_Operator(bool A) { return !A; }

bool Logic::Nor_Operator(bool A1, bool A2) { return !(A1|A2); }

bool Logic::Xor_Operator(bool A1, bool A2) { return A1^A2; }
