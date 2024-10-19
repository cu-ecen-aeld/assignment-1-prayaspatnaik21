#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Check if both arguments are provided
    if (argc != 3) {
        syslog(LOG_ERR, "Error: Two arguments required. First: path to file, Second: text string to write.");
        printf("Error: Two arguments required. First: path to file, Second: text string to write.\n");
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open syslog with LOG_USER facility
    openlog("writer", LOG_PERROR | LOG_PID, LOG_USER);

    // Try to open the file for writing
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error: Could not open file %s for writing: %s", writefile, strerror(errno));
        return 1;
    }

    // Write the string to the file
    if (fprintf(file, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error: Could not write to file %s: %s", writefile, strerror(errno));
        fclose(file);
        return 1;
    }

    // Log the successful write operation
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);

    // Close the file
    fclose(file);

    // Close syslog
    closelog();

    return 0;
}
