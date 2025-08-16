#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sha256.h"

// Function to compute SHA-256 using OpenSSL (for verification)
void openssl_sha256(const char *input, char *openssl_output) {
    char command[2048];
    // Use printf format to avoid shell injection
    snprintf(command, sizeof(command), "echo -n '%s' | openssl dgst -sha256 | awk '{print $2}'", input);
    
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run OpenSSL verification.\n");
        return;
    }
    
    // Read the full hash (64 chars) directly
    fgets(openssl_output, 65, fp);
    pclose(fp);
    
    // Remove trailing newline (if any)
    openssl_output[strcspn(openssl_output, "\n")] = '\0';
}
int main() {
    char user_input[1024];
    unsigned char digest[32];
    char my_hash[65];
    char openssl_hash[65];
    struct sha256_ctx ctx;

    printf("Enter a string to hash: ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; // Remove newline

    // Compute hash using your code
    sha256_init(&ctx);
    sha256_update(&ctx, (const u8 *)user_input, strlen(user_input));
    sha256_final(&ctx, digest);
    sha256_to_hex(digest, my_hash);

    // Get hash using OpenSSL (for verification)
    openssl_sha256(user_input, openssl_hash);

    printf("\nInput: \"%s\"\n", user_input);
    printf("Your SHA-256:    %s\n", my_hash);
    printf("OpenSSL SHA-256: %s\n", openssl_hash);

    // Verify
    if (strcmp(my_hash, openssl_hash) == 0) {
        printf("\nResult: \033[0;32mMATCH (correct)\033[0m\n");
    } else {
        printf("\nResult: \033[0;31mMISMATCH (error)\033[0m\n");
    }

    return 0;
}