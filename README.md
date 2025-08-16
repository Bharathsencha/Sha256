1. Fixed the padding bug in sha256_final:
   - Now handles edge cases (56-63 byte lengths) properly
   - Switched to direct padding instead of sha256_update
   - Correctly writes the 64-bit length in big-endian

2. Made the whole thing interactive:
   - Type any string, see both our hash and OpenSSL's
   - Fixed that OpenSSL output truncation bug

3. Testing:
   - Verified against standard test vectors ("abc", "hello")
   - Matches OpenSSL output perfectly now 
