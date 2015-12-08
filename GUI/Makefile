CC=gcc
CFLAGS=-g -Wall -o 
LDFLAGS=
GTK_FLAGS=-export-dynamic `pkg-config --libs --cflags gtk+-2.0`
EXEC=projet

all: $(EXEC) 

$(EXEC):
	$(CC) $(CFLAGS) ./bin/$(EXEC) ./src/*.c $(GTK_FLAGS)
	@echo "Done !"


clean:
	rm ./*.o

mrproper: clean
	rm -rf ./bin/$(EXEC)

rebuild: mrproper all
