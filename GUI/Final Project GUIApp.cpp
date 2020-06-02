//---------------------------------------------------------------------------
//
// Name:        Final Project GUIApp.cpp
// Author:      Eric Edgari , Yowen , William
// Created:     02/06/2020 18:51:57
// Description: 
//
//---------------------------------------------------------------------------

#include "Final Project GUIApp.h"
#include "Final Project GUIFrm.h"

IMPLEMENT_APP(Final_Project_GUIFrmApp)

bool Final_Project_GUIFrmApp::OnInit()
{
    Final_Project_GUIFrm* frame = new Final_Project_GUIFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int Final_Project_GUIFrmApp::OnExit()
{
	return 0;
}
