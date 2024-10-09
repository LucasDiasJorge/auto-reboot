#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t now;
    struct tm *timeinfo;
    int reboot_hour = 20;
    int reboot_minute = 30;
    int seconds_to_wait;

    while (1) {
        time(&now);
        timeinfo = localtime(&now);

        if (timeinfo->tm_hour == reboot_hour && timeinfo->tm_min == reboot_minute) {
            printf("Rebooting system...\n");
            sleep(5);
            system("reboot");
            return 0;
        }

        // Calculate the number of seconds until the next check
        seconds_to_wait = 60 - timeinfo->tm_sec;
        if (timeinfo->tm_min == reboot_minute - 1) {
            // Adjust if we are within a minute of the reboot time
            seconds_to_wait += 60 * ((reboot_minute - timeinfo->tm_min) % 60);
        }

        sleep(seconds_to_wait);  // sleep for the calculated duration
    }

    return 0;
}
