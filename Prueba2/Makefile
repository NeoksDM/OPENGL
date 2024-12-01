CC = gcc
CFLAGS = -std=c89 -pedantic -Wall -Werror -Wextra -Wconversion -Wfloat-equal -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wmissing-prototypes -Wnested-externs -Wold-style-definition -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes -Wswitch-default -Wundef -Wunreachable-code -Wwrite-strings -Wno-unused-parameter
SRC = main.c fuentes/utilidades_SDL.c 
TARGET = build_pruebas
all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -Iheaders -lSDL2 -lm
clean:
	rm -f $(TARGET)
