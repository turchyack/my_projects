NAME = $(notdir $(CURDIR))

PROJECT_ROOT = ..
PROJECT_DIR = .

BUILD_DIR = $(PROJECT_ROOT)/bin
BIN_DIR = $(BUILD_DIR)/$(NAME).obj
BIN_FPATH = $(BUILD_DIR)/$(NAME)

COMPILE.cpp = g++
LINK.cpp = g++

CXXFLAGS = -Wall

SRCS = $(wildcard *.cpp)
OBJS = $(addprefix $(BIN_DIR)/,$(patsubst %.cpp,%.o,$(SRCS)))
HDRS = $(wildcard *.h)

DEPS = Makefile ../common.mk $(HDRS)


all: bin

run: bin
	$(BIN_FPATH)

clean:
	-rm $(BIN_FPATH) $(OBJS)

test1:
	@echo "DEBUG: CURDIR=$(CURDIR)"
	@echo "DEBUG: PROJECT_ROOT=$(PROJECT_ROOT), PROJECT_DIR=$(PROJECT_DIR), NAME=$(NAME)"
	@echo "DEBUG: BIN_DIR=$(BIN_DIR), BIN_FPATH=$(BIN_FPATH)"
	@echo "DEBUG: SRCS: $(SRCS)"
	@echo "DEBUG: OBJS: $(OBJS)"


bin: $(BIN_FPATH)


$(BIN_FPATH): $(OBJS)
	$(LINK.cpp) -o $@ $(LDFLAGS) $^ $(LIBS)


$(BIN_DIR)/%.o: %.cpp $(DEPS)
	$(COMPILE.cpp) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) $<

$(OBJS): | $(BIN_DIR)
$(BIN_DIR): | $(BUILD_DIR)
$(BIN_FPATH): | $(dir $(BIN_FPATH))

$(BIN_DIR) $(BUILD_DIR):
	mkdir $@
