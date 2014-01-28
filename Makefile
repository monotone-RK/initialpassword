GCC = gcc -std=c99 -Wall -W -g
TARGET = a.out
SRCS = main.c
BATCHFILE = chpasswd.bat

all:
	$(GCC) $(SRCS)

run:
	./$(TARGET)

clean:
	rm $(TARGET)

# Please do as you like, if you wanna do these following features
# passgen:
# 	./$(TARGET) > $(BATCHFILE)

# setpass:
# 	chpasswd < $(BATCHFILE)

# clean:
# 	rm $(TARGET) $(BATCHFILE)

