all: main

STD = g++ -std=c++11
EXECUTE = main
BUSQUEDA = busqueda

busqueda: ./src/busqueda.hh busqueda.cpp main.cpp
	@echo "Compiling algorithms"
	@$(STD) -o $(BUSQUEDA) busqueda.cpp
	@$(STD) -o $(EXECUTE) main.cpp


execute: busqueda
	@echo "Ejecutando algoritmo"
	@./main < ./test/clasificacion.txt >> ./test/prueba.txt
	@./busqueda < ./test/prueba.txt

clean:
	@rm $(EXECUTE)
	@rm $(BUSQUEDA)
