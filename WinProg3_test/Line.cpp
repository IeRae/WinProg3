#include "stdafx.h"
#include "Line.h"


Line::Line()
{
}


Line::~Line()
{
}

Line::Line(bool start, int start_in, int end_in, CPoint startpoint, CPoint endpoint) {
	BoolValue = start;
	startGateIndex = start_in;
	endGateIndex = end_in;
	s_point = startpoint;
	e_point = endpoint;
	
}

