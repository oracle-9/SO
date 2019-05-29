_CC             = gcc
_SRC_EXT       = .c
_HEAD_EXT       = .h
_WARN_FLAGS     = --std=c11 -pedantic -W -Wall
_OPTIMIZE_FLAGS = -O2 -march=native
_DEBUG_FLAGS    = -g

_SOURCE_DIR = src
_HEADER_DIR = include
_BIN_DIR    = bin
_OUT_DIR    = out
_DEBUG_DIR  = debug
_DOCS_DIR   = docs
_EXECUTABLE = person.elf

_SOURCES = $(shell find $(_SOURCE_DIR) -name '*$(_SRC_EXT)')
_HEADERS = $(shell find $(_HEADER_DIR) -name '*$(_HEAD_EXT)')

_BUILD_OBJECTS = $(patsubst $(_SOURCE_DIR)/%$(_SRC_EXT), $(_OUT_DIR)/%.o, $(_SOURCES))
_DEBUG_OBJECTS = $(patsubst $(_SOURCE_DIR)/%$(_SRC_EXT), $(_DEBUG_DIR)/%.o, $(_SOURCES))

all: _bin_dir _out_dir $(_BIN_DIR)/$(_EXECUTABLE)

debug: _debug_dir $(_DEBUG_DIR)/$(_EXECUTABLE)

docs: $(_HEADERS)
	doxygen Doxyfile

memcheck: debug
	valgrind --tool=memcheck --leak-check=yes ./$(_DEBUG_DIR)/$(_EXECUTABLE)

clean:
	rm -rf $(_BIN_DIR) $(_OUT_DIR) $(_DEBUG_DIR) $(_DOCS_DIR)


_bin_dir:
	@mkdir -p $(_BIN_DIR)

_out_dir:
	@mkdir -p $(_OUT_DIR)

$(_BIN_DIR)/$(_EXECUTABLE): $(_BUILD_OBJECTS)
	$(_CC) $^ -o $@

$(_BUILD_OBJECTS): $(_OUT_DIR)/%.o : $(_SOURCE_DIR)/%$(_SRC_EXT)
	mkdir -p $(dir $@)
	$(_CC) -c -I$(_HEADER_DIR) $(_WARN_FLAGS) $(_OPTIMIZE_FLAGS) $< -o $@


_debug_dir:
	@mkdir -p $(_DEBUG_DIR)

$(_DEBUG_DIR)/$(_EXECUTABLE): $(_DEBUG_OBJECTS)
	$(_CC) $^ -I$(_HEADER_DIR) -o $@

$(_DEBUG_OBJECTS): $(_DEBUG_DIR)/%.o : $(_SOURCE_DIR)/%$(_SRC_EXT)
	mkdir -p $(dir $@)
	$(_CC) -c -I$(_HEADER_DIR) $(_WARN_FLAGS) $(_DEBUG_FLAGS) $< -o $@
