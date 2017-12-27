CC=gcc
TARGET=kayo.c
CFLAGS=-std=c99 -Wall -o signa
signa:kayo.c
	$(CC) $(TARGET) $(CFLAGS)
mura:yumine.c
	gcc yumine.c -Wall -std=c99 -o mura
