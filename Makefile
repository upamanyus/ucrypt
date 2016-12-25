NAME=ucrypt
CFLAGS=-Wall -pedantic -Werror -std=c11 -g
LDFLAGS=

INCLUDE_DIR=./include
SRC_DIR=./src
BUILD_DIR=./build
BIN_DIR=./bin

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(OBJS) | $(BIN_DIR)
	gcc $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	gcc -c $(CFLAGS) -I $(INCLUDE_DIR) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(BIN_DIR)/$(NAME)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)
