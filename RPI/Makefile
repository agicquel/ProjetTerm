CC=gcc
CFLAGS=-Wall --std=c99
LDFLAGS=-lconfig -lpthread -lwiringPi
EXEC=rpi_serv

all: $(EXEC)

$(EXEC): main.o analyse.o configuration.o network.o
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

network.o:
	@echo "Compiling network.c"
	$(CC) $(CFLAGS) -c src/network.c $(INCLUDE)

modules.o
	@echo "Compiling modules.c"
	$(CC) $(CFLAGS) -c src/modules.c $(INCLUDE)

clean:
	rm ./*.o

mrproper: clean
	rm -rf ./bin/$(EXEC)

rebuild: mrproper all
