# Makefile

DIR=src
USERS=${DIR}/lib/users
PRODUCTS=${DIR}/lib/products
DB=${DIR}/lib/db
HEADERS=${DIR}/headers
OBS=register.o login.o db.o addproducts.o interface.o

main: main.o ${OBS} libtools.a
	gcc $< -o main -L. -ltools

libtools.a: ${OBS}
	ar -rc libtools.a -o *.o && ranlib libtools.a

main.o: ${DIR}/main.c
	gcc -c $<

register.o: ${USERS}/register.c ${DB}/db.c ${HEADERS}/db.h ${HEADERS}/userstruct.h
	gcc -c $<

login.o: ${USERS}/login.c ${DB}/db.c ${HEADERS}/db.h ${HEADERS}/userstruct.h
	gcc -c $<

db.o: ${DB}/db.c ${HEADERS}/userstruct.h
	gcc -c $<

addproducts.o: ${PRODUCTS}/addproducts.c ${DB}/db.c ${HEADERS}/db.h ${HEADERS}/userstruct.h
	gcc -c $<

interface.o: ${DIR}/interface.c ${HEADERS}/interface.h
	gcc -c $<

seed: ${DB}/db.c ${HEADERS}/db.h
	gcc ${DB}/gendb.c $< -o seed 

backup_db:
	cp ./*.dat ${DB}

clean:
	rm -f *.o *.a main seed

reset:
	rm -f *.o main users.dat products.dat seed ${DB}/*.dat
