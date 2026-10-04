M ?=

ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
    CONFIG := debug
else
    CONFIG := release
endif

ifeq ($(M),)
	INC_DIR := inc
	SRC_DIR := src
	OUT_DIR := out/$(CONFIG)
else
	INC_DIR := inc/$(M)
	SRC_DIR := src/$(M)
	OUT_DIR := out/$(M)/$(CONFIG)
endif

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OUT_DIR)/%.o, $(SRCS))

TARGET ?= app

CXX := clang++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic-errors \
            -Weffc++ -Wconversion -Wsign-conversion \
            -I$(INC_DIR)
PHONY:= all clean build debug release

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "LD $(TARGET)"
	@$(CXX) $(CXXFLAGS) $^ -o $(TARGET)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OUT_DIR)
	@if [ -n "$(M)" ]; then echo "CXX[M] $(M)/$(notdir $<)"; else echo "CXX $(notdir $<)"; fi
	@$(CXX) -c $< $(CXXFLAGS) -o $@

$(OUT_DIR):
	@echo "MKDIR $(OUT_DIR)"
	@mkdir -p $(OUT_DIR)

clean:
	@echo "CLEAN"
	@rm -rf $(TARGET) $(OUT_DIR)

build: clean all

debug: CXXFLAGS += -g -O0

debug: all

release: CXXFLAGS += -O2

release: all

.PHONY: $(PHONY)