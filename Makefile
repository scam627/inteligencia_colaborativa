all: main

STD = g++ -std=c++11
EXECUTE = main
BUSQUEDA = busqueda
INIT = 	initial

busqueda: ./src/busqueda.hh busqueda.cpp main.cpp ./src/initial.cpp
	@echo "Compiling algorithms"
	@$(STD) -o $(BUSQUEDA) busqueda.cpp
	@$(STD) -o $(EXECUTE) main.cpp
	@$(STD) -o $(INIT) ./src/initial.cpp


execute: busqueda
	@echo "Ejecutando algoritmo"
	@ cat ./test/origin.txt > ./test/prueba.txt
	@ cat ./test/init.txt > ./test/clasificacion.txt
	@./initial < ./test/prueba.txt >> ./test/clasificacion.txt
	@./main < ./test/clasificacion.txt >> ./test/prueba.txt
	@./busqueda < ./test/prueba.txt
	@ cat ./test/origin.txt > ./test/prueba.txt
	@ cat ./test/init.txt > ./test/clasificacion.txt

clean:
	@rm $(EXECUTE)
	@rm $(BUSQUEDA)
	@rm $(INIT)
