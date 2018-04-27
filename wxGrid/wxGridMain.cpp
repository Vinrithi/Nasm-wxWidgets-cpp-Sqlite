/***************************************************************
 * Name:      wxGridMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Vinrithi (vinrithi96@gmail.com)
 * Created:   2016-11-08
 * Copyright: Vinrithi ()
 * License:
 **************************************************************/

#include "wxGridMain.h"
#include <wx/msgdlg.h>
#include "dataDisplay.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string>
using namespace std;

//(*InternalHeaders(wxGridFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

/**/

extern "C" {int retrieveData();}
extern "C" {bool executeQuery(char MyQuery[]);}
MY_STRUCT DataArr[1000];
typedef struct Grid
{
    int age;
    char surname[1000];
    char othername[1000];
    char position[1000];
    int id;

}MY_GRID;

MY_GRID MyGrid[1000];
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{

    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxGridFrame)
const long wxGridFrame::ID_TABLE1 = wxNewId();
const long wxGridFrame::ID_STATICTEXT1 = wxNewId();
const long wxGridFrame::ID_REPORT = wxNewId();
const long wxGridFrame::ID_PLID = wxNewId();
const long wxGridFrame::ID_NAME = wxNewId();
const long wxGridFrame::ID_AGE = wxNewId();
const long wxGridFrame::ID_UPDATE = wxNewId();
const long wxGridFrame::ID_STATICTEXT2 = wxNewId();
const long wxGridFrame::ID_STATICTEXT3 = wxNewId();
const long wxGridFrame::ID_STATICTEXT4 = wxNewId();
const long wxGridFrame::ID_STATICTEXT5 = wxNewId();
const long wxGridFrame::ID_DELETE = wxNewId();
const long wxGridFrame::ID_STATICTEXT6 = wxNewId();
const long wxGridFrame::ID_OTHERNAME = wxNewId();
const long wxGridFrame::ID_STATICTEXT7 = wxNewId();
const long wxGridFrame::ID_POSITION = wxNewId();
const long wxGridFrame::ID_PLIDIN = wxNewId();
const long wxGridFrame::ID_SURNAMEIN = wxNewId();
const long wxGridFrame::ID_OTHERNAMEIN = wxNewId();
const long wxGridFrame::ID_AGEIN = wxNewId();
const long wxGridFrame::ID_STATICTEXT8 = wxNewId();
const long wxGridFrame::ID_STATICTEXT9 = wxNewId();
const long wxGridFrame::ID_STATICTEXT11 = wxNewId();
const long wxGridFrame::ID_QUERYBOX = wxNewId();
const long wxGridFrame::ID_INSERT = wxNewId();
const long wxGridFrame::ID_COMBOBOX1 = wxNewId();
const long wxGridFrame::idMenuQuit = wxNewId();
const long wxGridFrame::idMenuAbout = wxNewId();
const long wxGridFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxGridFrame,wxFrame)
    //(*EventTable(wxGridFrame)
    //*)
END_EVENT_TABLE()

wxGridFrame::wxGridFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxGridFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("CHELSEA FOOTBALL CLUB PLAYER\'S DETAILS"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1347,582));
    TABLE1 = new wxGrid(this, ID_TABLE1, wxPoint(16,72), wxSize(664,312), 0, _T("ID_TABLE1"));
    TABLE1->CreateGrid(25,5);
    TABLE1->SetFocus();
    TABLE1->EnableEditing(false);
    TABLE1->EnableGridLines(true);
    TABLE1->SetDefaultColSize(115, true);
    TABLE1->SetColLabelValue(0, _("PL_ID"));
    TABLE1->SetColLabelValue(1, _("SURNAME"));
    TABLE1->SetColLabelValue(2, _("OTHER NAME"));
    TABLE1->SetColLabelValue(3, _("AGE"));
    TABLE1->SetColLabelValue(4, _("POSITION"));
    TABLE1->SetDefaultCellFont( TABLE1->GetFont() );
    TABLE1->SetDefaultCellTextColour( TABLE1->GetForegroundColour() );
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("PLAYERS DATA"), wxPoint(280,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("FreeSerif"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    REPORT = new wxTextCtrl(this, ID_REPORT, wxEmptyString, wxPoint(8,424), wxSize(656,64), 0, wxDefaultValidator, _T("ID_REPORT"));
    wxFont REPORTFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("FreeSans"),wxFONTENCODING_DEFAULT);
    REPORT->SetFont(REPORTFont);
    PL_ID = new wxTextCtrl(this, ID_PLID, wxEmptyString, wxPoint(808,56), wxSize(160,27), 0, wxDefaultValidator, _T("ID_PLID"));
    SURNAME = new wxTextCtrl(this, ID_NAME, wxEmptyString, wxPoint(808,104), wxSize(160,27), 0, wxDefaultValidator, _T("ID_NAME"));
    AGE = new wxTextCtrl(this, ID_AGE, wxEmptyString, wxPoint(808,200), wxSize(160,27), 0, wxDefaultValidator, _T("ID_AGE"));
    UPDATE = new wxButton(this, ID_UPDATE, _("UPDATE"), wxPoint(768,320), wxDefaultSize, 0, wxDefaultValidator, _T("ID_UPDATE"));
    wxFont UPDATEFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    UPDATE->SetFont(UPDATEFont);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("UPDATE/DELETE RECORD"), wxPoint(784,24), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("FreeSerif"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("PL_ID:"), wxPoint(752,56), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("SURNAME:"), wxPoint(720,104), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText4Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("AGE:"), wxPoint(760,200), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxFont StaticText5Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    DELETE = new wxButton(this, ID_DELETE, _("DELETE"), wxPoint(896,320), wxDefaultSize, 0, wxDefaultValidator, _T("ID_DELETE"));
    wxFont DELETEFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    DELETE->SetFont(DELETEFont);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("OTHER NAME:"), wxPoint(696,152), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    wxFont StaticText6Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText6->SetFont(StaticText6Font);
    OTHERNAME = new wxTextCtrl(this, ID_OTHERNAME, wxEmptyString, wxPoint(808,152), wxSize(160,27), 0, wxDefaultValidator, _T("ID_OTHERNAME"));
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("POSITION:"), wxPoint(728,248), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    wxFont StaticText7Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    POSITION = new wxTextCtrl(this, ID_POSITION, wxEmptyString, wxPoint(808,248), wxSize(160,27), 0, wxDefaultValidator, _T("ID_POSITION"));
    PL_IDIN = new wxTextCtrl(this, ID_PLIDIN, wxEmptyString, wxPoint(1064,56), wxSize(160,27), 0, wxDefaultValidator, _T("ID_PLIDIN"));
    SURNAMEIN = new wxTextCtrl(this, ID_SURNAMEIN, wxEmptyString, wxPoint(1064,104), wxSize(160,27), 0, wxDefaultValidator, _T("ID_SURNAMEIN"));
    OTHERNAMEIN = new wxTextCtrl(this, ID_OTHERNAMEIN, wxEmptyString, wxPoint(1064,152), wxSize(160,27), 0, wxDefaultValidator, _T("ID_OTHERNAMEIN"));
    AGEIN = new wxTextCtrl(this, ID_AGEIN, wxEmptyString, wxPoint(1064,200), wxSize(160,27), 0, wxDefaultValidator, _T("ID_AGEIN"));
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("INSERT NEW RECORD"), wxPoint(1064,24), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    wxFont StaticText8Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("FreeSerif"),wxFONTENCODING_DEFAULT);
    StaticText8->SetFont(StaticText8Font);
    StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Transaction Success:"), wxPoint(16,400), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    wxFont StaticText9Font(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText9->SetFont(StaticText9Font);
    StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Query Box:"), wxPoint(984,384), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    wxFont StaticText11Font(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText11->SetFont(StaticText11Font);
    QUERYBOX = new wxTextCtrl(this, ID_QUERYBOX, wxEmptyString, wxPoint(776,424), wxSize(488,64), 0, wxDefaultValidator, _T("ID_QUERYBOX"));
    wxFont QUERYBOXFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("FreeSans"),wxFONTENCODING_DEFAULT);
    QUERYBOX->SetFont(QUERYBOXFont);
    INSERT = new wxButton(this, ID_INSERT, _("INSERT"), wxPoint(1112,320), wxDefaultSize, 0, wxDefaultValidator, _T("ID_INSERT"));
    wxFont INSERTFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    INSERT->SetFont(INSERTFont);
    POSITIONIN = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxPoint(1064,248), wxSize(160,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    POSITIONIN->Append(_("Goalkeeper"));
    POSITIONIN->Append(_("Right back"));
    POSITIONIN->Append(_("Left back"));
    POSITIONIN->Append(_("Stopper"));
    POSITIONIN->Append(_("Sweeper"));
    POSITIONIN->Append(_("Left Midfielder"));
    POSITIONIN->Append(_("Right Midfielder"));
    POSITIONIN->Append(_("Defensive Midfielder"));
    POSITIONIN->Append(_("Forward"));
    POSITIONIN->Append(_("Striker"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TABLE1,wxEVT_GRID_SELECT_CELL,(wxObjectEventFunction)&wxGridFrame::OnSelectCell);
    Connect(ID_UPDATE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxGridFrame::OnUPDATEClick);
    Connect(ID_DELETE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxGridFrame::OnDELETEClick);
    Connect(ID_INSERT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxGridFrame::OnINSERTClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxGridFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxGridFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&wxGridFrame::OnClose);
    //*)

    int x = OnFinishedUpdate();
    if(x==0)
    {
        REPORT->SetValue("Data was successfully retrieved");
    }
    else
    {
		 char Q[1000];
		 strcpy(Q,"Error occurred while retrieving data: ");
		 strcat(Q,DataArr[0].errMessage);
         REPORT->SetValue(Q);
    }
}

wxGridFrame::~wxGridFrame()
{
    //(*Destroy(wxGridFrame)
    //*)
}

void wxGridFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxGridFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxGridFrame::OnClose(wxCloseEvent& event)
{
     Close();
}

int wxGridFrame::OnFinishedUpdate()
{
	//extern int retrieveData();
    int x = retrieveData();
    if(x==-1)
    {
       //
       return -1;
    }
    else
    {
        int c =0;
        while(c<x)
        {
            TABLE1->SetCellValue(c,0,wxString::Format(_("%i"),DataArr[c].id));
            TABLE1->SetCellValue(c,1,wxString::Format(_("%s"),DataArr[c].surname));
            TABLE1->SetCellValue(c,2,wxString::Format(_("%s"),DataArr[c].othername));
            TABLE1->SetCellValue(c,3,wxString::Format(_("%i"),DataArr[c].age));
            TABLE1->SetCellValue(c,4,wxString::Format(_("%s"),DataArr[c].position));
            c++;
        }
        return 0;
    }
    PL_ID->SetEditable(false);
}


void wxGridFrame::OnSHOWClick(wxCommandEvent& event)
{
    OnFinishedUpdate();
}

void wxGridFrame::OnSelectCell(wxGridEvent& event)
{

    char A[10],B[10];
    int row = event.GetRow();

    wxString colId, colSu,colON,colAg,colPo = wxT("");

    for(int i=0;i<5;i++)
    {
         colId = TABLE1->GetCellValue(row,0);
         const char *ascii_colId = (const char*)colId.mb_str(wxConvUTF8);

         colSu = TABLE1->GetCellValue(row,1);
         const char *ascii_colSu = (const char*)colSu.mb_str(wxConvUTF8);

         colON = TABLE1->GetCellValue(row,2);
         const char *ascii_colON = (const char*)colON.mb_str(wxConvUTF8);

         colAg = TABLE1->GetCellValue(row,3);
         const char *ascii_colAg = (const char*)colAg.mb_str(wxConvUTF8);

         colPo = TABLE1->GetCellValue(row,4);
         const char *ascii_colPo = (const char*)colPo.mb_str(wxConvUTF8);

         MyGrid[i].id = atoi(ascii_colId);

         sprintf(A,"%d",MyGrid[i].id);
         strcpy(MyGrid[i].surname,ascii_colSu);
         strcpy(MyGrid[i].othername,ascii_colON);
         MyGrid[i].age = atoi(ascii_colAg);
         sprintf(B,"%d",MyGrid[i].age);
         strcpy(MyGrid[i].position,ascii_colPo);

         SURNAME->SetValue(MyGrid[i].surname);
         PL_ID->SetValue(A);
         AGE->SetValue(B);
         OTHERNAME->SetValue(MyGrid[i].othername);
         POSITION->SetValue(MyGrid[i].position);

    }

}

    void wxGridFrame::OnUPDATEClick(wxCommandEvent& event)
    {
        wxString id = PL_ID->GetValue();
        wxString surname = SURNAME->GetValue();
        wxString age = AGE->GetValue();
        wxString othername = OTHERNAME->GetValue();
        wxString position = POSITION->GetValue();

        wxString xy = wxT("Update Player_Details set SURNAME = '"+surname+"', AGE = "+age+", POSITION = '"+position+"', OTHERNAME = '"+othername+"' where PL_ID = "+id+";");
        string str = (const char*)xy.mb_str(wxConvUTF8);

        QUERYBOX->SetValue(str);

	//extern bool executeQuery(char myQuery[]);

        char tab2[1024];
        strcpy(tab2, str.c_str());

        if(executeQuery(tab2)==true)
        {
            OnFinishedUpdate();
            REPORT->SetValue("Update successfully executed");
        }
        else
        {
			char Q[1000];
			 strcpy(Q,"Update NOT executed: ");
			 strcat(Q,DataArr[0].errMessage);
			 REPORT->SetValue(Q);

        }

        OnFinishedUpdate();
        REPORT->SetEditable(false);

    }

void wxGridFrame::OnDELETEClick(wxCommandEvent& event)
{
        wxString id = PL_ID->GetValue();
        wxString xy = wxT("Delete from Player_Details where PL_ID = "+id+";");
        string str = (const char*)xy.mb_str(wxConvUTF8);

        QUERYBOX->SetValue(str);

        char tab2[1024];
        strcpy(tab2, str.c_str());

	//extern bool executeQuery(char myQuery[]);
        if(executeQuery(tab2)==true)
        {
            OnFinishedUpdate();
            REPORT->SetValue("Record successfully deleted");

        }
        else
        {
			char Q[1000];
			 strcpy(Q,"Record NOT deleted: ");
			 strcat(Q,DataArr[0].errMessage);
			 REPORT->SetValue(Q);

        }
        OnFinishedUpdate();
        REPORT->SetEditable(false);
}


void wxGridFrame::OnINSERTClick(wxCommandEvent& event)
{
        wxString id = PL_IDIN->GetValue();
        wxString surname = SURNAMEIN->GetValue();
        wxString age = AGEIN->GetValue();
        wxString othername = OTHERNAMEIN->GetValue();
        wxString position = POSITIONIN->GetValue();

        wxString xy = wxT("Insert into Player_Details values("+id+",'"+surname+"','"+othername+"',"+age+",'"+position+"');");
        string str = (const char*)xy.mb_str(wxConvUTF8);

        QUERYBOX->SetValue(str);

        char tab2[1024];
        strcpy(tab2, str.c_str());

	//extern bool executeQuery(char myQuery[]);
        if(executeQuery(tab2)==true)
        {
            OnFinishedUpdate();
            REPORT->SetValue("Insertion successfully executed");
        }
        else
        {
			char Q[1000];
			 strcpy(Q,"Insertion NOT executed: ");
			 strcat(Q,DataArr[0].errMessage);
			 REPORT->SetValue(Q);
        }

        OnFinishedUpdate();
        REPORT->SetEditable(false);
}
