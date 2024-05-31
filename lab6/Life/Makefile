playlife: playlife.o lifefunc.o
	gcc playlife.o lifefunc.o -o playlife

playlife.o: playlife.c lifefunc.h
	gcc -c playlife.c -o playlife.o

lifefunc.o: lifefunc.c lifefunc.h
	gcc -c lifefunc.c -o lifefunc.o

clean:
	rm playlife
	rm *.o

