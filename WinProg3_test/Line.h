#pragma once
class Line {
public:
	//bool value 변수
	bool BoolValue;

	//시작 Gate index
	int startGateIndex;

	//종료 Gate index
	int endGateIndex;

	bool Drawline;
	bool Finish;
	

	CPoint s_point;
	CPoint e_point;


	void Draw(CPoint s_point, CPoint e_point);

	Line();
	~Line();
	Line(bool start, int start_in, int end_in, CPoint startpoint, CPoint endpoint);

};