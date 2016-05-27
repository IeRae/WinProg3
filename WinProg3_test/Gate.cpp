#include "stdafx.h"
#include "Gate.h"

Gate::Gate() { 
	inputArrayIndex = 0; 
	outputArrayIndex = 0; 
	
	//inputArray[inputArrayIndex] = false;
	//outputArray[outputArrayIndex] = false;


	lable = _T("");

	bmSizeFlag = false;
}

Gate::~Gate()
{
}

Gate::Gate(int id, int a, int b) {
	GateId = id; 
	x = a; y = b;
	
	inputArrayIndex = 0; 
	outputArrayIndex = 0;
	
	//inputArray[inputArrayIndex] = false;
	//outputArray[outputArrayIndex] = false;
	
	lable = _T("");

	bmSizeFlag = false;

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
		fixedInputIndex = 2;
		fixedOutputIndex = 1;
	case ORSHAPE:
		fixedInputIndex = 2;
		fixedOutputIndex = 1;

	case NANDSHAPE:
	case NORSHAPE:
	case XORSHAPE:
	case OUTPUTTRUE:
	case OUTPUTFALSE:
		fixedInputIndex = 2;
		fixedOutputIndex = 2;
		break;
	case NOTSHAPE:
		fixedInputIndex = 1;
		fixedOutputIndex = 1;
		break;

	default:
		break;
	}
}
