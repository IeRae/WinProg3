#pragma once

#define MAX 1024

class Gate {
public:
	//��Ʈ�� ����
	int GateId;
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

	//��°� ����
	bool outputArray[MAX];
	int outputArrayIndex;
	int fixedOutputIndex;

	void fixedIndex();

	//�� ����
	CString lable;
	
	

	Gate();
	~Gate();
	Gate(int id, int x, int y);
};