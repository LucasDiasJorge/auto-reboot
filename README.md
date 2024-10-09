# Reboot Scheduler

This is a simple C program that schedules a system reboot at a specified time. By default, it is set to reboot the system daily at 20:30 (8:30 PM). If you don't have `crontab` set up for managing scheduled tasks, this program can serve as an alternative.

## Features

- Monitors the system time.
- Reboots the system at the specified hour and minute.
- Can be easily modified to change the scheduled reboot time.

## Prerequisites

- A Unix-like operating system (Linux, macOS, etc.)
- GCC or any other C compiler installed on your system.

## Installation

1. **Clone the repository** (if applicable):
   ```bash
   git clone <repository-url>
   cd <repository-name>
   ```

2. **Compile the program**:
   ```bash
   gcc -o reboot_scheduler reboot_scheduler.c
   ```

3. **Run the program**:
   ```bash
   ./reboot_scheduler
   ```

### Note: If You Don't Have `crontab`

If you are unable to set up scheduled tasks using `crontab`, this program provides an effective alternative. It runs continuously in the background, checking the system time every minute. When the specified reboot time is reached, the system will reboot.

You can run this program in a terminal or as a background process. To run it in the background, use:

```bash
./reboot_scheduler &
```

### Important Considerations

- Make sure to run the program with sufficient permissions to execute a reboot (usually requires root privileges). You can use `sudo` if necessary:
  ```bash
  sudo ./reboot_scheduler
  ```

- Be cautious when running this program on production systems, as it will force a reboot without any warning.

## Customization

To change the scheduled reboot time, modify the `reboot_hour` and `reboot_minute` variables in the code:

```c
int reboot_hour = <new_hour>;
int reboot_minute = <new_minute>;
```

Compile the program again after making changes.
