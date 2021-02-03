#Compilation flags
CFLAGS = -Wall -o

#Libraries
LIB_CURL = -l curl
LIB_EXCEL = -l xlsxwriter

#C files
CFILES_UP = upload.c
CFILES_DOWN = download.c
CFILES_QR = qr.c libraries/qrcodegen/qrcodegen.c
CFILES_EXWR = excel.c

#Executable name
EXE_UP = up
EXE_DOWN = down
EXE_QR = qr
EXE_EXWR = excel

upload:
	gcc $(CFLAGS) $(EXE_UP) $(CFILES_UP) $(LIB_CURL)

download:
	gcc $(CFLAGS) $(EXE_DOWN) $(CFILES_DOWN) $(LIB_CURL)

qrcode:
	gcc $(CFLAGS) $(EXE_QR) $(CFILES_QR)

excelwrite:
	gcc $(CFLAGS) $(EXE_EXWR) $(CFILES_EXWR) $(LIB_EXCEL)
