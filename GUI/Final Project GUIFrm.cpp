///-----------------------------------------------------------------
///
/// @file      Final Project GUIFrm.cpp
/// @author    Eric Edgari , Yowen , William
/// Created:   02/06/2020 18:51:57
/// @section   DESCRIPTION
///            Final_Project_GUIFrm class implementation
///
///------------------------------------------------------------------

#include <algorithm>
#include "Messages.h"

#include "Final Project GUIFrm.h"
#include<iostream>
using namespace std;

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
	EVT_BUTTON(ID_WXBUTTON3,Final_Project_GUIFrm::WxButton3Click)
	EVT_BUTTON(ID_WXBUTTON2,Final_Project_GUIFrm::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON1,Final_Project_GUIFrm::WxButton1Click)
	

	EVT_BUTTON(ID_ADD,Final_Project_GUIFrm::TotalClick)
	
	EVT_TEXT(ID_WXEDIT1,Final_Project_GUIFrm::WxEdit1Updated)
END_EVENT_TABLE()
////Event Table End




Final_Project_GUIFrm::Final_Project_GUIFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
	
	
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

	WxButton3 = new wxButton(this, ID_WXBUTTON3, _("Delete"), wxPoint(321, 42), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton3"));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, _("Refresh"), wxPoint(321, 80), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton2"));

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Search"), wxPoint(230, 80), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("ID"), wxPoint(25, 84), wxDefaultSize, 0, _("WxStaticText3"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Name"), wxPoint(17, 48), wxDefaultSize, 0, _("WxStaticText2"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("ID"), wxPoint(-24, 104), wxDefaultSize, 0, _("WxStaticText1"));

	WxListCtrl1 = new wxListCtrl(this, ID_WXLISTCTRL1, wxPoint(62, 125), wxSize(250, 150), wxLC_REPORT, wxDefaultValidator, _("WxListCtrl1"));
	WxListCtrl1->InsertColumn(0, _("ID"), wxLIST_FORMAT_LEFT, 100);
	WxListCtrl1->InsertColumn(1, _("Name"), wxLIST_FORMAT_LEFT, 140);

	Add = new wxButton(this, ID_ADD, _("Add"), wxPoint(231, 40), wxSize(75, 25), 0, wxDefaultValidator, _("Add"));

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("6"), wxPoint(75, 82), wxSize(121, 19), 0, wxDefaultValidator, _("WxEdit2"));

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("Jack"), wxPoint(75, 45), wxSize(121, 19), 0, wxDefaultValidator, _("WxEdit1"));

	SetTitle(_("Final Project GUI"));
	SetIcon(Final_Project_GUIFrm_frmNewForm_XPM);
	SetSize(8,8,504,396);
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

}

/*
 * TotalClick
 */
void Final_Project_GUIFrm::TotalClick(wxCommandEvent& event)
{
	// insert your code here
	
	// this is the function to add id and name to the list , 
	//the procedure =  clear the items in the list box , get name and id on the text entry 
    // if the id is not a negative and not more than 9 interger , the AVL tree and hashlist will be updated with the name and id 
	WxListCtrl1->DeleteAllItems();
	string name = string(WxEdit1->GetValue().mb_str());
	int id = wxAtoi(WxEdit2->GetValue());
	if(id <0){
                    errorMessage("ID cannot be a negative number");
          
                    }

    else if (id>999999999){
                    errorMessage("ID cannot be longer than 9 integers");
                    }
    else{
                    
	updateTree(id,name);	
    updateListBox();
}
   
}



/*
 * WxEdit1Updated
 */
void Final_Project_GUIFrm::WxEdit1Updated(wxCommandEvent& event)
{
	// insert your code here
}


    
void Final_Project_GUIFrm::updateTree(int id , string name){
    
    // this is the function to insert the name and id to the tree and the hashlist
    myTree.insert(id,name);
    myHash.insertItem(name,id);

}
void Final_Project_GUIFrm::updateListBox(){
    
    // this is the function to update list box 
    // it uses the vector container to take the data that the tree and hash list provided 
    // after getting the data from the tree and hash , it will be inserted to the listbox
    
    vector<int> idList = myTree.getIdList();
    vector<string> nameList = myTree.getNameList();
    
    
    
    
    for (int i = 0 ; i < idList.size();i++){
        
        wxString id;
        id<<idList[i];
        WxListCtrl1->InsertItem(i,id);
        
        wxString name(nameList[i]);;
        
        WxListCtrl1->SetItem(i,1,name);
        
        
        }
        
    }
    

string Final_Project_GUIFrm::searchById(int id ){
    // this is the function for searching the data by id 
    // takes a vector and use a simple search algorithm 
    // if the vector contained the id , it will get the same index in the namelist
    // if not it will return a no result string
    vector<int> idList = myTree.getIdList();
    vector<string> nameList = myTree.getNameList();
    string name;
    if(myTree.search(id) != "NAN"){
                    for (int i =0 ;i<idList.size();i++){
                        if(idList[i]==id){
                            name = nameList[i];
                            }
                        }
                    return name ;
                    
                }
                else{
                    name = "No Result!!!";
                    return name;
                    }
    }
    
int Final_Project_GUIFrm::searchByName(string name ){
        // this is the function for searching the data by name 
    // takes a vector and use a simple search algorithm 
    // if the vector contained the name , it will get the same index in the idlist
    // if not it will return a -1 value
    vector<int> idList = myTree.getIdList();
    vector<string> nameList = myTree.getNameList();
    int id;
    if(myHash.searchName(name) == -1){
                    id = -1;
                    return id;
                    
                }
                else{
                    id = myHash.searchName(name);
                    return id;
                                  }
    }
    

void Final_Project_GUIFrm::updateListBoxSearch(int id, string name){
    // this function works after the search algorithm run
    // it will update the listbox with search item
        WxListCtrl1->DeleteAllItems();
        wxString theId;
        if(id == -1){
            theId = "No Result!!!";
            }
        else{
            theId<<id;
            }
        WxListCtrl1->InsertItem(0,theId);
        
        wxString theName(name);
        WxListCtrl1->SetItem(0,1,theName);
        
        
    }


/*
 * WxButton1Click
 */
 

void Final_Project_GUIFrm::errorMessage(string message){
    // a function to create error message by just typing the string
    wxString msg(message); 
    wxMessageBox(msg, _T("Error"),wxOK | wxICON_ERROR, this);
    }
    
void Final_Project_GUIFrm::dialogMessage(string message){
    // a function to create dialog message by just typing the string
    wxString msg(message); 
    wxMessageBox(msg, _T("Delete"),wxOK, this);
    }

 
void Final_Project_GUIFrm::WxButton1Click(wxCommandEvent& event)
{
    // this function works when the search button is clicked 
    // you need to enter only the id or only the name 
    // if not it will generate an error message 
    // if all condition fulfilled it will , run the updatelistbox search function
    // and the search function to generate the result to the listbox
    int id;
    string name;
    
    if(!WxEdit1->IsEmpty() && !WxEdit2->IsEmpty()){
        errorMessage("Please enter ID or Name");

        WxListCtrl1->DeleteAllItems();
        updateListBox();
        }
    else if (WxEdit1->IsEmpty() && WxEdit2->IsEmpty()){
        errorMessage("Please enter ID or Name");
        WxListCtrl1 ->DeleteAllItems();
        updateListBox();
        }    
        
    else{
            if(WxEdit1->IsEmpty()){
                id = wxAtoi(WxEdit2->GetValue());
                name = searchById(id);
                if(name == "No Result!!!"){
                    errorMessage("Name does not exist");
                    }
                else{
                    updateListBoxSearch(id,name);    
                    }
                
                }
            else if(WxEdit2->IsEmpty()){
                name = string(WxEdit1->GetValue().mb_str());
                id = searchByName(name);
                
                if(id == -1){
                    errorMessage("ID does not exist");
                    }
                else{
                     updateListBoxSearch(id,name);
                    }
               
                }    
        }    
    
}


/*
 * WxButton2Click
 */
void Final_Project_GUIFrm::WxButton2Click(wxCommandEvent& event)
{
    // this is a function update the list box after you search 
    // to make the listbox display the default result 
	WxListCtrl1 ->DeleteAllItems();
    updateListBox();
}



/*
 * WxButton3Click
 */
void Final_Project_GUIFrm::WxButton3Click(wxCommandEvent& event)
{
       // this is the function for the delete button 
       // it only accepts ID only , if not it will generate error message 
       // if condition fulfilled it will , search the data in the tree and hash 
       // and delete it 
       // after that it will updatethevector that the GUI using 
       // to provide the new result 
       // and at last it will generate a messagedialog that the id is succesfully deleted
       
	// making delete function 
	if(!WxEdit2->IsEmpty() && WxEdit1->IsEmpty()){
        int id = wxAtoi(WxEdit2->GetValue());
        string result_string = myTree.search(id);
        if(result_string == "NAN"){
            errorMessage("ID does not exist!");
            }
        
        else{
            myTree.remove(id);
            myHash.delete_string(result_string);
            dialogMessage("ID DELETED");
            }
        }
        
    else{
        errorMessage("Please enter ID ONLY");
    }
    
    
    myTree.updateVector();
    WxListCtrl1 ->DeleteAllItems();
    updateListBox();
    
    
	
}
