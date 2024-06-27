#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int check_input(char *buf) {
    if (buf[0] == 'h' && buf[1] == 'e' && buf[2] == 'l' && buf[3] == 'l' && buf[4] == 'o') {
        printf("Bug!!\n");
        return 1;
    }
    else {
        printf("%s\n", buf);
        return 0;
    }
}
// start
// 00100
// I want
// 00000
// 00001
// 00011
void check_tree(char *buf) {

        printf("Looking at Tree\n");
    if (buf[0] == '0') {
        if (buf[1] == '0') {
            if (buf[2] == '0') {
                if (buf[3] == '0') {
                    if (buf[4] == '0') {
                        printf("Path: 00000\n");
                    } else {
                        printf("Path: 00001\n");
                    }
                } else {
                    if (buf[4] == '0') {
                        printf("Path: 00010\n");
                    } else {
                        printf("Path: 00011\n");
                    }
                }
            } else {
                if (buf[3] == '0') {
                    if (buf[4] == '0') {
                        printf("Path: 00100\n");
                    } else {
                        printf("Path: 00101\n");
                    }
                } else {
                    if (buf[4] == '0') {
                        printf("Path: 00110\n");
                    } else {
                        printf("Path: 00111\n");
                    }
                }
            }
        } else {
            if (buf[2] == '0') {
                if (buf[3] == '0') {
                    if (buf[4] == '0') {
                        printf("Path: 01000\n");
                    } else {
                        printf("Path: 01001\n");
                    }
                } else {
                    if (buf[4] == '0') {
                        printf("Path: 01010\n");
                    } else {
                        printf("Path: 01011\n");
                    }
                }
            } else {
                if (buf[3] == '0') {
                    if (buf[4] == '0') {
                        printf("Path: 01100\n");
                    } else {
                        printf("Path: 01101\n");
                    }
                } else {
                    if (buf[4] == '0') {
                        printf("Path: 01110\n");
                    } else {
                        printf("Path: 01111\n");
                    }
                }
            }
        }
    } else {
        if (buf[1] == '0') {
            if (buf[2] == '0') {
                if (buf[3] == '0') {
                    if (buf[4] == '0') {
                        printf("Path: 10000\n");
                    } else {
                        printf("Path: 10001\n");
                    }
                } else {
                    if (buf[4] == '0') {
                        printf("Path: 10010\n");
                    } else {
                        printf("Path: 10011\n");
                    }
                }
            } else {
                if (buf[3] == '0') {
                    if (buf[4] == '0') {
                        printf("Path: 10100\n");
                    } else {
                        printf("Path: 10101\n");
                    }
                } else {
                    if (buf[4] == '0') {
                        printf("Path: 10110\n");
                    } else {
                        printf("Path: 10111\n");
                    }
                }
            }
        } else {
            if (buf[2] == '0') {
                if (buf[3] == '0') {
                    if (buf[4] == '0') {
                        printf("Path: 11000\n");
                    } else {
                        printf("Path: 11001\n");
                    }
                } else {
                    if (buf[4] == '0') {
                        printf("Path: 11010\n");
                    } else {
                        printf("Path: 11011\n");
                    }
                }
            } else {
                if (buf[3] == '0') {
                    if (buf[4] == '0') {
                        printf("Path: 11100\n");
                    } else {
                        printf("Path: 11101\n");
                    }
                } else {
                    if (buf[4] == '0') {
                        printf("Path: 11110\n");
                    } else {
                        printf("Path: 11111\n");
                    }
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s inputfile\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    char buf[64] = {};
    int r = read(fd, buf, 64);
    if (r < 5) {
        fprintf(stderr, "Need at least five characters of input\n");
        return 1;
    }
    buf[63] = '\0';
    
    check_tree(buf);
    return 0;
}
