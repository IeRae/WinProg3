#pragma once

#define MAX 1024

struct Gate {
	//��Ʈ�� ����
	int GateId;
	int x;
	int y;

	//�Է°� ����
	bool inputArray[MAX];
	int inputArrayIndex;

	//��°� ����
	bool outputArray[MAX];
	int outputArrayIndex;
	Gate() {}
	Gate(int a, int b, int c) { GateId = a; x = b; y = c; }
};

struct Line {
	//���� bool value ����
	bool startBoolValue;

	//���� Gate index
	int startGateIndex;

	//���� bool value ����
	bool endBoolValue;

	//���� Gate index
	int endGateIndex;

	Line() {}
	Line(bool start, int start_in, bool end, int end_in) { startBoolValue = start; startGateIndex = start_in; endBoolValue = end; endGateIndex = end_in; }
};