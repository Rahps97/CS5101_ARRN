# Makefile

DIR=src

main: main.o register.o db.o login.o ${DIR}/headers/colors.h
	gcc main.o db.o login.o register.o -o main

main.o: ${DIR}/main.c
	gcc -c ${DIR}/main.c

db.o: ${DIR}/lib/db/db.c ${DIR}/headers/userstruct.h
	gcc -c ${DIR}/lib/db/db.c

register.o: ${DIR}/lib/users/register.c ${DIR}/lib/db/db.c ${DIR}/headers/db.h ${DIR}/headers/userstruct.h
	gcc -c ${DIR}/lib/users/register.c

login.o: ${DIR}/lib/users/login.c ${DIR}/lib/db/db.c ${DIR}/headers/db.h ${DIR}/headers/userstruct.h
	gcc -c ${DIR}/lib/users/login.c

seed: ${DIR}/lib/db/db.c ${DIR}/headers/db.h
	gcc ${DIR}/lib/db/gendb.c ${DIR}/lib/db/db.c -o seed 

mv_db:
	mv ./users.dat ${DIR}/lib/db

clean:
	rm -f *.o main users.dat products.dat seed && cp ${DIR}/lib/db/users.dat ./users.dat 2>/dev/null && cp ${DIR}/lib/db/products.dat ./products.dat 2>/dev/null
