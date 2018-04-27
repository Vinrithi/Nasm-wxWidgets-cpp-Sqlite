/***************************************************************
 * Name:      wxGridMain.h
 * Purpose:   Defines Application Frame
 * Author:    Vinrithi (vinrithi96@gmail.com)
 * Created:   2016-11-08
 * Copyright: Vinrithi ()
 * License:
 **************************************************************/

#ifndef WXGRIDMAIN_H
#define WXGRIDMAIN_H

//(*Headers(wxGridFrame)
#include <wx/grid.h>
#include <wx/combobox.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class wxGridFrame: public wxFrame
{
    public:

        wxGridFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxGridFrame();

    private:

        //(*Handlers(wxGridFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnGrid1CellLeftClick(wxGridEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnSHOWClick(wxCommandEvent& event);
        void OnSelectCell(wxGridEvent& event);
        void OnUPDATEClick(wxCommandEvent& event);
        void OnDELETEClick(wxCommandEvent& event);
        //void OnTABLE1CellLeftClick(wxCommandEvent& event);
        int OnFinishedUpdate();
        void OnINSERTClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxGridFrame)
        static const long ID_TABLE1;
        static const long ID_STATICTEXT1;
        static const long ID_REPORT;
        static const long ID_PLID;
        static const long ID_NAME;
        static const long ID_AGE;
        static const long ID_UPDATE;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_DELETE;
        static const long ID_STATICTEXT6;
        static const long ID_OTHERNAME;
        static const long ID_STATICTEXT7;
        static const long ID_POSITION;
        static const long ID_PLIDIN;
        static const long ID_SURNAMEIN;
        static const long ID_OTHERNAMEIN;
        static const long ID_AGEIN;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT11;
        static const long ID_QUERYBOX;
        static const long ID_INSERT;
        static const long ID_COMBOBOX1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxGridFrame)
        wxTextCtrl* PL_ID;
        wxTextCtrl* AGEIN;
        wxStatusBar* StatusBar1;
        wxTextCtrl* SURNAME;
        wxTextCtrl* POSITION;
        wxButton* UPDATE;
        wxTextCtrl* REPORT;
        wxTextCtrl* QUERYBOX;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxButton* INSERT;
        wxGrid* TABLE1;
        wxStaticText* StaticText8;
        wxStaticText* StaticText7;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxComboBox* POSITIONIN;
        wxTextCtrl* OTHERNAME;
        wxButton* DELETE;
        wxStaticText* StaticText6;
        wxTextCtrl* AGE;
        wxTextCtrl* PL_IDIN;
        wxTextCtrl* OTHERNAMEIN;
        wxStaticText* StaticText9;
        wxTextCtrl* SURNAMEIN;
        wxStaticText* StaticText11;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXGRIDMAIN_H
