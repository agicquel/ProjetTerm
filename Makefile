CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=genpsw
INCLUDE=-I ./include/
BUILD=#./build/

all: $(EXEC)

$(EXEC): main.o number.o password.o
	@echo "Linkage..."
	$(CC) $(CFLAGS) ./*.o -o ./bin/$(EXEC) $(LDFLAGS)
	@echo "Done !"

main.o:
	@echo "Compiling main.c"
	$(CC) $(CFLAGS) -c ./src/main.c $(INCLUDE) $(BUILD)

clean:
	rm ./*.o

mrproper: clean
	rm -rf ./bin/$(EXEC)

rebuild: mrproper all
