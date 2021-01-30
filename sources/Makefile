#Compilation flags
CFLAGS = -Wall -o

#Libraries
LIBS = -l curl

#C files
CFILES_UP = upload.c
CFILES_DOWN = download.c

#Executable name
EXE_UP = up
EXE_DOWN = down

upload:
	gcc $(CFLAGS) $(EXE_UP) $(CFILES_UP) $(LIBS)

download:
	gcc $(CFLAGS) $(EXE_DOWN) $(CFILES_DOWN) $(LIBS)
