/*
 * QR Code generator demo (C)
 *
 * Run this command-line program with no arguments. The program
 * computes a demonstration QR Codes and print it to the console.
 *
 * Copyright (c) Project Nayuki. (MIT License)
 * https://www.nayuki.io/page/qr-code-generator-library
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * - The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * - The Software is provided "as is", without warranty of any kind, express or
 *   implied, including but not limited to the warranties of merchantability,
 *   fitness for a particular purpose and noninfringement. In no event shall the
 *   authors or copyright holders be liable for any claim, damages or other
 *   liability, whether in an action of contract, tort or otherwise, arising from,
 *   out of or in connection with the Software or the use or other dealings in the
 *   Software.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraries/qrcodegen/qrcodegen.h"


// Function prototypes
static void createQRcode (char *text, uint16_t nb);
static void printQr(const uint8_t qrcode[], char *file);


// The main application program.
int main (int argc, char **argv) {
    uint8_t i ;
    if (argc > 1) {
        for (i = 1 ; i < argc ; ++i) {
            createQRcode(argv[i], i);
        }
    } else {
        printf("No arguments given\n") ;
    }

	return EXIT_SUCCESS;
}


// Creates a single QR Code, then prints it to the console and in a file.
static void createQRcode (char *text, uint16_t nb) {
    char fileName[30] = "" ;
	enum qrcodegen_Ecc errCorLvl = qrcodegen_Ecc_LOW;  // Error correction level

	// Make and print the QR Code symbol
	uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
	uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
	bool ok = qrcodegen_encodeText(text, tempBuffer, qrcode, errCorLvl,
		qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);
	if (ok) {
        sprintf(fileName, "qrCode-%d.txt", nb) ;
		printQr(qrcode, fileName);
    }
}


// Prints the given QR Code to the console.
static void printQr(const uint8_t qrcode[], char *file) {
    FILE *qr = fopen(file, "w");
    if(qr == NULL)
        return ;

    int size = qrcodegen_getSize(qrcode);
    int border = 4;
    for (int y = -border; y < size + border; y++) {
        for (int x = -border; x < size + border; x++) {
            fputs((qrcodegen_getModule(qrcode, x, y) ? "##" : "  "), stdout);
            fputs((qrcodegen_getModule(qrcode, x, y) ? "##" : "  "), qr);
        }
        fputs("\n", stdout);
        fputs("\n", qr);
    }
    fputs("\n", stdout);
    fputs("\n", qr);
}
