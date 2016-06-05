
// WinProg3_testDoc.h : CWinProg3_testDoc Ŭ������ �������̽�
//


#pragma once

class CWinProg3_testDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CWinProg3_testDoc();
	DECLARE_DYNCREATE(CWinProg3_testDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	bool getLogic(Gate& Gates);
	bool test(int i);
	void SevenSegment(bool& seg1, bool& seg2, bool& seg3, bool& seg4, bool& seg5, bool& seg6, bool& seg7, int& select);

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CWinProg3_testDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
