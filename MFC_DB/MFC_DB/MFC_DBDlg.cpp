
// MFC_DBDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_DB.h"
#include "MFC_DBDlg.h"
#include "afxdialogex.h"
#include <vector>
#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#ifdef MARKED
typedef struct _STUDENT_INFO
{
	char ID[32];
	char Name[16];
	double Score[3];
	struct _STUDENT_INFO *next;
}STUDENT_INFO;
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_DBDlg �Ի���




CMFC_DBDlg::CMFC_DBDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_DBDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_DBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ShowInfo, myLIST_ShowInfo);
	DDX_Control(pDX, IDC_EDIT_Name2, score1);
	DDX_Control(pDX, IDC_EDIT_Name6, m_edit);
	DDX_Control(pDX, IDC_EDIT2, s_edit);
}

BEGIN_MESSAGE_MAP(CMFC_DBDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FileLoad, &CMFC_DBDlg::OnBnClickedButtonFileload)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_ShowInfo, &CMFC_DBDlg::OnNMRClickListShowinfo)
	ON_BN_CLICKED(IDC_BUTTON_NewNode, &CMFC_DBDlg::OnBnClickedButtonNewnode)
	ON_BN_CLICKED(IDOK, &CMFC_DBDlg::OnBnClickedOk)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CMFC_DBDlg::OnHdnItemclickListShowinfo)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ShowInfo, &CMFC_DBDlg::OnNMDblclkListShowinfo)
	ON_EN_KILLFOCUS(IDC_EDIT_Name6, &CMFC_DBDlg::OnEnKillfocusEditName6)
END_MESSAGE_MAP()


// CMFC_DBDlg ��Ϣ�������

BOOL CMFC_DBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_edit.ShowWindow(SW_HIDE);

	CString asd;
	asd="Tips:";
	s_edit.SetWindowText(asd);
	asd +="\r\n";
	asd +="˫�������޸�����";
	s_edit.SetWindowText(asd);
	asd +="\r\n";
	asd +="�һ�����ɾ������";
	s_edit.SetWindowText(asd);
	asd +="\r\n";
	asd +="�����ɼ�(1,2,3)���Խ�������";
	s_edit.SetWindowText(asd);
	asd +="\r\n";
	asd +="�����һ��Ϊ���򣬣�";
	s_edit.SetWindowText(asd);
	asd +="\r\n";
	asd +="���ٵ�һ��Ϊ����";
	s_edit.SetWindowText(asd);
	asd +="\r\n";
	asd +="���ȷ�����Ա����ļ�";
	s_edit.SetWindowText(asd);

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

#ifndef MARKED
LONG lStyle;
      lStyle = GetWindowLong(myLIST_ShowInfo.m_hWnd, GWL_STYLE);//��ȡ��ǰ����style
      lStyle &= ~LVS_TYPEMASK; //�����ʾ��ʽλ
      lStyle |= LVS_REPORT; //����style
      SetWindowLong(myLIST_ShowInfo.m_hWnd, GWL_STYLE, lStyle);//����style
 
      DWORD dwStyle = myLIST_ShowInfo.GetExtendedStyle();
      dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
      dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��
      dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�
      myLIST_ShowInfo.SetExtendedStyle(dwStyle); //������չ���
	  
		
	  myLIST_ShowInfo.InsertColumn( 0, "ѧ��", LVCFMT_LEFT, 100 );//������
	  myLIST_ShowInfo.InsertColumn( 1, "����", LVCFMT_LEFT, 80 );
	  myLIST_ShowInfo.InsertColumn( 2, "�ɼ�1", LVCFMT_LEFT, 80 );
	  myLIST_ShowInfo.InsertColumn( 3, "�ɼ�2", LVCFMT_LEFT, 80 );
	  myLIST_ShowInfo.InsertColumn( 4, "�ɼ�3", LVCFMT_LEFT, 80 );
	  
	  vecSTDINFO.clear();

	  CString str;
	  for(int i=0; i<myLIST_ShowInfo.GetItemCount(); i++)
	  {
		  if( myLIST_ShowInfo.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
		  {
			  str.Format(_T(" ѡ���˵�%d ��"), i);
			  AfxMessageBox(str);
		  }
	  }

#endif


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_DBDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_DBDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_DBDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//���ļ�
void CMFC_DBDlg::OnBnClickedButtonFileload()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
            CString fileName;
            CFileDialog dlgFile(TRUE);
            OPENFILENAME& ofn = dlgFile.GetOFN( );
            ofn.Flags |= OFN_ALLOWMULTISELECT;
            //ofn.lpstrFile = p;
            //ofn.nMaxFile = FILE_LIST_BUFFER_SIZE;

            if(dlgFile.DoModal() == IDOK)
				{
				fileName = dlgFile.GetPathName();
				char msg[] = "";
				}
			else
				{
				char msg[] = "";
				return;
				}

//-------------------------------------------------------
			vecSTDINFO.clear();
			myLIST_ShowInfo.DeleteAllItems();
	FILE *stream = NULL;
   // Open for read (will fail if file "crt_fopen.c" does not exist)  
   if( (stream  = fopen( fileName, "r" )) == NULL ) // C4996  
   // Note: fopen is deprecated; consider using fopen_s instead  
      printf( "The file 'crt_fopen.c' was not opened errorCODE = %d\n", GetLastError() );  
   else  
      printf( "The file 'crt_fopen.c' was opened\n" ); 
   char buffer[256];
   STUDENT_INFO myInfo;
   int cnt = 1;
  while(fgets(buffer, 255, stream) != NULL)
	{
 	  //¼ȡ�����ݽṹ����---sscanf
	  int rtn = sscanf(buffer, "%s %s %lf %lf %lf", myInfo.ID, myInfo.Name, 
										&myInfo.Score[0], &myInfo.Score[1],&myInfo.Score[2]);
	//---���뵽��������]
	  vecSTDINFO.push_back(myInfo);
	  CString str;
	  if(cnt > 0)
		{
		  myLIST_ShowInfo.InsertItem(cnt - 1, myInfo.ID);
		  myLIST_ShowInfo.SetItemText(cnt - 1, 1, myInfo.Name);
		  str.Format("%.1f", myInfo.Score[0]);
		  myLIST_ShowInfo.SetItemText(cnt - 1, 2, str);
		  str.Format("%.1f", myInfo.Score[1]);
		  myLIST_ShowInfo.SetItemText(cnt - 1, 3, str);
		  str.Format("%.1f", myInfo.Score[2]);
		  myLIST_ShowInfo.SetItemText(cnt - 1, 4, str);
		}
	  cnt++;
	}
  fclose(stream);



 

return;
}

//ɾ��
void CMFC_DBDlg::OnNMRClickListShowinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int rows = pNMItemActivate->iItem;
	if(rows<0)
	{
		MessageBox("����ſհ�ɾ��ι��");
		return;
	}
	else
	{
		if(::MessageBox(m_hWnd,_T("���Ҫɾ����һ����"),_T("��Ϣ��ʾ"),MB_OKCANCEL) == IDCANCEL)
			return;
		vecSTDINFO.erase(vecSTDINFO.begin() + rows );
		Sleep(100);
		Vector_Traverse(vecSTDINFO);
		*pResult = 0;
	}
}

//����
void CMFC_DBDlg::Vector_Traverse(std::vector<STUDENT_INFO> vec)
{
	CString str;
	myLIST_ShowInfo.DeleteAllItems();
	for(int i=0; i< vec.size(); i++)
		{
		  myLIST_ShowInfo.InsertItem(i, vec.at(i).ID);
		  myLIST_ShowInfo.SetItemText(i, 1, vec.at(i).Name);
		  str.Format("%.1f", vec.at(i).Score[0]);
		  myLIST_ShowInfo.SetItemText(i, 2, str);
		  str.Format("%.1f", vec.at(i).Score[1]);
		  myLIST_ShowInfo.SetItemText(i, 3, str);
		  str.Format("%.1f", vec.at(i).Score[2]);
		  myLIST_ShowInfo.SetItemText(i, 4, str);
		}
}

//����
void CMFC_DBDlg::OnBnClickedButtonNewnode()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;

	if(GetDlgItemText(IDC_EDIT_ID, str)==NULL || GetDlgItemText(IDC_EDIT_Name, str)==NULL || GetDlgItemText(IDC_EDIT_Name2, str)==NULL || GetDlgItemText(IDC_EDIT_Name3, str)==NULL || GetDlgItemText(IDC_EDIT_Name4, str)==NULL)
	{
		MessageBox("������������Ϣ��");
		return;
	}

	STUDENT_INFO tmpINFO;
	GetDlgItemText(IDC_EDIT_ID, str);
	strncpy(tmpINFO.ID, str, 16);
	GetDlgItemText(IDC_EDIT_Name, str);
	strncpy(tmpINFO.Name, str, 16);

	score1.GetWindowText(str);
	double a = atof(str.GetBuffer()); 
	tmpINFO.Score[0]=a;

	GetDlgItemText(IDC_EDIT_Name3, str);
	double b = atof(str.GetBuffer()); 
	tmpINFO.Score[1]=b;

	GetDlgItemText(IDC_EDIT_Name4, str);
	double c = atof(str.GetBuffer()); 
	tmpINFO.Score[2]=c;


	vecSTDINFO.push_back(tmpINFO);
	
	Vector_Traverse(vecSTDINFO);
}

//�����ļ�
void CMFC_DBDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	CDialogEx::OnOK();
	if(::MessageBox(m_hWnd,_T("Ҫ���汾��������"),_T("��Ϣ��ʾ"),MB_OKCANCEL) == IDCANCEL)
		return;

	CString fileName;
	CFileDialog dlgFile(TRUE);
	OPENFILENAME& ofn = dlgFile.GetOFN( );
	ofn.Flags |= OFN_ALLOWMULTISELECT;
	//ofn.lpstrFile = p;
	//ofn.nMaxFile = FILE_LIST_BUFFER_SIZE;

	if(dlgFile.DoModal() == IDOK)
	{
		fileName = dlgFile.GetPathName();
		char msg[] = "";
	}
	else
	{
		char msg[] = "";
		return;
	}
	FILE *stream = NULL;
	// Open for read (will fail if file "crt_fopen.c" does not exist)  
	if( (stream  = fopen( fileName, "w+" )) == NULL ) // C4996  
		// Note: fopen is deprecated; consider using fopen_s instead  
		printf( "The file 'crt_fopen.c' was not opened errorCODE = %d\n", GetLastError() );  
	else  
		printf( "The file 'crt_fopen.c' was opened\n" );
	
	
	for(int i=0; i< vecSTDINFO.size(); i++)
	{
		fprintf(stream,"%s          %s      %.3lf     %.3lf     %.3lf", vecSTDINFO.at(i).ID, vecSTDINFO.at(i).Name, 
			vecSTDINFO.at(i).Score[0], vecSTDINFO.at(i).Score[1],vecSTDINFO.at(i).Score[2]);
		fputs("\n",stream);
	}
	fclose (stream);
}

bool GreaterSortScore1 (_STUDENT_INFO a,_STUDENT_INFO b) { return (a.Score[0]>b.Score[0]);}  
bool DecreaseSortScore1 (_STUDENT_INFO a,_STUDENT_INFO b) { return (a.Score[0]<b.Score[0]);}
bool GreaterSortScore2 (_STUDENT_INFO a,_STUDENT_INFO b) { return (a.Score[1]>b.Score[1]);}  
bool DecreaseSortScore2 (_STUDENT_INFO a,_STUDENT_INFO b) { return (a.Score[1]<b.Score[1]);}
bool GreaterSortScore3 (_STUDENT_INFO a,_STUDENT_INFO b) { return (a.Score[2]>b.Score[2]);}  
bool DecreaseSortScore3 (_STUDENT_INFO a,_STUDENT_INFO b) { return (a.Score[2]<b.Score[2]);}

//����
void CMFC_DBDlg::OnHdnItemclickListShowinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: Add your control notification handler code here
	int rows = phdr->iItem;
	*pResult = 0;
	static int i = 0;
	static int j = 0;
	static int k = 0;
	switch(rows)
	{
		case 2:
			if(i==0)
			{
				sort(vecSTDINFO.begin(), vecSTDINFO.end(),GreaterSortScore1);  
				Vector_Traverse(vecSTDINFO);
			}
			else
			{
				sort(vecSTDINFO.begin(), vecSTDINFO.end(),DecreaseSortScore1);  
				Vector_Traverse(vecSTDINFO);
			}
			i++;
			i %=2;
			break;
		case 3:
			if(j==0)
			{
				sort(vecSTDINFO.begin(), vecSTDINFO.end(),GreaterSortScore2);  
				Vector_Traverse(vecSTDINFO);
			}
			else
			{
				sort(vecSTDINFO.begin(), vecSTDINFO.end(),DecreaseSortScore2);  
				Vector_Traverse(vecSTDINFO);
			}
			j++;
			j %=2;
			break;
		case 4:
			if(k==0)
			{
				sort(vecSTDINFO.begin(), vecSTDINFO.end(),GreaterSortScore3);  
				Vector_Traverse(vecSTDINFO);
			}
			else
			{
				sort(vecSTDINFO.begin(), vecSTDINFO.end(),DecreaseSortScore3);  
				Vector_Traverse(vecSTDINFO);
			}
			k++;
			k %=2;
			break;
	}
}

static int m_Row;
static int m_Col;

//˫�����޸�
void CMFC_DBDlg::OnNMDblclkListShowinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	CRect rc;  
	m_Row = pNMItemActivate->iItem;//���ѡ�е���  
	m_Col = pNMItemActivate->iSubItem;//���ѡ����  
	CString s = myLIST_ShowInfo.GetItemText(m_Row,m_Col);
	if(s.GetLength()==0)
	{
		return;
	}
	else
	{
		if(m_Col >= 0) //���ѡ���������;  
		{  
			myLIST_ShowInfo.GetSubItemRect(m_Row,m_Col,LVIR_LABEL,rc);//��������RECT��  
			m_edit.SetParent(&myLIST_ShowInfo);//ת������Ϊ�б���е�����  
			m_edit.MoveWindow(rc);//�ƶ�Edit��RECT���ڵ�λ��;  
			m_edit.SetWindowText(myLIST_ShowInfo.GetItemText(m_Row,m_Col));//���������е�ֵ����Edit�ؼ��У�  
			m_edit.ShowWindow(SW_SHOW);//��ʾEdit�ؼ���  
			m_edit.SetFocus();//����Edit����  
			m_edit.ShowCaret();//��ʾ���  
			m_edit.SetSel(-1);//������ƶ������  
		}  
	}

	*pResult = 0;  
}

//�����޸�����
void CMFC_DBDlg::OnEnKillfocusEditName6()
{
	// TODO: Add your control notification handler code here
	CString tem;
	double a,b,c;
	m_edit.GetWindowText(tem);    //�õ��û�������µ�����  
	//myLIST_ShowInfo.SetItemText(m_Row,m_Col,tem);   //���ñ༭���������  
	m_edit.ShowWindow(SW_HIDE);                //Ӧ�ر༭��  
	switch(m_Col)
	{
		case 0:
			strncpy(vecSTDINFO[m_Row].ID, tem, 16);
			break;
		case 1:
			strncpy(vecSTDINFO[m_Row].Name, tem, 16);
			break;
		case 2:
			a = atof(tem.GetBuffer()); 
			vecSTDINFO[m_Row].Score[0] = a;
			break;
		case 3:
			b = atof(tem.GetBuffer()); 
			vecSTDINFO[m_Row].Score[1] = b;
			break;
		case 4:
			c = atof(tem.GetBuffer()); 
			vecSTDINFO[m_Row].Score[2] = c;
			break;
	}
	Vector_Traverse(vecSTDINFO);
}

