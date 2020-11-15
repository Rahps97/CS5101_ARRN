# Makefile

DIR=src

main: main.o register.o db.o login.o addproducts.o ${DIR}/headers/colors.h
	gcc main.o db.o login.o register.o addproducts.o -o main

main.o: ${DIR}/main.c
	gcc -c ${DIR}/main.c

db.o: ${DIR}/lib/db/db.c ${DIR}/headers/userstruct.h
	gcc -c ${DIR}/lib/db/db.c

register.o: ${DIR}/lib/users/register.c ${DIR}/lib/db/db.c ${DIR}/headers/db.h ${DIR}/headers/userstruct.h

addproducts.o: ${DIR}/lib/db/db.c ${DIR}/headers/db.h ${DIR}/headers/userstruct.h
	gcc -c ${DIR}/lib/products/addproducts.c

login.o: ${DIR}/lib/users/login.c ${DIR}/lib/db/db.c ${DIR}/headers/db.h ${DIR}/headers/userstruct.h
	gcc -c ${DIR}/lib/users/login.c

seed: ${DIR}/lib/db/db.c ${DIR}/headers/db.h
	gcc ${DIR}/lib/db/gendb.c ${DIR}/lib/db/db.c -o seed 

backup_db:
	cp ./*.dat ${DIR}/lib/db

clean:
	rm -f *.o main seed

reset:
	rm -f *.o main users.dat products.dat seed ${DIR}/lib/db/*.dat
