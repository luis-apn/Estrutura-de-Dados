inst1 = instncias_grafo/pcv4.txt
inst2 = instncias_grafo/pcv10.txt
inst3 = instncias_grafo/pcv50.txt
inst4 = instncias_grafo/pcv177.txt

all: lib Grafo
	@echo Compilando...
	
	@g++ FilaSeq.o Grafo.o main.cpp -o main

lib: 
	@echo Gerando o Arquivo Objeto...
	@g++ -c Fila_Sequencial/FilaSeq.cpp

Grafo:
	@g++ -c Grafo.cpp

clean:
	@echo Limpando Arquivos Objeto e Executavel...
	@rm *.o main

instancia1:
	@echo Executando a Instancia 1...
	@./main $(inst1)

instancia2:
	@echo Executando a Instancia 2...
	@./main $(inst2)

instancia3:
	@echo Executando a Instancia 3...
	@./main $(inst3)

instancia4:
	@echo Executando a Instancia 4...
	@./main $(inst4)