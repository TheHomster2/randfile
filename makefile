all: randomfile.c
	gcc randomfile.c -o randfile.exe

run: all
	./randfile.exe

clean:
	rm foo
	rm *.out
	rm *~
