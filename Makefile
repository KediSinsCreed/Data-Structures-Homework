CC = g++
CFLAGS = -I./include -Wall
LDFLAGS = -L./lib
SRC = ./src/*.cpp
EXEC = ./bin/program

hepsi: derle calistir

derle:
	@echo "Derleniyor..."
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXEC) $(SRC)
	@echo "Derleme tamamlandi."

calistir:
	@echo "Program baslatiliyor..."
	@$(EXEC)

temizle:
	del bin\program.exe