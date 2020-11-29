# Makefile

# Variables
DIR=src
USERS=${DIR}/lib/users
PRODUCTS=${DIR}/lib/products
DB=${DIR}/lib/db
HEADERS=${DIR}/headers
OBS=register.o login.o db.o addproducts.o interface.o editproducts.o

# Main build
main: main.o ${OBS} libtools.a
	gcc $< -o main -L. -ltools

# static library libtools
libtools.a: ${OBS}
	ar -rc libtools.a -o *.o && ranlib libtools.a

# object files start here
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

editproducts.o: ${DIR}/lib/products/edit.c ${HEADERS}/edit.h
	gcc -c $<
	
# object files end here

# database seeder
seed: ${DB}/db.c ${HEADERS}/db.h
	gcc ${DB}/gendb.c $< -o seed && touch cart.dat session.dat products.dat users.dat

# backup database
backup_db:
	cp ./*.dat ${DB}

# restore database from backup
restore_db:
	cp ${DB}/*.dat ./

# clean project directory retaining database
clean:
	rm -f *.o *.a main seed

# reset project directory, removing database, nned to be seeded again
reset:
	rm -f *.o main *.dat seed ${DB}/*.dat
