Exec = ./InsertionSort 
DIR = instancias-num/


# Compila o arquivo completo
all:	InsertionSort # Dependencia para a target
	g++ InsertionSort.o main.cpp -o InsertionSort
 
#Gera o arquivo binario o INsertionSort
InsertionSort:
	g++ -c InsertionSort.cpp

run_1000_1:
	$(Exec) $(DIR)num.1000.1.in

run_1000_2:
	$(Exec) $(DIR)num.1000.2.in

run_1000_3:
	$(Exec) $(DIR)num.1000.3.in

run_1000_4:
	$(Exec) $(DIR)num.1000.4.in

run_10000_1:
	$(Exec) $(DIR)num.10000.1.in

run_10000_2:
	$(Exec) $(DIR)num.10000.2.in

run_10000_3:
	$(Exec) $(DIR)num.10000.3.in

run_10000_4:
	$(Exec) $(DIR)num.10000.4.in

run_100000_1:
	$(Exec) $(DIR)num.100000.1.in

run_100000_2:
	$(Exec) $(DIR)num.100000.2.in

run_100000_3:
	$(Exec) $(DIR)num.100000.3.in

run_100000_4:
	$(Exec) $(DIR)num.100000.4.in

clean:
	rm InsertionSort.o InsertionSort