CFLAGS = -I../libraries/libxl/include_c -L../libraries/libxl/lib -lxl -l mysqlclient -l curl

program: libxl.dylib
	gcc main.c -o main $(CFLAGS)
	cp main /Applications/MAMP/htdocs/QuickBaluchonWeb/main

libxl.dylib:
	cp ../libraries/libxl/lib/libxl.dylib ./
