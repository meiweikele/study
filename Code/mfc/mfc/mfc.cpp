#include "mfc.h"

MyApp app; //ȫ��Ӧ�ó���������ҽ���һ��

BOOL MyApp::InitInstance()
{
	//��������
	MyFrame * frame = new MyFrame;

	//��ʾ�͸���
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	m_pMainWnd = frame; //����ָ��Ӧ�ó���������ڵ�ָ��

	return TRUE; //����������ʼ��

}

//�ֽ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)

	ON_WM_LBUTTONDOWN() //����������

	ON_WM_CHAR() //����

	ON_WM_PAINT() //��ͼ��

END_MESSAGE_MAP()


MyFrame::MyFrame()
{
	Create(NULL, TEXT("mfc"));
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{

	/*TCHAR buf[1024];
	wsprintf(buf, TEXT("x = %d, y =%d"), point.x, point.y);

	MessageBox(buf);*/

	//mfc�е��ַ���  CString

	CString str;
	str.Format(TEXT("x = %d ,,,, y = %d "), point.x, point.y);

	MessageBox(str);

}

void MyFrame::OnChar(UINT key, UINT, UINT)
{

	CString str;
	str.Format(TEXT("������%c ��"), key);

	MessageBox(str);

}

void MyFrame::OnPaint()
{
	CPaintDC dc(this);  //CDC�����������ܻ���ͼ�� 

	dc.TextOutW(100, 100, TEXT("Ϊ�˲���"));
	//����Բ
	dc.Ellipse(10, 10, 100, 100);

	//���ֽ�תΪ ���ֽ� 
	//TEXT��������Ӧ�����ת��
	// TCHER ����Ӧ�����ת��
	//MessageBox(L"aaa");

	//ͳ���ַ�������
	int num = 0;
	char * p = "aaaa";
	num = strlen(p);

	//ͳ�ƿ��ֽڵ��ַ�������
	wchar_t * p2 = L"bbbb";
	num = wcslen(p2);

	//char * �� CString֮���ת��   C++  string  .c_str();
	//char* -> CString
	char * p3 = "ccc";
	CString str = CString(p3);
	//CString  -> char *
	CStringA tmp;
	tmp = str;
	char * pp = tmp.GetBuffer();



}


//���� 1���ַ���Ӧ1���ֽ� ���ֽ�
// ����  1���ַ���Ӧ����ֽ�  ���ֽ�  Unicode   utf-8 3��  GBK 2��


