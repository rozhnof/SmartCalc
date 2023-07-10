CC = gcc
FLAGS = -g 
INC_DIR = -L. -I.
CHECK_LIB = -lcheck
OS:=$(shell uname -s)
CCOV = -lgcov --coverage

OBJ_DIR = obj/
COV_DIR = coverage_info/
TEST_DIR = Tests/
LIB_OBJ_DIR = $(OBJ_DIR)$(LIB_DIR)
COV_OBJ_DIR = $(COV_DIR)$(OBJ_DIR)

ifeq ($(OS), Linux)
	CHECK_LIB += -lrt -lpthread -lm -lsubunit
endif

## Make array of all object files for library
LIB_SRCS = $(addprefix $(LIB_DIR),calculation.c \
								  converter.c)

## Make array of all test files
TEST_SRCS = $(addprefix $(TEST_DIR),Tests.c \
									BracketExpressionsTests.c \
									ClearInputTests.c \
									ResultInputValidTests.c \
									SetBracketsValidTests.c \
									SetDotValidTests.c \
									SetFuncValidTests.c \
									SetModValidTests.c \
									SetNumberValidTests.c \
									SetOperatorValidTests.c \
									SetXValidTests.c \
									TrigonometricFunctionsTests0.c \
									TrigonometricFunctionsTests1.c \
									TrigonometricFunctionsTests2.c \
									TrigonometricFunctionsTests3.c \
									TrigonometricFunctionsTests4.c \
									TrigonometricFunctionsTests5.c \
									TrigonometricFunctionsTests6.c)
												  
LIB_OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(LIB_SRCS))
COV_OBJS = $(patsubst %.c, $(COV_OBJ_DIR)%.o, $(LIB_SRCS))

TEST_EXEC = test
COV_EXEC = $(COV_DIR)test_cov
COV_INFO = $(COV_DIR)SmartCalc.info
COV_REPORT = $(COV_DIR)/SmartCalc/index.html

vpath %.c $(LIB_DIR)

all: clean test gcov_report

install: build
	@mkdir $(HOME)/Desktop/$(APP)/
	@cp -rf $(APP) $(HOME)/Desktop/$(APP)/
	make clean

build:
	@mkdir ../build
	@cd ./lib/ && qmake $(APP).pro && make

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
		   data

rebuild: clean all