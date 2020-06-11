//---------------------------------------------------------------------------
//
// Name:        Final Project GUIApp.h
// Author:      Eric Edgari , Yowen , William
// Created:     02/06/2020 18:51:57
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __FINAL_PROJECT_GUIFRMApp_h__
#define __FINAL_PROJECT_GUIFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class Final_Project_GUIFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
