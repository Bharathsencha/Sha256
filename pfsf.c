#include "pfsf.h"

static void putchar_(char c) {
	}

static char getchar_(void) {
    }

void printer_hex(const unsigned char *data, u32 len) {
    static const char hexchars[] = "0123456789abcdef";
    for (u32 i = 0; i < len; i++) {
        unsigned char b = data[i];
        putchar_(hexchars[(b >> 4) & 0xF]);
        putchar_(hexchars[b & 0xF]);
    }
    putchar_('\n');
}

int scanner(char *buf, u32 maxlen) {
    u32 i = 0;
    while (i < maxlen - 1) {
        char c = getchar_();
        if (c == '\r' || c == '\n') break;
        buf[i++] = c;
    }
    buf[i] = '\0';
    return i;
}
