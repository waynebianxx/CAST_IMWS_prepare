
// CAST_IMWS_prepareDoc.h : CCAST_IMWS_prepareDoc ��Ľӿ�
//


#pragma once


class CCAST_IMWS_prepareDoc : public CDocument
{
protected: // �������л�����
	CCAST_IMWS_prepareDoc();
	DECLARE_DYNCREATE(CCAST_IMWS_prepareDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CCAST_IMWS_prepareDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
