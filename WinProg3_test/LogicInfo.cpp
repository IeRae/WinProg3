#include "LogicInfo.h"

void Gate::fixed() {
	switch (GateId)
	{
	case 1:
	case 2:
	case 4:
	case 5:
	case 6:
		fixedInputIndex = 2;
		break;
	case 3:
		fixedInputIndex = 2;
		fixedOutputIndex = 1;
		break;

	default:
		break;
	}
}

Gate::Gate() { inputArrayIndex = 0; outputArrayIndex = 0; }

Gate::Gate(int id, int x, int y) { 
	GateId = id; this->x = x; this->y = y; 
	inputArrayIndex = 0; outputArrayIndex = 0;
	fixed();
}

Line::Line() {}

Line::Line(bool start, int start_in, bool end, int end_in) { 
	startBoolValue = start; 
	startGateIndex = start_in; 
	endBoolValue = end; 
	endGateIndex = end_in; 
}