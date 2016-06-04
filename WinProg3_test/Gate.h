#pragma once
#include "stdafx.h"
#include "Logic.h"

#define MAX 1024

class Gate {
public:
	//비트맵 정보
	BagicGateType GateId;
	int x;
	int y;
	int width;
	int height;	

	void setBmSize(int w, int h);
	bool bmSizeFlag;

	//입력값 정보
	bool inputArray[MAX];
	int inputArrayIndex;
	int fixedInputIndex;
	void addInputArray(bool* a, int index);
	//출력값 정보
	bool outputArray[MAX];
	int outputArrayIndex;
	int fixedOutputIndex;

	void fixedIndex();

	//라벨 정보
	CString lable;

	//플립플롭 정보
	bool edge;
	
	

	Gate();
	~Gate();
	Gate(BagicGateType id, int x, int y);
	void SevenSegment();
};