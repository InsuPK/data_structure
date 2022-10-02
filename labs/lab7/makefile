#아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

qsort: quick.o comparator.o printlist.o
	g++ quick.o comparator.o printlist.o -o qsort
quick.o: quick.cpp
	g++ -c -std=c++11 -Wall quick.cpp -I../include
comparator.o: comparator.cpp
	g++ -c -std=c++11 -Wall comparator.cpp
printlist.o: printlist.cpp
	g++ -c -std=c++11 -Wall printlist.cpp
clean:
	rm -f *.o qsort.exe qsort