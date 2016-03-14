#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

const int BUF_SIZE = 1024;

int main() {
	char buf[BUF_SIZE];
	int read_cnt, write_cnt;
	while ((read_cnt = read(0, buf, BUF_SIZE)) > 0) {
		write_cnt = 0;
		while (write_cnt < read_cnt) {
			int tmp = write(1, buf, read_cnt);
			if (tmp == -1) {
				printf("%s", "Error in writing");
			}
			write_cnt += tmp;
		}
	}

	if (read_cnt == -1) {
		printf("%s", "Eroor in reading");
	}
	return 0;
}
