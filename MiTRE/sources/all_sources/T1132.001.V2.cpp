// Link      = https://attack.mitre.org/techniques/T1132/001/
// Technique = Data Encoding: Standard Encoding
// ID        = T1132.001
// Tactics   = Command and Control,

#define DATA "Sensitive data that needs to be h hidden that its content can not be read"


// Base64
const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main() {
    unsigned char temp[1024];
    int i = 0, j = 0;
    unsigned char* input = (unsigned char*)&DATA[0];
    unsigned char* output = &temp[0];
    int input_len = sizeof(DATA);
    unsigned char byte_array_3[3];
    unsigned char byte_array_4[4];

    while (input_len--) {
        byte_array_3[i++] = *(input++);
        if (i == 3) {
            byte_array_4[0] = (byte_array_3[0] & 0xfc) >> 2;
            byte_array_4[1] = ((byte_array_3[0] & 0x03) << 4) | ((byte_array_3[1] & 0xf0) >> 4);
            byte_array_4[2] = ((byte_array_3[1] & 0x0f) << 2) | ((byte_array_3[2] & 0xc0) >> 6);
            byte_array_4[3] = byte_array_3[2] & 0x3f;

            for (i = 0; i < 4; i++)
                *output++ = base64_table[byte_array_4[i]];

            i = 0;
        }
    }

    if (i > 0) {
        for (int k = i; k < 3; k++)
            byte_array_3[k] = '\0';

        byte_array_4[0] = (byte_array_3[0] & 0xfc) >> 2;
        byte_array_4[1] = ((byte_array_3[0] & 0x03) << 4) | ((byte_array_3[1] & 0xf0) >> 4);
        byte_array_4[2] = ((byte_array_3[1] & 0x0f) << 2) | ((byte_array_3[2] & 0xc0) >> 6);
        byte_array_4[3] = byte_array_3[2] & 0x3f;

        for (int k = 0; k < i + 1; k++)
            *output++ = base64_table[byte_array_4[k]];

        while (i++ < 3)
            *output++ = '=';
    }

    *output = '\0';

    return 0;
}
