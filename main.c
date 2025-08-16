#include <stdio.h>
#include "sha256.h"

int main() {
    const unsigned char msg[] = "abc";
    unsigned char digest[32];
    char hex[65];
    struct sha256_ctx ctx;

    sha256_init(&ctx);
    sha256_update(&ctx, msg, 3);
    sha256_final(&ctx, digest);
    sha256_to_hex(digest, hex);

    printf("sha256(abc) = %s\n", hex);
    return 0;
}

