CC=gcc
CFLAGS=-g -Wall -o 
LDFLAGS=
EXEC=rpi_serv

all: $(EXEC) 

$(EXEC): main.o
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
