CC=gcc
APP_NAME=SmartCalc
VERSION=1.0
MAKEFILE=Makefile.build
INSTALL_PATH = ${HOME}/Desktop

all: install

install: qmake 
	make -f $(MAKEFILE) install
	cp -R ../build/SmartCalc/SmartCalc.app $(INSTALL_PATH)/$(APP_NAME).app

uninstall:
	-rm -f $(MAKEFILE) 
	-rm -f .qmake.stash
	-rm -rf $(INSTALL_PATH)/$(APP_NAME).app
	-rm -rf ../build

qmake: $(APP_NAME).pro
	qmake -o $(MAKEFILE) $(APP_NAME).pro

rebuild: clean all

clean: 
	-rm -f test test.c *.o *.out *.a *.gc* *.info
	-rm -f .qmake.stash
	-rm -rf opt
	-rm *.gz 
	-rm -rf bin
	-rm -f $(MAKEFILE) 
	-rm -f $(APP_NAME)
	-rm -rf Docs
	-rm -rf $(MAKEFILE)
	-rm -rf ./obj
	-rm -rf ./moc
	-rm -rf $(TEST_EXEC).dSYM
	-rm -rf $(LIB) $(TEST_EXEC) $(COV_EXEC) $(OBJ_DIR) $(COV_INFO) $(COV_REPORT) $(COV_DIR)
	-rm -f test.log
	-rm -rf lib
	-rm -f $(APP_NAME).pro.user

dvi:
	open instruction.html

dist: clean
	tar -czf ../$(APP_NAME)-$(VERSION).tar.gz ./*

distclean: 
	-rm -rf ../$(APP_NAME)-$(VERSION).tar.gz

style:
	cp ../materials/linters/.clang-format ../.clang-format
	clang-format -n -style=Google Controllers/*.cpp \
									Controllers/*.h \
									Controllers/Validators/*.cpp \
									Controllers/Validators/*.h \
									main.cpp \
									Models/*.cpp \
									Models/*.h \
									Services/*.h \
									Services/*.cpp \
									Services/*.c \
									Tests/*.h \
									Tests/*.c \
									Views/*.cpp \
									Views/*.h 

CC = gcc
INC_DIR = -I.
FLAGS = -Wall -Werror -g -fprofile-arcs -ftest-coverage
CHECK_LIB = -lcheck
CCOV = -lgcov --coverage

LIB_HEADER = Services/calc.h
LIB_SRCS = Services/converter.c \
           Services/calculation.c

LIB_OBJS = lib/obj/converter.o \
           lib/obj/calculation.o

LIB_COV_OBJS = lib/Coverage/obj/converter.o \
               lib/Coverage/obj/calculation.o

TEST_SRCS = Tests/BracketExpressionsTests.c \
            Tests/Tests.c \
			Tests/OtherTests.c \
            Tests/TrigonometricFunctionsTests0.c \
            Tests/TrigonometricFunctionsTests1.c \
            Tests/TrigonometricFunctionsTests2.c \
            Tests/TrigonometricFunctionsTests3.c \
            Tests/TrigonometricFunctionsTests4.c \
            Tests/TrigonometricFunctionsTests5.c \
            Tests/TrigonometricFunctionsTests6.c

TEST_OBJS = lib/Coverage/obj/BracketExpressionsTests.o \
            lib/Coverage/obj/Tests.o \
			lib/Coverage/obj/OtherTests.o \
            lib/Coverage/obj/TrigonometricFunctionsTests0.o \
            lib/Coverage/obj/TrigonometricFunctionsTests1.o \
            lib/Coverage/obj/TrigonometricFunctionsTests2.o \
            lib/Coverage/obj/TrigonometricFunctionsTests3.o \
            lib/Coverage/obj/TrigonometricFunctionsTests4.o \
            lib/Coverage/obj/TrigonometricFunctionsTests5.o \
            lib/Coverage/obj/TrigonometricFunctionsTests6.o

TEST_DIR = Tests/
LIB_DIR = lib/
COV_DIR = lib/Coverage/
OBJ_DIR = lib/obj/
COV_OBJ_DIR = lib/Coverage/obj/

LIB = lib/calc.a
COV_EXEC = lib/Coverage/CoverageTest
TEST_EXEC = lib/Test
COV_INFO = lib/Coverage/SmartCalc.info
COV_REPORT = lib/Coverage/index.html

ALL_TEST_SRCS = \
                Tests/BracketExpressionsTests.c \
                Tests/Tests.c \
				Tests/OtherTests.c \
                Tests/TrigonometricFunctionsTests0.c \
                Tests/TrigonometricFunctionsTests1.c \
                Tests/TrigonometricFunctionsTests2.c \
                Tests/TrigonometricFunctionsTests3.c \
                Tests/TrigonometricFunctionsTests4.c \
                Tests/TrigonometricFunctionsTests5.c \
                Tests/TrigonometricFunctionsTests6.c \
                Services/converter.c \
                Services/calculation.c


all: install

test:
	@mkdir -p lib
	$(CC) -g $(CHECK_LIB) $(ALL_TEST_SRCS) $< -o $(TEST_EXEC)
	./$(TEST_EXEC)

gcov_report: $(LIB_COV_OBJS) $(TEST_OBJS)
	@mkdir -p lib/Coverage
	$(CC) $(FLAGS) $(CCOV) $(LIB_COV_OBJS) $(TEST_OBJS) $(CHECK_LIB) -o $(COV_EXEC)
	@-./$(COV_EXEC)
	@lcov -q -c -d $(COV_DIR) -o $(COV_INFO) --exclude "$(TEST_DIR)*" --exclude /usr
	@genhtml -q $(COV_INFO) -o $(COV_DIR)
	@open $(COV_REPORT)
	@rm -rf *.gc*

$(OBJ_DIR)%.o: Services/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC_DIR) -c $< -o $@

$(COV_OBJ_DIR)%.o: Services/%.c
	@mkdir -p $(COV_OBJ_DIR)
	$(CC) $(FLAGS) $(INC_DIR) -c $< -o $@

$(COV_OBJ_DIR)%.o: Tests/%.c
	@mkdir -p $(COV_OBJ_DIR)
	$(CC) $(FLAGS) $(INC_DIR) -c $< -o $@
