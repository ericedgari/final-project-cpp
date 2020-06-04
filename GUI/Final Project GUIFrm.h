///-----------------------------------------------------------------
///
/// @file      Final Project GUIFrm.h
/// @author    Eric Edgari , Yowen , William
/// Created:   02/06/2020 18:51:57
/// @section   DESCRIPTION
///            Final_Project_GUIFrm class declaration
///
///------------------------------------------------------------------


#include "HashMap.h"
#include "avl.h"
#ifndef __FINAL_PROJECT_GUIFRM_H__
#define __FINAL_PROJECT_GUIFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/stattext.h>
#include <wx/listctrl.h>
#include <wx/button.h>
#include <wx/textctrl.h>
////Header Include End

////Dialog Style Start
#undef Final_Project_GUIFrm_STYLE
#define Final_Project_GUIFrm_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Final_Project_GUIFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
	    AVLTree myTree;
        Hash myHash;
		
	public:
		Final_Project_GUIFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Final Project GUI"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Final_Project_GUIFrm_STYLE);
		void Final_Project_GUIFrmActivate(wxActivateEvent& event);
		virtual ~Final_Project_GUIFrm();
		void TotalClick(wxCommandEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void WxListBox1Selected(wxCommandEvent& event);
		void createDatabase();
		void updateTree(int id , string name);
		void updateListBox();
		string searchById(int id);
		int searchByName(string name);
		void updateListBoxSearch(int id , string name);
		void WxButton1Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButton1;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxListCtrl *WxListCtrl1;
		wxButton *Add;
		wxTextCtrl *WxEdit2;
		wxTextCtrl *WxEdit1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBUTTON1 = 1011,
			ID_WXSTATICTEXT3 = 1010,
			ID_WXSTATICTEXT2 = 1009,
			ID_WXSTATICTEXT1 = 1008,
			ID_WXLISTCTRL1 = 1007,
			ID_ADD = 1004,
			ID_WXEDIT2 = 1002,
			ID_WXEDIT1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
