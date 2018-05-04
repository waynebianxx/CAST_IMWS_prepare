#pragma once

typedef struct
{
	int m_HeadIdent;//文件头标识,3Byte
	int m_HeadLen;//文件头长度,2Byte
	int m_FileFmt;//文件格式,3Byte
	UINT16 m_DataBitWidth;//数据位宽,2Byte
	int m_HeadReserv;//文件头预留,3Byte
	int m_ImgWidth;//图像宽度,3Byte
	int m_ImgHeight;//图像高度,3Byte
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

