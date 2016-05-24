#pragma once

#define MAX 1024

struct Gate {
	//비트맵 정보
	int GateId;
	int x;
	int y;

	//입력값 정보
	bool inputArray[MAX];
	int inputArrayIndex;
	int fixedInputIndex;

	//출력값 정보
	bool outputArray[MAX];
	int outputArrayIndex;
	int fixedOutputIndex;

	void fixed() {};

	Gate();
	Gate(int id, int x, int y);
};

struct Line {
	//시작 bool value 변수
	bool startBoolValue;

	//시작 Gate index
	int startGateIndex;

	//종료 bool value 변수
	bool endBoolValue;

	//종료 Gate index
	int endGateIndex;

	Line();
	Line(bool start, int start_in, bool end, int end_in);
};