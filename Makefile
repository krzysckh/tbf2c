cc=cc
binl=/usr/bin/

tbf2c:
	$(cc) tbf2c.c -o tbf2c

install: tbf2c
	cp tbf2c $(binl)
