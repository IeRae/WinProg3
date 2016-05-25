#pragma once
class Line {
public:
	//시작 bool value 변수
	bool startBoolValue;

	//시작 Gate index
	int startGateIndex;

	//종료 bool value 변수
	bool endBoolValue;

	//종료 Gate index
	int endGateIndex;

	Line();
	~Line();
	Line(bool start, int start_in, bool end, int end_in);
};