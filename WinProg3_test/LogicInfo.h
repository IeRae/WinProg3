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

	//출력값 정보
	bool outputArray[MAX];
	int outputArrayIndex;
	Gate() {}
	Gate(int a, int b, int c) { GateId = a; x = b; y = c; }
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

	Line() {}
	Line(bool start, int start_in, bool end, int end_in) { startBoolValue = start; startGateIndex = start_in; endBoolValue = end; endGateIndex = end_in; }
};