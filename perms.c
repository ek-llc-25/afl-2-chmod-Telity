#include <stdlib.h>
#include "perms.h"

// Forventet output: "-rwx------"
char *fmt_perms(struct perms_t perms) {
    // char out[11]; // NO GO: Jeg må ikke allokere på stakken

    // Fordi jeg returnerer en pointer som skal opstå i funktionen
    // og skal leve længere end funktionen, så er heap-allokering
    // helt oplagt.
    char *out = malloc(11 * sizeof(char));

    out[0] = '-'; // First char is always '-' for regular file

    // User permissions
    out[1] = (perms.rwe_t & USER_READ) ? 'r' : '-';
    out[2] = (perms.rwe_t & USER_WRITE) ? 'w' : '-';
    out[3] = (perms.rwe_t & USER_EXECUTE) ? 'x' : '-';

    // Group permissions
    out[4] = (perms.rwe_t & GROUP_READ) ? 'r' : '-';
    out[5] = (perms.rwe_t & GROUP_WRITE) ? 'w' : '-';
    out[6] = (perms.rwe_t & GROUP_EXECUTE) ? 'x' : '-';

    // Others permissions
    out[7] = (perms.rwe_t & OTHERS_READ) ? 'r' : '-';
    out[8] = (perms.rwe_t & OTHERS_WRITE) ? 'w' : '-';
    out[9] = (perms.rwe_t & OTHERS_EXECUTE) ? 'x' : '-';

    out[10] = '\0';

    return out;
}

char *ny_fmt_perms(struct ny_perms_t perms) {
    char *out = malloc(11 * sizeof(char));

    out[0] = '-';
    // TODO: Find bits'ene inde i 'perms'
    out[10] = '\0';
}
