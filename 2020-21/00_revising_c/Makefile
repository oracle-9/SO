CC          = gcc
C_STD       = -std=c2x
WARN_FLAGS  = -Wfatal-errors -Wall -Wextra -Wdouble-promotion -Wconversion -Wsign-conversion
OPTI_FLAGS  = -O2 -march=native -mtune=native -flto
DEBUG_FLAGS = -g -O0

SRC_DIR = .
INC_DIR = .
BIN_DIR = bin

SOURCES    = $(shell find $(SRC_DIR) -name '*.c')
HEADERS    = $(shell find $(INC_DIR) -name '*.h')
OBJECTS    = $(patsubst ./%.c, $(BIN_DIR)/%.o, $(SOURCES))

.PHONY: all bin_dir clean

all: bin_dir $(OBJECTS)

clean:
	rm -rf $(BIN_DIR)

bin_dir:
	@mkdir -p $(BIN_DIR)

$(OBJECTS): $(BIN_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(C_STD) $(WARN_FLAGS) $(OPTI_FLAGS) $< -o $@
