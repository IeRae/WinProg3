#pragma once
#include "stdafx.h"
#include "Logic.h"

#define MAX 1024

class Gate {
public:
	//��Ʈ�� ����
	BagicGateType GateId;
	int x;
	int y;
	int width;
	int height;	

	void setBmSize(int w, int h);
	bool bmSizeFlag;

	//�Է°� ����
	bool inputArray[MAX];
	int inputArrayIndex;
	int fixedInputIndex;
	void addInputArray(bool* a, int index);
	//��°� ����
	bool outputArray[MAX];
	int outputArrayIndex;
	int fixedOutputIndex;

	void fixedIndex();

	//�� ����
	CString lable;

	//�ø��÷� ����
	bool edge;
	
	

	Gate();
	~Gate();
	Gate(BagicGateType id, int x, int y);
	void SevenSegment();
};