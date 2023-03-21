CC = gcc
CFLAG = -g

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


clean: 
	rm -rf build