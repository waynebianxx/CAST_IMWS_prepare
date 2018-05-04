#pragma once

typedef struct
{
	int m_HeadIdent;//�ļ�ͷ��ʶ,3Byte
	int m_HeadLen;//�ļ�ͷ����,2Byte
	int m_FileFmt;//�ļ���ʽ,3Byte
	UINT16 m_DataBitWidth;//����λ��,2Byte
	int m_HeadReserv;//�ļ�ͷԤ��,3Byte
	int m_ImgWidth;//ͼ����,3Byte
	int m_ImgHeight;//ͼ��߶�,3Byte
}HEAD_INFO;

typedef struct
{
	int m_PackHeadPos;
	int m_DataWidth;
	int m_DataLength;
	long long m_ProjIdent;
	long long m_FrameCnt;
	long long m_LineCnt;
	long long m_BroadTime;
	int m_PixStPos;
	int m_PixEdPos;
	long long m_ProjName;
	long long m_SaveTime;
	long long m_DevModel;
	char m_DevQuant;
	char m_DevNum;
	char m_SpecsecNum;
	int m_DataOrder;
	int m_SplicPixQuant;
	UINT8 m_LightRadLevel;
	//go on adding

}AUXIL_DATA;

class CAST_IMG
{
public:
	CAST_IMG();
	~CAST_IMG();
public:
	void* pData;
	void* pImgData;
	AUXIL_DATA AuxData;
	HEAD_INFO HeadData;
};

