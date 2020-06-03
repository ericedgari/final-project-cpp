///-----------------------------------------------------------------
///
/// @file      Final Project GUIFrm.cpp
/// @author    Eric Edgari , Yowen , William
/// Created:   02/06/2020 18:51:57
/// @section   DESCRIPTION
///            Final_Project_GUIFrm class implementation
///
///------------------------------------------------------------------

#include "addnumber.h"
#include "HashMap.h"
#include "avl.h"
#include <iostream>

#include "Final Project GUIFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/Final_Project_GUIFrm_frmNewForm_XPM.xpm"
////Header Include End

//----------------------------------------------------------------------------
// Final_Project_GUIFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Final_Project_GUIFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Final_Project_GUIFrm::OnClose)
	EVT_ACTIVATE(Final_Project_GUIFrm::Final_Project_GUIFrmActivate)
	EVT_BUTTON(ID_TOTAL,Final_Project_GUIFrm::TotalClick)
	
	EVT_TEXT(ID_WXEDIT1,Final_Project_GUIFrm::WxEdit1Updated)
END_EVENT_TABLE()
////Event Table End




Final_Project_GUIFrm::Final_Project_GUIFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
	int n1,n2,sum;
	
    //USING ALL THE IMPORTED
  
	
	//DISPLAYING THE FIRST ITEM 
	n1 = wxAtoi(WxEdit1->GetValue());
    n2 = wxAtoi(WxEdit2->GetValue());
    sum = addFunction(n1,n2);
    
   
    
    WxListCtrl1->InsertItem(1,WxEdit1->GetValue());
    WxListCtrl1->InsertItem(1,WxEdit2->GetValue());
}

Final_Project_GUIFrm::~Final_Project_GUIFrm()
{
}

void Final_Project_GUIFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("ID"), wxPoint(25, 84), wxDefaultSize, 0, _("WxStaticText3"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Name"), wxPoint(17, 48), wxDefaultSize, 0, _("WxStaticText2"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("ID"), wxPoint(-24, 104), wxDefaultSize, 0, _("WxStaticText1"));

	WxListCtrl1 = new wxListCtrl(this, ID_WXLISTCTRL1, wxPoint(44, 134), wxSize(250, 150), wxLC_REPORT, wxDefaultValidator, _("WxListCtrl1"));
	WxListCtrl1->InsertColumn(0, _("ID"), wxLIST_FORMAT_LEFT, 100);
	WxListCtrl1->InsertColumn(1, _("Name"), wxLIST_FORMAT_LEFT, 100);

	Total = new wxButton(this, ID_TOTAL, _("Total"), wxPoint(236, 50), wxSize(75, 25), 0, wxDefaultValidator, _("Total"));

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("6"), wxPoint(75, 82), wxSize(121, 19), 0, wxDefaultValidator, _("WxEdit2"));

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("Jack"), wxPoint(75, 45), wxSize(121, 19), 0, wxDefaultValidator, _("WxEdit1"));

	SetTitle(_("Final Project GUI"));
	SetIcon(Final_Project_GUIFrm_frmNewForm_XPM);
	SetSize(8,8,501,396);
	Center();
	
	////GUI Items Creation End
}

void Final_Project_GUIFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * Final_Project_GUIFrmActivate
 */
void Final_Project_GUIFrm::Final_Project_GUIFrmActivate(wxActivateEvent& event)
{
	// insert your code here
}

/*
 * TotalClick
 */
void Final_Project_GUIFrm::TotalClick(wxCommandEvent& event)
{
	// insert your code here
	AVLTree myTree;
    Hash myHash;
	 
    std::string name = std::string(WxEdit1->GetValue().mb_str());
	int id =wxAtoi(WxEdit2->GetValue());
	std::string stlstring = "Hello world";
// assuming your string is encoded as the current locale encoding (wxConvLibc)
    wxString mystring(stlstring);
    int myint = 89;
    wxString thestring;
    thestring << myint;
    
    
    
    myTree.insert(id,name);
    myHash.insertItem(name,id);
    
   
   // THE LOGIC ON INSERTING TO THE LISTCONTROL  
    WxListCtrl1->DeleteAllItems();
    WxListCtrl1->InsertItem(0,WxEdit1->GetValue());
    WxListCtrl1->SetItem(0,1,WxEdit2->GetValue());
    WxListCtrl1->InsertItem(1,mystring);
    WxListCtrl1->SetItem(1,1,thestring);
    
    //WxListCtrl1->SetItem(0,0,WxEdit2->GetValue());
    
    
    
   
}

/*
 * WxEdit1Updated
 */
void Final_Project_GUIFrm::WxEdit1Updated(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxListBox1Selected
 */
void Final_Project_GUIFrm::WxListBox1Selected(wxCommandEvent& event)
{
	// insert your code here
}




