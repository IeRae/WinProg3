#pragma once
class Line {
public:
	//���� bool value ����
	bool startBoolValue;

	//���� Gate index
	int startGateIndex;

	//���� bool value ����
	bool endBoolValue;

	//���� Gate index
	int endGateIndex;

	Line();
	~Line();
	Line(bool start, int start_in, bool end, int end_in);
};