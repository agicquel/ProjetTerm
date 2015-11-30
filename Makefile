CC=gcc
CFLAGS=-Wall 
LDFLAGS=
GTK_CFLAGS='pkg-config --cflags gtk+-2.0'
GTK_LDFLAGS='pkg-config --libs gtk+-2.0'
EXEC=projet
INCLUDE=-I ./include/
BUILD=#./build/

all: $(EXEC)

$(EXEC): main.o
	@echo "Linkage..."
	$(CC) $(CFLAGS) ./*.o -o $(GTK_LDFLAGS) ./bin/$(EXEC)
	@echo "Done !"

main.o:
	@echo "Compiling main.c"
	$(CC) $(CFLAGS) -c ./src/main.c $(GTK_CFLAGS) $(INCLUDE)

clean:
	rm ./*.o

mrproper: clean
	rm -rf ./bin/$(EXEC)

rebuild: mrproper all
