#Compilation flags
CFLAGS = -Wall `pkg-config --cflags gtk+-3.0` -o

#Libraries
LIB_CURL = -l curl
LIB_XL = -I../libraries/libxl/include_c -L../libraries/libxl/lib -lxl
LIBS = `pkg-config --libs gtk+-3.0`
ALL_LIBS = $(LIBS) $(LIB_CURL) $(LIB_XL) $(LIB_EXWR)

#C files
CFILES_QR = qr.c ../libraries/qrcodegen/qrcodegen.c
CFILES_EXWR = main.c excel.c gtk.c
CFILES_API = api.c
ALL_FILES = $(CFILES_EXWR) $(CFILES_API) $(CFILES_QR)

#Executable name
EXE = main

program: libxl.dylib
	gcc $(CFLAGS) $(EXE) $(ALL_FILES) $(ALL_LIBS)

libxl.dylib:
	cp ../libraries/libxl/lib/libxl.dylib ./
