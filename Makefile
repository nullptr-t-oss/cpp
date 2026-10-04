M ?=

ifeq ($(M),)
	INC_DIR := inc
	SRC_DIR := src
	OUT_DIR := out
else
	INC_DIR := inc/$(M)
	SRC_DIR := src/$(M)
	OUT_DIR := out/$(M)
endif

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OUT_DIR)/%.o, $(SRCS))

TARGET ?= app

CXX := clang++
CXXFLAGS := -Wall -Wextra -I$(INC_DIR)
PHONY:= all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "LD $(TARGET)"
	@$(CXX) $^ -o $(TARGET)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OUT_DIR)
	@if [ -n "$(M)" ]; then echo "CXX[M] $(notdir $<)"; else echo "CXX $(notdir $<)"; fi
	@$(CXX) -c $< $(CXXFLAGS) -o $@

$(OUT_DIR):
	@echo "MKDIR $(OUT_DIR)"
	@mkdir -p $(OUT_DIR)

clean:
	@echo "CLEAN"
	@rm -rf $(TARGET) $(OUT_DIR)

.PHONY: $(PHONY)