
SRC := src
HEADERS := headers
SRC_FILES := $(wildcard $(SRC)/*.c)
BUILD_DIR := objs
BUILD_FILES := $(patsubst $(SRC)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
APP := apps
GCC := gcc
EXTRAFLAGS := -g -O0 -Wall -Wextra
RMDIR := rmdir /S /Q


define mkclean
	@if exist "$(1)" @$(RMDIR) "$(1)"
endef

.PHONY: clean linklist PRECONFIG 

$(APP)/linklist: $(BUILD_FILES) 
	$(GCC) $^ -o $@
$(BUILD_DIR)/%.o: $(SRC)/%.c | PRECONFIG
	$(GCC) -I $(HEADERS) $(EXTRAFLAGS) -c $< -o $@

PRECONFIG:
	@mkdir $(BUILD_DIR)
	@mkdir $(APP)

clean:
	$(call mkclean,$(BUILD_DIR))
	$(call mkclean,$(APP))
	