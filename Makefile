OBJ = parrot.o

parrot: $(OBJ)
	$(CC) $(OBJ) -o parrot

FAKEROOT = build
BIN = $(FAKEROOT)/usr/bin
deb: parrot
	mkdir -p $(BIN)
	cp parrot $(BIN)
	dpkg-deb --build . parrot.deb

clean:
	rm -rf *.o parrot *.deb build

.PHONY: clean
