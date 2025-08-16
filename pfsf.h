#ifndef PFSF_H
#define PFSF_H

typedef unsigned int u32;

// Output functions
void printer(const char *s);          // print string
void printer_hex(const unsigned char *data, u32 len); // print bytes as hex 

// Input functions
int scanner(char *buf, u32 maxlen);   // read user input into buf 

#endif /* PFSF_H */
