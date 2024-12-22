# Compiler settings
ifeq ($(OS),Windows_NT)
    CC = clang
    CFLAGS = -fopenmp -Wall -O2
    LDFLAGS = -lomp
    EXE = test.exe
else
    CC = gcc
    CFLAGS = -fopenmp -Wall -O2
    LDFLAGS = -fopenmp
    EXE = test
endif

# Source files
SRC = MatrixOMP.cpp

# Build targets
all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Clean target
clean:
ifeq ($(OS),Windows_NT)
	del /F $(EXE)
else
	rm -f $(EXE)
endif

# Run target
run: $(EXE)
	./$(EXE)

# Help target
help:
	@echo "Available targets:"
	@echo "  all    - Build the executable (default)"
	@echo "  clean  - Remove the executable"
	@echo "  run    - Build and run the executable"
	@echo "  help   - Show this help message"

.PHONY: all clean run help