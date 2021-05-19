cc=cc
binl=/usr/bin/
manl=/usr/share/man/man1/

tbf2c:
	$(cc) tbf2c.c -o tbf2c

install: tbf2c
	cp tbf2c $(binl)
	cp tbf2c.1.gz $(manl)
