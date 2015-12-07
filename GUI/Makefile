CC=gcc
CFLAGS=-Wall 
LDFLAGS=
GTK_FLAGS=`pkg-config --libs --cflags gtk+-2.0`
EXEC=projet
INCLUDE=-I ./include/
BUILD=#./build/

all: $(EXEC) 

$(EXEC):
	$(CC) $(CFLAGS) -o ./bin/$(EXEC) ./src/*.c $(GTK_FLAGS)
	@echo "Done !"


clean:
	rm ./*.o

mrproper: clean
	rm -rf ./bin/$(EXEC)

rebuild: mrproper all
