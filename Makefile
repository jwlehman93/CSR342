goal: bonds

bonds: bonds.c bonds.h
	gcc -std=gnu99 -g -o bonds bonds.c bonds.h -lm

clean:
	rm -f bonds
