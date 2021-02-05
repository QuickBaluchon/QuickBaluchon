#Compilation flags
CFLAGS = -Wall `pkg-config --cflags gtk+-3.0` -o

#Libraries
LIB_CURL = -l curl
LIB_EXWR = -l xlsxwriter
LIB_XL = -I../libraries/libxl/include_c -L../libraries/libxl/lib -lxl
LIBS = `pkg-config --libs gtk+-3.0`
ALL_LIBS = $(LIBS) $(LIB_CURL) $(LIB_XL) $(LIB_EXWR)

#C files
CFILES_UP = upload.c
CFILES_DOWN = download.c
CFILES_QR = qr.c libraries/qrcodegen/qrcodegen.c
CFILES_EXWR = main.c excel.c gtk.c
CFILES_API = api.c
ALL_FILES = $(CFILES_EXWR) $(CFILES_API)

#Executable name
EXE_UP = up
EXE_DOWN = down
EXE_QR = qr
EXE = main

upload:
	gcc $(CFLAGS) $(EXE_UP) $(CFILES_UP) $(LIB_CURL)

download:
	gcc $(CFLAGS) $(EXE_DOWN) $(CFILES_DOWN) $(LIB_CURL)

qrcode:
	gcc $(CFLAGS) $(EXE_QR) $(CFILES_QR)

program: libxl.dylib
	gcc $(CFLAGS) $(EXE) $(ALL_FILES) $(ALL_LIBS)

libxl.dylib:
	cp ../libraries/libxl/lib/libxl.dylib ./
