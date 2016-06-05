#pragma once

#define MAX 1024

class Gate {
public:
	//비트맵 정보
	int GateId;
	int x;
	int y;
	int width;
	int height;	
	int rota;

	void setBmSize(int w, int h);
	bool bmSizeFlag;

	//입력값 정보
	bool inputArray[MAX];
	int inputArrayIndex;
	int fixedInputIndex;

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
	Gate(int id, int x, int y);
	void SevenSegment();
};