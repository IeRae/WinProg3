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
	int fixedInputIndex;

	//��°� ����
	bool outputArray[MAX];
	int outputArrayIndex;
	int fixedOutputIndex;

	void fixed() {};

	Gate();
	Gate(int id, int x, int y);
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

	Line();
	Line(bool start, int start_in, bool end, int end_in);
};