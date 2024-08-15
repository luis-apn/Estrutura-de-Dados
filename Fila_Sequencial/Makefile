all: FilaSeq
	@echo Compilando...
	@g++ FilaSeq.o main.cpp -o main

FilaSeq: 
	@echo Gerando o Arquivo Objeto...
	@g++ -c FilaSeq.cpp

clear:
	@echo Limpando Arquivos...
	@rm FilaSeq.o main

run:
	@echo Executando...
	@./main
