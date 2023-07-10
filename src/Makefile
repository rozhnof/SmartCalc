TARGET = build/SmartCalc
MAKEFILE_PATH = Makefile.build

all: $(TARGET)

$(TARGET): $(MAKEFILE_PATH)
	@$(MAKE) -f $<

$(MAKEFILE_PATH): SmartCalc.pro
	@qmake6 $< -o $@

install: $(MAKEFILE_PATH)
	@$(MAKE) -f $< install

uninstall: $(MAKEFILE_PATH)
	@$(MAKE) -f $< uninstall

clean: $(MAKEFILE_PATH)
	@$(MAKE) -f $< clean

dvi: $(MAKEFILE_PATH)
	@$(MAKE) -f $< dvi

dist: $(MAKEFILE_PATH)
	@$(MAKE) -f $< dist

test: $(MAKEFILE_PATH)
	@$(MAKE) -f $< test

gcov_report: $(MAKEFILE_PATH)
	@$(MAKE) -f $< gcov_report

.PHONY: all install uninstall clean dvi dist test gcov_report
