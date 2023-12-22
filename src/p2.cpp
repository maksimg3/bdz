#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctime>
#include <fcntl.h>
def monitor_memory():
    memory_usage = psutil.virtual_memory().percent
    with open("monitoring.txt", "a") as file:
        file.write(f"Memory usage: {memory_usage}% at {time.strftime('%Y-%m-%d %H:%M:%S')}\n")


def monitor_cpu():
    cpu_usage = psutil.cpu_percent(0.1)
    with open("monitoring.txt", "a") as file:
        file.write(f"CPU usage: {cpu_usage}% at {time.strftime('%Y-%m-%d %H:%M:%S')}\n")


def monitor_disk():
    disk_usage = psutil.disk_usage('/').percent
    with open("monitoring.txt", "a") as file:
        file.write(f"Disk usage: {disk_usage}% at {time.strftime('%Y-%m-%d %H:%M:%S')}\n")


def measure_performance():
    # Some performance measurement code here
    with open("monitoring.txt", "a") as file:
        file.write(f"Performance measurement at {time.strftime('%Y-%m-%d %H:%M:%S')}\n")


def detect_security_threats():
    # Some security threat detection code here
    with open("monitoring.txt", "a") as file:
        file.write(f"Security threats detected at {time.strftime('%Y-%m-%d %H:%M:%S')}\n")


int main() {
    printf(" Результаты мониторинга системы успешно записаны в файл log.txt.\n");
    // Открытие файла log.txt для записи
    int fd = open("../files/log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Дублирование дескриптора файлового дескриптора stdout для записи в файл
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }

    // Отображение информации о системе
    printf("System Monitoring");

    // Код мониторинга системы
    // Выведем информацию о текущем процессе и системном времени
    int pid = getpid();
    printf("Current process ID: %d", pid);
    time_t current_time = time(NULL);
    printf("Current time: %s", ctime(&current_time));

    // Закрытие файла
    close(fd);

    return 0;
}
