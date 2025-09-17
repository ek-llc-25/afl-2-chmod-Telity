#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "perms.h"

void test_permission(uint32_t bits, const char* expected, const char* description) {
    struct perms_t perms;
    perms.rwe_t = bits;
    char *result = fmt_perms(perms);

    if (strcmp(result, expected) == 0) {
        printf("✓ %s: %s\n", description, result);
    } else {
        printf("✗ %s: Expected %s, got %s\n", description, expected, result);
    }
    free(result);
}

int main(void) {
    struct perms_t hello_txt;
    // Set permissions using bitwise OR
    hello_txt.rwe_t = USER_READ | GROUP_READ | OTHERS_READ;

    char *perms = fmt_perms(hello_txt);
    printf("hello.txt har rettighederne %s\n", perms);
    free(perms);

    // Tests
    printf("\nRunning tests:\n");
    test_permission(0, "----------", "No permissions");
    test_permission(USER_READ | USER_WRITE | USER_EXECUTE | GROUP_READ | GROUP_WRITE | GROUP_EXECUTE | OTHERS_READ | OTHERS_WRITE | OTHERS_EXECUTE,
                   "-rwxrwxrwx", "All permissions (777)");
    test_permission(USER_READ | USER_WRITE | GROUP_READ | OTHERS_READ,
                   "-rw-r--r--", "644 permissions");
    test_permission(USER_READ | USER_WRITE | USER_EXECUTE | GROUP_READ | GROUP_EXECUTE | OTHERS_READ | OTHERS_EXECUTE,
                   "-rwxr-xr-x", "755 permissions");
    test_permission(USER_READ | USER_WRITE | USER_EXECUTE,
                   "-rwx------", "700 permissions");
    test_permission(USER_READ, "-r--------", "User read only");
    test_permission(OTHERS_EXECUTE, "---------x", "Others execute only");

    return 0;
}
