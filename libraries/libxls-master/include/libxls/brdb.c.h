/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Copyright 2004 Komarov Valery
 * Copyright 2006 Christophe Leitienne
 * Copyright 2008-2017 David Hoerl
 * Copyright 2013 Bob Colbert
 * Copyright 2013-2018 Evan Miller
 *
 * This file is part of libxls -- A multiplatform, C/C++ library for parsing
 * Excel(TM) files.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ''AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

{ 0x00, "Unknown",	""},
{ 0x06, "FORMULA",	"Cell Formula" },
{ 0x09, "BOF-BIFF2",	"Beginning of File" },
{ 0x0A, "EOF",	"End of File" },
{ 0x0C, "CALCCOUNT",	"Iteration Count" },
{ 0x0D, "CALCMODE",	"Calculation Mode" },
{ 0x0E, "PRECISION",	"Precision" },
{ 0x0F, "REFMODE",	"Reference Mode" },
{ 0x10, "DELTA",	"Iteration Increment" },
{ 0x11, "ITERATION",	"Iteration Mode" },
{ 0x12, "PROTECT",	"Protection Flag" },
{ 0x13, "PASSWORD",	"Protection Password" },
{ 0x14, "HEADER",	"Print Header on Each Page" },
{ 0x15, "FOOTER",	"Print Footer on Each Page" },
{ 0x16, "EXTERNCOUNT",	"Number of External References" },
{ 0x17, "EXTERNSHEET",	"External Reference" },
{ 0x18, "DEFINEDNAME",	"User Defined Formulas (and others)" },
{ 0x19, "?WINDOWPROTECT",	" (biffview guessed)" },
{ 0x1A, "VERTICALPAGEBREAKS",	"Explicit Column Page Breaks" },
{ 0x1B, "HORIZONTALPAGEBREAKS",	"Explicit Row Page Breaks" },
{ 0x1C, "NOTE",	"Comment Associated with a Cell" },
{ 0x1D, "SELECTION",	"Current Selection" },
{ 0x22, "DATEMODE",	"1904 Date System" },
{ 0x26, "LEFTMARGIN",	"Left Margin Measurement" },
{ 0x27, "RIGHTMARGIN",	"Right Margin Measurement" },
{ 0x28, "TOPMARGIN",	"Top Margin Measurement" },
{ 0x29, "BOTTOMMARGIN",	"Bottom Margin Measurement" },
{ 0x2A, "PRINTHEADERS",	"Print Row/Column Labels" },
{ 0x2B, "PRINTGRIDLINES",	"Print Gridlines Flag" },
{ 0x2F, "FILEPASS",	"File Is Password-Protected" },
{ 0x31, "FONT",	"Font Description" },
{ 0x3C, "CONTINUE",	"Continues Long Records" },
{ 0x3D, "WINDOW1",	"Window Information" },
{ 0x40, "BACKUP",	"Save Backup Version of the File" },
{ 0x41, "PANE",	"Number of Panes and Their Position" },
{ 0x42, "CODEPAGE",	"Default Code Page" },
{ 0x4D, "PLS",	"Environment-Specific Print Record" },
{ 0x50, "DCON",	"Data Consolidation Information" },
{ 0x51, "DCONREF",	"Data Consolidation References" },
{ 0x52, "DCONNAME",	"Data Consolidation Named References" },
{ 0x55, "DEFCOLWIDTH",	"Default Width for Columns" },
{ 0x59, "XCT",	"CRN Record Count" },
{ 0x5A, "CRN",	"Nonresident Operands" },
{ 0x5B, "FILESHARING",	"File-Sharing Information" },
{ 0x5C, "WRITEACCESS",	"Write Access User Name" },
{ 0x5D, "OBJ",	"Describes a Graphic Object" },
{ 0x5E, "UNCALCED",	"Recalculation Status" },
{ 0x5F, "SAVERECALC",	"Recalculate Before Save" },
{ 0x60, "TEMPLATE",	"Workbook Is a Template" },
{ 0x63, "OBJPROTECT",	"Objects Are Protected" },
{ 0x7D, "COLINFO",	"Column Formatting Information" },
{ 0x7F, "IMDATA",	"Image Data" },
{ 0x80, "GUTS",	"Size of Row and Column Gutters" },
{ 0x81, "WSBOOL",	"Additional Workspace Information" },
{ 0x82, "GRIDSET",	"State Change of Gridlines Option" },
{ 0x83, "HCENTER",	"Center Between Horizontal Margins" },
{ 0x84, "VCENTER",	"Center Between Vertical Margins" },
{ 0x85, "BOUNDSHEET",	"Sheet Information" },
{ 0x86, "WRITEPROT",	"Workbook Is Write-Protected" },
{ 0x87, "ADDIN",	"Workbook Is an Add-in Macro" },
{ 0x88, "EDG",	"Edition Globals" },
{ 0x89, "PUB",	"Publisher" },
{ 0x8C, "COUNTRY",	"Default Country and WIN.INI Country" },
{ 0x8D, "HIDEOBJ",	"Object Display Options" },
{ 0x90, "SORT",	"Sorting Options" },
{ 0x91, "SUB",	"Subscriber" },
{ 0x92, "PALETTE",	"Color Palette Definition" },
{ 0x94, "LHRECORD",	".WK? File Conversion Information" },
{ 0x95, "LHNGRAPH",	"Named Graph Information" },
{ 0x96, "SOUND",	"Sound Note" },
{ 0x99, "STANDARDWIDTH",	"Standard Column Width" },
{ 0x98, "LPR",	"Sheet Was Printed Using LINE.PRINT" },
{ 0x9A, "FNGROUPNAME",	"Function Group Name" },
{ 0x9B, "FILTERMODE",	"Sheet Contains Filtered List" },
{ 0x9C, "FNGROUPCOUNT",	"Built-in Function Group Count" },
{ 0x9D, "AUTOFILTERINFO",	"Drop-Down Arrow Count" },
{ 0x9E, "AUTOFILTER",	"AutoFilter Data" },
{ 0xA0, "SCL",	"Window Zoom Magnification" },
{ 0xA1, "SETUP",	"Page Setup" },
{ 0xA9, "COORDLIST",	"Polygon Object Vertex Coordinates" },
{ 0xAB, "GCW",	"Global Column-Width Flags" },
{ 0xAE, "SCENMAN",	"Scenario Output Data" },
{ 0xAF, "SCENARIO",	"Scenario Data" },
{ 0xB0, "SXVIEW",	"View Definition" },
{ 0xB1, "SXVD",	"View Fields" },
{ 0xB2, "SXVI",	"View Item" },
{ 0xB4, "SXIVD",	"Row/Column Field IDs" },
{ 0xB5, "SXLI",	"Line Item Array" },
{ 0xB6, "SXPI",	"Page Item" },
{ 0xB8, "DOCROUTE",	"Routing Slip Information" },
{ 0xB9, "RECIPNAME",	"Recipient Name" },
{ 0xBC, "SHRFMLA",	"Shared Formula" },
{ 0xBD, "MULRK",	"Multiple RK Cells" },
{ 0xBE, "MULBLANK",	"Multiple Blank Cells" },
{ 0xC1, "MMS",	"ADDMENU/DELMENU Record Group Count" },
{ 0xC2, "ADDMENU",	"Menu Addition" },
{ 0xC3, "DELMENU",	"Menu Deletion" },
{ 0xC5, "SXDI",	"Data Item" },
{ 0xC6, "SXDB",	"PivotTable Cache Data" },
{ 0xCD, "SXSTRING",	"String" },
{ 0xD0, "SXTBL",	"Multiple Consolidation Source Info" },
{ 0xD1, "SXTBRGIITM",	"Page Item Name Count" },
{ 0xD2, "SXTBPG",	"Page Item Indexes" },
{ 0xD3, "OBPROJ",	"Visual Basic Project" },
{ 0xD5, "SXIDSTM",	"Stream ID" },
{ 0xD6, "RSTRING",	"Cell with Character Formatting" },
{ 0xD7, "DBCELL",	"Stream Offsets" },
{ 0xDA, "BOOKBOOL",	"Workbook Option Flag" },
{ 0xDC, "PARAMQRY-SXEXT",	"Query Parameters-External Source Information" },
{ 0xDD, "SCENPROTECT",	"Scenario Protection" },
{ 0xDE, "OLESIZE",	"Size of OLE Object" },
{ 0xDF, "UDDESC",	"Description String for Chart Autoformat" },
{ 0xE0, "XF",	"Extended Format" },
{ 0xE1, "INTERFACEHDR",	"Beginning of User Interface Records" },
{ 0xE2, "INTERFACEEND",	"End of User Interface Records" },
{ 0xE3, "SXVS",	"View Source" },
{ 0xE5, "CSPAN",	"Cells span" },
{ 0xEA, "TABIDCONF",	"Sheet Tab ID of Conflict History" },
{ 0xEB, "MSODRAWINGGROUP",	"Microsoft Office Drawing Group" },
{ 0xEC, "MSODRAWING",	"Microsoft Office Drawing" },
{ 0xED, "MSODRAWINGSELECTION",	"Microsoft Office Drawing Selection" },
{ 0xEF, "PHONETIC-INFO", "Specifies the default format for phonetic strings " },
{ 0xF0, "SXRULE",	"PivotTable Rule Data" },
{ 0xF1, "SXEX",	"PivotTable View Extended Information" },
{ 0xF2, "SXFILT",	"PivotTable Rule Filter" },
{ 0xF6, "SXNAME",	"PivotTable Name" },
{ 0xF7, "SXSELECT",	"PivotTable Selection Information" },
{ 0xF8, "SXPAIR",	"PivotTable Name Pair" },
{ 0xF9, "SXFMLA",	"PivotTable Parsed Expression" },
{ 0xFB, "SXFORMAT",	"PivotTable Format Record" },
{ 0xFC, "SST",	"Shared String Table" },
{ 0xFD, "LABELSST",	"Cell Value, String Constant/SST" },
{ 0xFF, "EXTSST",	"Extended Shared String Table" },
{ 0x100, "SXVDEX",	"Extended PivotTable View Fields" },
{ 0x103, "SXFORMULA",	"PivotTable Formula Record" },
{ 0x122, "SXDBEX",	"PivotTable Cache Data" },
{ 0x13D, "TABID",	"Sheet Tab Index Array" },
{ 0x160, "USESELFS",	"Natural Language Formulas Flag" },
{ 0x161, "DSF",	"Double Stream File" },
{ 0x162, "XL5MODIFY",	"Flag for DSF" },
{ 0x1A5, "FILESHARING2",	"File-Sharing Information for Shared Lists" },
{ 0x1A9, "USERBVIEW",	"Workbook Custom View Settings" },
{ 0x1AA, "USERSVIEWBEGIN",	"Custom View Settings" },
{ 0x1AB, "USERSVIEWEND",	"End of Custom View Records" },
{ 0x1AD, "QSI",	"External Data Range" },
{ 0x1AE, "SUPBOOK",	"Supporting Workbook" },
{ 0x1AF, "PROT4REV",	"Shared Workbook Protection Flag" },
{ 0x1B0, "CONDFMT",	"Conditional Formatting Range Information" },
{ 0x1B1, "CF",	"Conditional Formatting Conditions" },
{ 0x1B2, "DVAL",	"Data Validation Information" },
{ 0x1B5, "DCONBIN",	"Data Consolidation Information" },
{ 0x1B6, "TXO",	"Text Object" },
{ 0x1B7, "REFRESHALL",	"Refresh Flag" },
{ 0x1B8, "HLINK",	"Hyperlink" },
{ 0x1BA, "CODENAME",	"Name of a workbook object," },
{ 0x1BB, "SXFDBTYPE",	"SQL Datatype Identifier" },
{ 0x1BC, "PROT4REVPASS",	"Shared Workbook Protection Password" },
{ 0x1BE, "DV",	"Data Validation Criteria" },
{ 0x1C1, "RECALC_ID", "identifier of the recalculation engine" },
{ 0x200, "DIMENSIONS",	"Cell Table Size" },
{ 0x201, "BLANK",	"Cell Value, Blank Cell" },
{ 0x203, "NUMBER",	"Cell Value, Floating-Point Number" },
{ 0x204, "LABEL",	"Cell Value, String Constant" },
{ 0x205, "BOOLERR",	"Cell Value, Boolean or Error" },
{ 0x207, "STRING",	"String Value of a Formula" },
{ 0x208, "ROW",	"Describes a Row" },
{ 0x209, "BOF-BIFF3",	"Beginning of File" },
{ 0x20B, "INDEX",	"Index Record" },
{ 0x218, "NAME",	"Defined Name" },
{ 0x221, "ARRAY",	"Array-Entered Formula" },
{ 0x223, "EXTERNNAME",	"Externally Referenced Name" },
{ 0x225, "DEFAULTROWHEIGHT",	"Default Row Height" },
{ 0x236, "TABLE",	"Data Table" },
{ 0x23E, "WINDOW2",	"Sheet Window Information" },
{ 0x27E, "RK",	"Cell Value, RK Number" },
{ 0x293, "STYLE",	"Style Information" },
{ 0x409, "BOF-BIFF4",	"Beginning of File" },
{ 0x41E, "FORMAT",	"Number Format" },
{ 0x4BC, "?FORMULA-RELATED=?(BC=SHRFMLA))",	"Formula related, always before there are 0x06 (FORMULA)" },
{ 0x809, "BOF-BIFF5/7/8",	"Beginning of File" },
{ 0x863, "BOOKEXT", "Specifies properties of a workbook file." },
{ 0xFFF, "",	"" },
