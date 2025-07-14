#include "UIText.h"
void UIText::drawText(int x, int y, std::wstring s)
{
	settextcolor(BLACK);				 // �����ı���ɫ
	LOGFONT f;							 // ����LOGFONT�ṹ�����
	gettextstyle(&f);					 // ��ȡĬ����������
	f.lfHeight = 30;					 // �����ı��߶�
	f.lfWidth = 15;						 // �����ı����
	_tcscpy_s(f.lfFaceName, _T("����")); // ��������Ϊ����
	f.lfQuality = ANTIALIASED_QUALITY;	 // �������Ч��Ϊ�����
	settextstyle(&f);					 // ����������ʽ
	int h = textheight(s.c_str());		 // ��ȡ�ָ�
	int w = textwidth(s.c_str());		 // ��ȡ�ֿ�
	outtextxy(x, y, s.c_str());
}
void UIText::Start()
{
	Render::AddUIRender(std::bind(&UIText::drawText, this, transform.position.x, transform.position.y, text));
}