# Компилятор

CC := g++

# Опции компилятора

CFLAGS := -std=c++17 -Wall -Werror -pedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -Imodel -Icontroller -Iview 
UNITFLAGS := -lgtest
COV_FLAG :=
OS:=$(shell uname -s)
ifeq ($(OS), Darwin)
	UNITFLAGS += $(shell pkg-config --cflags --libs check)
else
	UNITFLAGS += -lsubunit -lrt -lm -lpthread
endif

INSTALL_DIR := ./application

# Объектные файлы

OBJS := ./out/bonusPart.o ./out/expressionCalculation.o ./out/expressionParsing.o ./out/graph.o ./out/stack.o ./out/controller.o  
UNITOBJS := ./out/tests.o

.PHONY : all clean gcov_report del_obj dvi install uninstall tests check format

all : clean install

go: application/smart_calc.exe
	./application/smart_calc.exe

tests : $(OBJS) $(UNITOBJS)
	$(CC) -o tests $(UNITOBJS) $(OBJS) $(UNITFLAGS) -fprofile-arcs -ftest-coverage
	./tests

valgrind: clean tests
	valgrind --tool=memcheck --leak-check=yes --log-file=valgrind_out.txt --leak-check=full -s ./tests || echo

smart_calc.exe: $(OBJS) ./out/main.o ./out/view.o
	$(CC) -o $@  $^ -lm `pkg-config --libs gtk+-3.0`

gcov_report : COV_FLAG += --coverage 
gcov_report : del_obj tests
	lcov -t "coverage" -o coverage.info -c -d . 
	genhtml -o report coverage.info
	rm -rf ./*.gc*
	rm -rf ./*.gd*
	open ./report/index.html

del_obj :
	rm -rf ./out
	
install : smart_calc.exe
	mkdir -p $(INSTALL_DIR)
	cp $^ $(INSTALL_DIR)
	rm -rf $^

uninstall :
	rm -rf $(INSTALL_DIR)
	
s21_math.a : ./out/s21_math.o
	ar rc $@ $^
	ranlib $@
	cp $@ lib$@

./out/%.o: ./view/%.cpp ./view/%.h
	mkdir -p ./out
	$(CC) -std=c++17 `pkg-config gtk+-3.0 --cflags` -Imodel -Icontroller -Iview -c $< -o $@

./out/%.o: ./model/%.cpp ./model/%.h
	mkdir -p ./out
	$(CC) $(CFLAGS) $(COV_FLAG) -c $< -o $@

./out/%.o: ./controller/%.cpp ./controller/%.h
	mkdir -p ./out
	$(CC) $(CFLAGS) $(COV_FLAG) -c $< -o $@
	
./out/%.o: ./main.cpp
	mkdir -p ./out
	$(CC) -std=c++17 `pkg-config gtk+-3.0 --cflags` -Imodel -Icontroller -Iview -c $< -o $@
	
./out/tests.o : ./test/tests.cpp
	mkdir -p ./out
	$(CC) $(CFLAGS) -Wno-error=write-strings -Wno-write-strings -c $< $(UNITFLAGS1)
	mv ./*.o ./out/

dvi:
	open ../README.md

dist: clean
	zip -r SmartCalc_v1.0.zip *
	
format:
	clang-format -style=google -i ./*/*.cpp ./*/*.h ./*.cpp

check:
	clang-format -style=google -n ./*.cpp ./*/*.cpp ./*/*.h
	cppcheck --enable=all --suppress=missingIncludeSystem --inline-suppr \
	--language=c++ --std=c++17 ./*/*.cpp ./*/*.h ./*.cpp

clean :
	rm -f ./*.exe
	rm -rf ./out
	rm -rf ./*.a
	rm -rf ./*.gc*
	rm -rf ./*.gd*
	rm -rf ./report
	rm -rf ./*.info
	rm -rf tests
	rm -rf valgrind_out.txt

