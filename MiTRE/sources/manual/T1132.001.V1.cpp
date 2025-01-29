// Link      = https://attack.mitre.org/techniques/T1132/001/
// Technique = Data Encoding: Standard Encoding
// ID        = T1132.001
// Tactics   = Command and Control,

#define DATA "Sensitive data that needs to be h hidden that its content can not be read"
#define HEX "0123456789ABCDEF"

int main() {
    unsigned char temp[1024];
    unsigned char* p = (unsigned char *) & DATA[0];
    unsigned int index = 0;
    while ((*p) != 0) {
        temp[index] = HEX[(*p) / 16];
        temp[index + 1] = HEX[(*p) % 16];
        index += 2;
        p++;
    }

    return 0;
}
