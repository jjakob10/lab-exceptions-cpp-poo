main: main.o empresa.o departamento.o funcionario.o
	g++ -std=c++17 -o main main.o empresa.o departamento.o funcionario.o

main.o: main.cpp departamento.h empresa.h funcionario.h
	g++ -std=c++17 -c -o main.o main.cpp

empresa.o: empresa.cpp empresa.h departamento.h funcionario.h
	g++ -std=c++17 -c -o empresa.o empresa.cpp

departamento.o: departamento.cpp departamento.h funcionario.h
	g++ -std=c++17 -c -o departamento.o departamento.cpp

funcionario.o: funcionario.cpp funcionario.h
	g++ -std=c++17 -c -o funcionario.o funcionario.cpp

run: main
	./main

clean:
	rm *.o main *txt