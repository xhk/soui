// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

#define  Update_Update_Speed		101
#define  Update_Down_Speed			102
#define  Update_Use_Speed			103


class CTrayDlg : public SHostWnd
{
public:
	CTrayDlg();
	~CTrayDlg();


	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);


	void OnTimer(char nIDEvent);							// 定时器

	void OnUseBg();

protected:
	bool OnUseBgMouseHover(EventArgs *e);
	bool OnUseBgMouseLeave(EventArgs *e);

	virtual void OnFinalMessage(HWND hWnd);
	
	virtual void OnLButtonDown(UINT nFlags, CPoint pt);

	virtual void OnLButtonUp(UINT nFlags, CPoint pt);

protected:
	void OnRocketVisibleChange(EventArgs *e);
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_use_bg", OnUseBg)
		EVENT_NAME_HANDLER(L"rocket",EVT_VISIBLECHANGED,OnRocketVisibleChange)
	EVENT_MAP_END()

	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CTrayDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_TIMER(OnTimer)
		MSG_WM_LBUTTONDOWN(OnLButtonDown)
		MSG_WM_LBUTTONUP(OnLButtonUp)


		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;

	int				m_nFullWidth;
	int				m_nFullHeight;
};
