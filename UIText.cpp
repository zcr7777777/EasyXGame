#include "UIText.h"
void UIText::drawText(int x, int y, std::wstring s)
{
	settextcolor(BLACK);				 // 设置文本颜色
	LOGFONT f;							 // 定义LOGFONT结构体变量
	gettextstyle(&f);					 // 获取默认字体设置
	f.lfHeight = 30;					 // 设置文本高度
	f.lfWidth = 15;						 // 设置文本宽度
	_tcscpy_s(f.lfFaceName, _T("宋体")); // 设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;	 // 设置输出效果为抗锯齿
	settextstyle(&f);					 // 设置字体样式
	int h = textheight(s.c_str());		 // 获取字高
	int w = textwidth(s.c_str());		 // 获取字宽
	outtextxy(x, y, s.c_str());
}
void UIText::Start()
{
	Render::AddUIRender(std::bind(&UIText::drawText, this, transform.position.x, transform.position.y, text));
}