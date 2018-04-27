/***************************************************************
 * Name:      wxGridApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Vinrithi (vinrithi96@gmail.com)
 * Created:   2016-11-08
 * Copyright: Vinrithi ()
 * License:
 **************************************************************/

#include "wxGridApp.h"

//(*AppHeaders
#include "wxGridMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxGridApp);

bool wxGridApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxGridFrame* Frame = new wxGridFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
