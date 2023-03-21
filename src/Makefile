CC = gcc
CFLAG = -g
CHECK_LIB = -lcheck
OS:=$(shell uname -s)
CCOV = -lgcov --coverage

LIB_HEADER = SmartCalc.h
LIB = SmartCalc.a
LIB_DIR = lib/
OBJ_DIR = obj/
COV_DIR = coverage_info/
TEST_DIR = tests/
LIB_OBJ_DIR = $(OBJ_DIR)$(LIB_DIR)
COV_OBJ_DIR = $(COV_DIR)$(OBJ_DIR)

APP = SmartCalc
ARCH_NAME = Archive_$(APP)

ifeq ($(UNAME),Darwin)
	APP_NAME = $(APP).app
endif
ifeq ($(UNAME),Linux)
	APP_NAME = $(APP)
	CHECK_LIB += -lrt -lpthread -lm -lsubunit
endif

APP_PATH = build/$(APP_NAME)


LIB_SRCS = $(addprefix $(LIB_DIR),validator.c \
								converter.c \
								calculation.c \
								credit_calc.c)

# TEST_SRCS = $(addprefix $(TEST_DIR)s21_tests.c)

												  
LIB_OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(LIB_SRCS))
COV_OBJS = $(patsubst %.c, $(COV_OBJ_DIR)%.o, $(LIB_SRCS))

TEST_EXEC = test
COV_EXEC = $(COV_DIR)test_cov
COV_INFO = $(COV_DIR)$($(APP)).info
COV_REPORT = $(COV_DIR)/lib/index.html

vpath %.c $(LIB_DIR)


all: install $(LIB) test

install: build
	@mkdir $(HOME)/Desktop/$(APP)/
	@cp -rf $(APP) $(HOME)/Desktop/$(APP)/
	make clean

uninstall:
	@rm -rf $(HOME)/Desktop/$(APP)/


build:
	@mkdir build
	@cd ./lib/ && qmake $(APP).pro && make
	

dvi:
	open instruction.md

dist:
	rm -rf $(ARCH_NAME)
	mkdir $(ARCH_NAME)
	mkdir $(ARCH_NAME)/src
	cp -rf ./lib ./build ./tests Makefile instruction.md $(ARCH_NAME)/src
	tar cvzf $(ARCH_NAME).tgz $(ARCH_NAME)/
	rm -rf $(ARCH_NAME)

test: $(LIB) $(TEST_SRCS)
	$(CC) $(FLAGS) $(INC_DIR) $(TEST_SRCS) $(LIB) $(CHECK_LIB) -o $(TEST_EXEC)


gcov_report: $(LIB) $(TEST_SRCS) $(COV_OBJS)
	$(CC) $(FLAGS) $(INC_DIR) $(CCOV) $(LIB) $^ $(CHECK_LIB) -o $(COV_EXEC)
	@-./$(COV_EXEC)
	@lcov -q -c -d $(COV_DIR) -o $(COV_INFO) --exclude "$(TEST_DIR)*"
	@genhtml -q $(COV_INFO) -o $(COV_DIR)
	@open $(COV_REPORT)
	@rm -rf *.gc*


$(LIB): $(LIB_OBJS)
	ar rc $@ $^
	ranlib $@

$(LIB_OBJ_DIR)%.o: %.c $(LIB_HEADER)
	@mkdir -p $(LIB_OBJ_DIR)
	$(CC) $(FLAGS) $(INC_DIR) -c $< -o $@

$(COV_OBJ_DIR)%.o: %.c $(LIB_HEADER)
	@mkdir -p $(COV_OBJ_DIR)$(LIB_DIR)
	@$(CC) $(FLAGS) $(INC_DIR) $(CCOV) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR) \
		   $(LIB) \
		   $(TEST_EXEC) \
		   $(TEST_EXEC).dSYM \
		   test.log  \
		   $(COV_DIR) \
		   *.gc* \
		   cpp_part \
		   cs_part \
		   data \

