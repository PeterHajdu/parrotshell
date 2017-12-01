OBJ = parrot.o

parrot: $(OBJ)
	$(CXX) $(OBJ) -o parrot

clean:
	rm -f *.o parrot

.PHONY: clean
