#include "stdafx.h"
#include "Line.h"


Line::Line()
{
}


Line::~Line()
{
}

Line::Line(bool start, int start_in, bool end, int end_in) {
	startBoolValue = start;
	startGateIndex = start_in;
	endBoolValue = end;
	endGateIndex = end_in;
}