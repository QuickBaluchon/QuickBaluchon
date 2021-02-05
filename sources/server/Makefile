CFLAGS = -I../libraries/libxl/include_c -L../libraries/libxl/lib -lxl

program: libxl.dylib
	gcc main.c -o main $(CFLAGS)

libxl.dylib:
	cp ../libraries/libxl/lib/libxl.dylib ./
