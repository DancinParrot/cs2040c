COMPILER = g++
OPTIONS = -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
COMPILE = $(COMPILER) $(OPTIONS)

BUILD_DIR = build
SRCS = $(filter-out ./template.cpp, $(wildcard ./*.cpp))
TEST_DIR = tests
TEST := $(wildcard $(TEST_DIR)/*.cpp)
#$(filter-out src/bar.cpp, $(wildcard src/*.cpp))

.PHONY: release
release: dirs
	@$(MAKE) all

.PHONY: dirs
dirs:
	@echo "Creating build directories..."
	@mkdir -p $(BUILD_DIR)

.PHONY: main
# To run: make main SRCS=/path/to/file, otherwise specify in this file
all: $(SRCS) 
	$(COMPILE) $(SRCS) -o $(BUILD_DIR)/$@

.PHONY: test
test: $(TEST)
	$(COMPILE) $(TEST) -o $(BUILD_DIR)/gen

# To run: make 2000C will build 2000C.cpp
% : %.cpp dirs
	$(COMPILE) $< -o $(BUILD_DIR)/$@

.PHONY: clean
clean:
	@echo "Deleting build directories..."
	@$(RM) -rv $(BUILD_DIR)
