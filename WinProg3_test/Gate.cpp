#include "stdafx.h"
#include "Gate.h"

Gate::Gate() { 
	inputArrayIndex = 0; 
	outputArrayIndex = 0; 
	
	//inputArray[inputArrayIndex] = false;
	//outputArray[outputArrayIndex] = false;


	lable = _T("");

	bmSizeFlag = false;
	edge = false;
}

Gate::~Gate()
{
}

Gate::Gate(int id, int a, int b) {
	GateId = id; 
	x = a; y = b;
	
	if (id == INPUTTRUE)
		outputArray[0] = true;
	else if (id == INPUTFALSE)
		outputArray[0] = false;

	inputArrayIndex = 0; 
	outputArrayIndex = 0;
	
	//inputArray[inputArrayIndex] = false;
	//outputArray[outputArrayIndex] = false;
	
	lable = _T("");

	bmSizeFlag = false;
	edge = false;
	fixedIndex();
}

void Gate::setBmSize(int w, int h) {
	width = w;
	height = h;
}

void Gate::fixedIndex() {
	switch (GateId)
	{
	case ANDSHAPE:		
	case ORSHAPE:
	case NANDSHAPE:
	case NORSHAPE:
	case XORSHAPE:
		fixedInputIndex = 2;
		fixedOutputIndex = 1;	
		break;
	case OUTPUTTRUE:
	case OUTPUTFALSE:
		fixedInputIndex = 0;
		fixedOutputIndex = 1;
		break;
	case INPUTFALSE:
	case INPUTTRUE:
		fixedInputIndex = 1;
		fixedOutputIndex = 0;
		break;
	case NOTSHAPE:
		fixedInputIndex = 1;
		fixedOutputIndex = 1;
		break;

	default:
		break;
	}

	//inputArrayIndex = fixedInputIndex-1;
}

