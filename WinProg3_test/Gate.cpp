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

Gate::Gate(BagicGateType id, int a, int b) {
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
	case TFFSHAPE:
		fixedInputIndex = 2;
		fixedOutputIndex = 2;
		break;

	default:
		break;
	}

	//inputArrayIndex = fixedInputIndex-1;
}

void Gate::addInputArray(bool* a, int index) {
	
	for (int i = 0; i < index; i++) {
		inputArray[i] = a[i];
	}
}

/*
void Gate::SevenSegment()
{
	if (typeOfGate = SEVENSEGMENT & start_x != 0) {	//7세그먼트 그리기
		time[0] = 0;
		//펜 설정
		CPen pen(PS_SOLID, 1, RGB(200, 200, 200));
		CBrush red = (RGB(255, 0, 0));
		CBrush white = (RGB(255, 255, 255));

		int select;
		Y = 50;
		X = start_x;

		select = time[0];
		CPoint point_1[6] = { { X,Y },{ X + 10,Y - 5 },{ X + 40,Y - 5 },{ X + 50,Y },{ X + 40,Y + 5 },{ X + 10,Y + 5 } };	//시계 모양 좌표 그리기
		CPoint point_6[6] = { { X + 53,Y + 3 },{ X + 58,Y + 13 },{ X + 58,Y + 43 },{ X + 53,Y + 53 },{ X + 48,Y + 43 },{ X + 48,Y + 13 } };
		CPoint point_7[6] = { { X + 53,Y + 59 },{ X + 58, Y + 69 },{ X + 58,Y + 99 },{ X + 53,Y + 109 },{ X + 48,Y + 99 },{ X + 48,Y + 69 } };
		CPoint point_2[6] = { { X,Y + 112 },{ X + 10,Y + 107 },{ X + 40,Y + 107 },{ X + 50,Y + 112 },{ X + 40,Y + 117 },{ X + 10,Y + 117 } };
		CPoint point_5[6] = { { X - 3,Y + 59 },{ X + 3,Y + 69 },{ X + 3,Y + 99 },{ X - 3,Y + 109 },{ X - 8,Y + 99 },{ X - 8,Y + 69 } };
		CPoint point_4[6] = { { X - 3,Y + 3 },{ X + 3,Y + 13 },{ X + 3,Y + 43 },{ X - 3,Y + 53 },{ X - 8,Y + 43 },{ X - 8,Y + 13 } };
		CPoint point_3[6] = { { X,Y + 56 },{ X + 10,Y + 51 },{ X + 40,Y + 51 },{ X + 50,Y + 56 },{ X + 40,Y + 61 },{ X + 10,Y + 61 } };
		pDC->SelectObject(pen);


		//				  1
		//			 ---------
		//		4	|    3    | 6
		//			 ---------
		//		5	|         | 7
		//			 ---------
		//               2


		seg1 = seg2 = seg3 = seg4 = seg5 = seg6 = seg7 = false;
		switch (select)	//스위치문에 의해 세그먼트 결정
		{
		case 0: seg1 = seg2 = seg4 = seg5 = seg6 = seg7 = true;	break;
		case 1:	seg6 = seg7 = true; break;
		case 2: seg1 = seg6 = seg3 = seg5 = seg2 = true; break;
		case 3: seg1 = seg6 = seg3 = seg7 = seg2 = true; break;
		case 4: seg4 = seg3 = seg6 = seg7 = true;	break;
		case 5: seg1 = seg4 = seg3 = seg7 = seg2 = true; break;
		case 6: seg1 = seg4 = seg5 = seg2 = seg7 = seg3 = true; break;
		case 7: seg1 = seg6 = seg7 = true; break;
		case 8: seg1 = seg2 = seg3 = seg4 = seg5 = seg6 = seg7 = true; break;
		case 9: seg1 = seg3 = seg4 = seg6 = seg7 = seg2 = true; break;
		}



		if (seg1) {	//각 세그먼트별 동작설정
			pDC->SelectObject(red);
			pDC->Polygon(point_1, 6);
		}
		else {
			pDC->SelectObject(white);
			pDC->Polygon(point_1, 6);
		}

		if (seg2) {
			pDC->SelectObject(red);
			pDC->Polygon(point_2, 6);
		}
		else {
			pDC->SelectObject(white);
			pDC->Polygon(point_2, 6);
		}

		if (seg3) {
			pDC->SelectObject(red);
			pDC->Polygon(point_3, 6);
		}
		else {
			pDC->SelectObject(white);
			pDC->Polygon(point_3, 6);
		}

		if (seg4) {
			pDC->SelectObject(red);
			pDC->Polygon(point_4, 6);
		}
		else {
			pDC->SelectObject(white);
			pDC->Polygon(point_4, 6);
		}

		if (seg5) {
			pDC->SelectObject(red);
			pDC->Polygon(point_5, 6);
		}
		else {
			pDC->SelectObject(white);
			pDC->Polygon(point_5, 6);
		}

		if (seg6) {
			pDC->SelectObject(red);
			pDC->Polygon(point_6, 6);
		}
		else {
			pDC->SelectObject(white);
			pDC->Polygon(point_6, 6);
		}

		if (seg7) {
			pDC->SelectObject(red);
			pDC->Polygon(point_7, 6);
		}
		else {
			pDC->SelectObject(white);
			pDC->Polygon(point_7, 6);
		}
		InvalidateRect(NULL, false);

	}
}
*/