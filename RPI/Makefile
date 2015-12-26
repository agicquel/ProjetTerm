CC=gcc
CFLAGS=-Wall --std=c99
LDFLAGS=-lconfig
EXEC=rpi_serv

all: $(EXEC)

$(EXEC): main.o analyse.o configuration.o
	@echo "Linkage..."
	$(CC) $(CFLAGS) ./*.o -o ./bin/$(EXEC) $(LDFLAGS)
	@echo "Done !"

main.o:
	@echo "Compiling main.c"
	$(CC) $(CFLAGS) -c src/main.c $(INCLUDE)

analyse.o:
	@echo "Compiling analyse.c"
	$(CC) $(CFLAGS) -c src/analyse.c $(INCLUDE)

configuration.o:
	@echo "Compiling configuration.c"
	$(CC) $(CFLAGS) -c src/configuration.c $(INCLUDE)

clean:
	rm ./*.o

mrproper: clean
	rm -rf ./bin/$(EXEC)

rebuild: mrproper all
