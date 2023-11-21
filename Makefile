# ====== Configuration ======
LIB_NAME = libTestFramework.so

target = debug

CFLAGS = -Wall -Wextra -std=c++23 -fpic

ifeq ($(target), debug)
  CFLAGS += -g
  OBJ = obj/debug
else ifeq ($(target), release)
  CFLAGS += -O3 -DNDEBUG
  OBJ = obj/release
else
  $(error Wrong target)
endif

OUTPUT_DIR = $(OBJ)/output
LIB = $(OUTPUT_DIR)/$(LIB_NAME)

# ====== Setup ======
SRC_LIST = $(wildcard *.cpp)

OBJ_DIRS = $(OBJ)/tmp/
OBJ_LIST = $(addprefix $(OBJ_DIRS), $(patsubst %.cpp, %.o, $(SRC_LIST)))

LDFLAGS = 

.PHONY: all clean cleanAll

# ====== Rules ======
all: $(LIB)

clean:
	rm -rf $(OBJ)

cleanAll:
	rm -rf obj

$(LIB): $(OBJ_LIST) | $(OUTPUT_DIR)
	g++ -std=c++23 -shared -o $@ $^ $(LDFLAGS)

$(OUTPUT_DIR):
	mkdir -p $@

$(OBJ_DIRS):
	mkdir -p $@

# ====== Dependency generation ======
DEPFLAGS = -MMD -MF $(@:.o=.d)
DEP := $(patsubst %.o, %.d, $(OBJ_LIST))
-include $(DEP)

$(OBJ)/tmp/%.o: %.cpp | $(OBJ_DIRS)
	g++ $(CFLAGS) -c $< -o $@ $(DEPFLAGS)

