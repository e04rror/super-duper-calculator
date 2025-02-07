#	gcc -Wall -Werror ./src/*.c -o calc -I./include

TARGET_EXEC := calc
BUILD_DIR := build
SRC_DIR := src
INC_DIR := include

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

INC_FLAGS := $(addprefix -I,$(INC_DIR))
CPPFLAGS := $(INC_FLAGS) -MMD -MP 
CFLAGS := -Wall -Werror

$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR) 2>NULL || true
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
# for windows users
ifeq ($(OS),Windows_NT) 
	del /S /Q $(BUILD_DIR)\* 2>NUL ||rmdir /S /Q $(BUILD_DIR) 2>NUL || true
	del /Q $(TARGET_EXEC) 2>NUL || true
else
	rm -rf $(TARGET_EXEC) $(BUILD_DIR) NULL || true
endif
-include $(DEPS)
