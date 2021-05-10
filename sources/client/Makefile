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

APP = hedwige
app: program
	rm -fr $(APP)
	rm -fr $(APP).app
	mkdir -p $(APP)/Contents/MacOS/exe
	cp main $(APP)/Contents/MacOS/exe
	cp libxl.dylib $(APP)/Contents/MacOS/exe
	cp hedwigeSH $(APP)/Contents/MacOS/$(APP)
	cp -r ../libraries $(APP)/Contents/MacOS/
	chmod +x $(APP)/Contents/MacOS/hedwige

	mkdir $(APP)/qrCodes $(APP)/Excel $(APP)/Contents/Resources
	cp hedwige.icns $(APP)/Contents/Resources/$(APP).icns
	cp Info.plist $(APP)/Contents
	mv $(APP) $(APP).app
	killall Finder