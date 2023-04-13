#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t now;
    struct tm *timeinfo;
    int reboot_hour = 20;
    int reboot_minute = 30;

    while (1) {
        time(&now);
        timeinfo = localtime(&now);

        if (timeinfo->tm_hour == reboot_hour && timeinfo->tm_min == reboot_minute) {
            printf("Rebooting system...\n");
            sleep(5);
            system("reboot");
            return 0;
        }

        sleep(60);  // wait 1 minute before checking the time again
    }

    return 0;
}
