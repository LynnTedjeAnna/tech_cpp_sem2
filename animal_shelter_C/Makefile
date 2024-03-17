PROD_DIR := ./product
SHARED_DIR := ./shared
TEST_DIR := ./test
UNITY_FOLDER :=./Unity
RES_DIR := ./ResourceDetector
BUILD_DIR :=./build

PROD_EXEC = main
PROD_DIRS := $(PROD_DIR) $(SHARED_DIR) $(RES_DIR)
PROD_FILES := $(wildcard $(patsubst %,%/*.c, $(PROD_DIRS)))
HEADER_PROD_FILES := $(wildcard $(patsubst %,%/*.h, $(PROD_DIRS)))
PROD_INC_DIRS=-I$(PROD_DIR) -I$(SHARED_DIR) -I$(RES_DIR)

TEST_EXEC = main_test
TEST_DIRS := $(TEST_DIR) $(SHARED_DIR) $(RES_DIR) $(UNITY_FOLDER)
TEST_FILES := $(wildcard $(patsubst %,%/*.c, $(TEST_DIRS)))
HEADER_TEST_FILES := $(wildcard $(patsubst %,%/*.h, $(TEST_DIRS)))
TEST_INC_DIRS=-I$(TEST_DIR) -I$(SHARED_DIR) -I$(UNITY_FOLDER) -I$(RES_DIR)

CC=gcc
SYMBOLS=-Wall -Werror -g -pedantic -O0 -std=c99
TEST_SYMBOLS=$(SYMBOLS) -DTEST -DUNITY_USE_MODULE_SETUP_TEARDOWN

.PHONY: clean test

all: $(PROD_EXEC)

$(PROD_EXEC): Makefile $(PROD_FILES)  $(HEADER_FILES)
	$(CC) $(PROD_INC_DIRS) $(SYMBOLS) $(PROD_FILES) -o $(BUILD_DIR)/$(PROD_EXEC)

$(TEST_EXEC): Makefile $(TEST_FILES)  $(HEADER_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(TEST_FILES) -o $(BUILD_DIR)/$(TEST_EXEC)

run: $(PROD_EXEC)
	@./$(BUILD_DIR)/$(PROD_EXEC)

test: $(TEST_EXEC)
	@./$(BUILD_DIR)/$(TEST_EXEC) administration

testfile : $(TEST_EXEC)
	@./$(BUILD_DIR)/$(TEST_EXEC) file_element

clean:
	rm -f $(BUILD_DIR)/$(PROD_EXEC)
	rm -f $(BUILD_DIR)/$(TEST_EXEC)
