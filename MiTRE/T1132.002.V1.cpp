// Link      = https://attack.mitre.org/techniques/T1132/002/
// Technique = Data Encoding: Non-Standard Encoding
// ID        = T1132.002
// Tactics   = Command and Control,

#define DATA "Sensitive data that needs to be transmited in a way that noone undestand it"

int main() {
    unsigned char temp[1024];
    unsigned char* p = (unsigned char*)&DATA[0];
    unsigned char key = 0x11;
    unsigned char add = 0x25;
    unsigned int index = 0;
    while ((*p) != 0) {
        temp[index] = ((*p) ^ key) + add;
        index ++;
        p++;
    }

    return 0;
}
