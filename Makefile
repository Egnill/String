FOLDER := src/
FOLDER_TWO := build/src/
FOLDER_TEST := build/test/
TARGET := bin/String
CC := gcc
CFLAGS :=  -Wall -Werror -c
EXE_TEST := bin/String_test
LFLAGS := -I thirdparty -I src -c

 
all: $(EXE_TEST) $(TARGET)

$(TARGET): build/src/main.o build/src/Work.o build/src/Strings.o
	$(CC) build/src/main.o build/src/Work.o build/src/Strings.o -o $@

build/src/main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c -o $@

build/src/Work.o: src/Work.c
	$(CC) $(CFLAGS) src/Work.c -o $@

build/src/Strings.o: src/Strings.c
	$(CC) $(CFLAGS) src/Strings.c -o $@

$(EXE_TEST): build/test/Work_Strings_test.o build/test/main.o build/src/Work.o build/src/Strings.o
	$(CC) build/test/Work_Strings_test.o build/test/main.o build/src/Work.o build/src/Strings.o -o $@

build/test/Work_Strings_test.o: test/Work_Strings_test.c
	$(CC) $(LFLAGS) test/Work_Strings_test.c -o $@ 

build/test/main.o: test/main.c 
	$(CC) -I thirdparty -c test/main.c -o $@

.PHONY: all clean
clean:
	rm -f build/src/*.o
	rm -f build/test/*.o
	rm -f bin/*