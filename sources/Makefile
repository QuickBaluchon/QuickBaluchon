#Compilation flags
CFLAGS = -Wall -o

#Libraries
LIBS = -l curl

#C files
CFILES_UP = upload.c
CFILES_DOWN = download.c
CFILES_QR = qr.c libraries/qrcodegen/qrcodegen.c

#Executable name
EXE_UP = up
EXE_DOWN = down
EXE_QR = qr

upload:
	gcc $(CFLAGS) $(EXE_UP) $(CFILES_UP) $(LIBS)

download:
	gcc $(CFLAGS) $(EXE_DOWN) $(CFILES_DOWN) $(LIBS)

qrcode:
	gcc $(CFLAGS) $(EXE_QR) $(CFILES_QR)
