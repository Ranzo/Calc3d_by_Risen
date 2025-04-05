# Dependencies: qt6-base-dev, doxygen

CXX = g++
# CXXFLAGS = -std=c++17 -I./model -I./include -DLOGGER_MAX_LOG_LEVEL_PRINTED=0
CPPCHECK_FLAGS = --enable=all --suppress=missingIncludeSystem --language=c++ \
				 --quiet --suppress=unusedFunction --suppress=unusedStructMember \
				 --suppress=shadowFunction --suppress=missingInclude --suppress=unknownMacro \
				 --suppress=unmatchedSuppression --suppress=missingInclude --suppress=checkersReport

BUILD_DIR = build
EXEC_NAME = Calc3D
# INSTALL_DIR = bin

#########################################
#----------- Build and run  ------------#
#########################################
all: 
	rm -rf ./build
	mkdir -p $(BUILD_DIR) && \
	cd $(BUILD_DIR) && \
	cmake ../../src && \
	make 
	# valgrind -q -s --leak-check=full --trace-children=yes --track-origins=yes  --log-file=./VALGRIND ./$(BUILD_DIR)/$(EXEC_NAME)
	./$(BUILD_DIR)/$(EXEC_NAME)

#########################################
#---------------- Checks ---------------#
#########################################
.PHONY: check
check:
	find . \( -path "./build" -o -path "./include" \) -prune -o -type f -regex '.*\.cpp' -print | xargs cppcheck $(CPPCHECK_FLAGS)
	find . \( -path "./build" -o -path "./include" \) -prune -o -type f -regex '.*\.h' -print | xargs cppcheck $(CPPCHECK_FLAGS)
	find . \( -path "./build" -o -path "./include" \) -prune -o -type f -regex '.*\.cpp' -print  -exec clang-format -style='{BasedOnStyle: Google}' -n {} \;
	find . \( -path "./build" -o -path "./include" \) -prune -o -type f -regex '.*\.h' -print  -exec clang-format -style='{BasedOnStyle: Google}' -n {} \;

.PHONY: check_fix
check_fix:
	find . \( -path "./build" -o -path "./include" \) -prune -o -type f -regex '.*\.cpp' -print | xargs cppcheck $(CPPCHECK_FLAGS)
	find . \( -path "./build" -o -path "./include" \) -prune -o -type f -regex '.*\.h' -print | xargs cppcheck $(CPPCHECK_FLAGS)
	find . \( -path "./build" -o -path "./include" \) -prune -o -type f -regex '.*\.cpp' -print  -exec clang-format -style='{BasedOnStyle: Google}' -i {} \;
	find . \( -path "./build" -o -path "./include" \) -prune -o -type f -regex '.*\.h' -print  -exec clang-format -style='{BasedOnStyle: Google}' -i {} \;

.PHONY: clean 
clean: 
	cd ../ && rm -rf $(INSTALL_DIR)