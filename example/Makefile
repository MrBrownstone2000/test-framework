.PHONY: build clean run

build:
	cd .. && $(MAKE)
	g++ -std=c++23 -I .. -c testExample.cpp -o test.o
	g++ -std=c++23 -L ../obj/debug/output -lTestFramework test.o -o test.out

run: build
	LD_LIBRARY_PATH=../obj/debug/output ./test.out

clean:
	rm -f test.o test.out

